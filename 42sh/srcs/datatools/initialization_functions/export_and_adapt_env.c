/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_and_adapt_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:02:30 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:03:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "env.h"

static void		env_management(t_data *data, char **newenv, int i)
{
	if (ft_strncmp(data->env[i], "SHELL", 5) == 0)
		newenv[i] = ft_strdup("SHELL=42sh");
	else
		newenv[i] = ft_strdup(data->env[i]);
	if (ft_strncmp(data->env[i], "HOME", 4) == 0)
		data->home = ft_strdup(&data->env[i][5]);
	if (ft_strncmp(data->env[i], "PWD", 3) == 0)
		data->pwd = ft_strdup(&data->env[i][4]);
	if (ft_strncmp(data->env[i], "OLDPWD", 6) == 0)
		data->oldpwd = ft_strdup(&data->env[i][7]);
}

static void		prepare_children_shell_level(t_data *data, char **env, int i)
{
	size_t		size_to_malloc;
	char		**temp;
	int			shlvl;

	temp = ft_strsplit(env[i], '=');
	if (temp[1] == NULL)
		shlvl = 0;
	else
	{
		shlvl = ft_atoi(temp[1]);
		shlvl++;
	}
	free(temp[1]);
	temp[1] = ft_itoa(shlvl);
	size_to_malloc = ft_strlen(temp[0]) + ft_strlen(temp[1]) + 2;
	data->children_shell_level = ft_strnew(size_to_malloc);
	ft_strcat(data->children_shell_level, temp[0]);
	free(temp[0]);
	ft_strcat(data->children_shell_level, "=");
	ft_strcat(data->children_shell_level, temp[1]);
	free(temp[1]);
	free(temp);
}

static void		create_shell_level(t_data *data, char **env, int i)
{
	char		*shell_level;

	shell_level = ft_strnew(8);
	ft_strcat(shell_level, "SHLVL=0");
	env[i] = shell_level;
	env[i + 1] = NULL;
	data->children_shell_level = ft_strnew(8);
	ft_strcat(data->children_shell_level, "SHLVL=1");
}

static void		set_shell_level(t_data *data, char **env)
{
	int			i;

	i = check_env(env, "SHLVL");
	if (env[i] != NULL)
		prepare_children_shell_level(data, env, i);
	else
		create_shell_level(data, env, i);
}

void			export_and_adapt_env(t_data *data, char **env)
{
	char		**newenv;
	int			i;

	i = 0;
	data->env = env;
	while (data->env[i] != NULL)
		i++;
	if (data->env[check_env(data->env, "SHLVL")] == NULL)
		i++;
	if (!(newenv = (char**)malloc(sizeof(char*) * (i + 1))))
		exit(-1);
	i = -1;
	while (data->env[++i] != NULL)
		env_management(data, newenv, i);
	newenv[i] = NULL;
	set_shell_level(data, newenv);
	data->env = newenv;
}
