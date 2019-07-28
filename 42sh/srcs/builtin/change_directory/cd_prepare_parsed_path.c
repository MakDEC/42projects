/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_prepare_parsed_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:55:44 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:05:34 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "libft.h"

static char		**malloc_rslt(char **temp, char **temp2)
{
	int			index;
	size_t		nb_of_elements;
	char		**rslt;

	index = -1;
	nb_of_elements = 0;
	while (temp[++index] != NULL)
		nb_of_elements++;
	index = -1;
	while (temp2[++index] != NULL)
		nb_of_elements++;
	if (!(rslt = (char **)malloc(sizeof(char *) * (nb_of_elements + 1))))
		exit(-1);
	return (rslt);
}

static char		**prepare_path_from_getcwd(void)
{
	char		**temp;
	char		*ret_getcwd;

	ret_getcwd = getcwd(NULL, 0);
	temp = ft_strsplit(ret_getcwd, '/');
	free(ret_getcwd);
	return (temp);
}

char			**prepare_parsed_path(
						t_data *data,
						t_cd_variables *cd_vars,
						t_params_list *params_list)
{
	char		**rslt;
	char		**temp;
	char		**temp2;
	int			index;
	int			rslt_index;

	if (cd_vars->mode == 0)
		temp = ft_strsplit(data->pwd, '/');
	else
		temp = prepare_path_from_getcwd();
	if (temp == NULL)
		return (NULL);
	temp2 = ft_strsplit(params_list->params[cd_vars->directory_position], '/');
	index = 0;
	rslt_index = 0;
	rslt = malloc_rslt(temp, temp2);
	while (temp[index] != NULL)
		rslt[rslt_index++] = temp[index++];
	index = 0;
	while (temp2[index] != NULL)
		rslt[rslt_index++] = temp2[index++];
	rslt[rslt_index] = NULL;
	free(temp);
	free(temp2);
	return (rslt);
}
