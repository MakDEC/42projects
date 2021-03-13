# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 15:49:57 by aanger            #+#    #+#              #
#    Updated: 2019/07/15 04:03:53 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

FILE = srcs/shell.c

BUILTIN_FILES =	srcs/builtin/builtin.c\
				srcs/builtin/echo_builtin.c\
				srcs/builtin/exit_builtin.c\
				srcs/builtin/change_directory/change_env_variables.c\
				srcs/builtin/change_directory/cd_prepare_parsed_path.c\
				srcs/builtin/change_directory/cd_prepare_path.c\
				srcs/builtin/change_directory/cd_reforged.c\
				srcs/builtin/change_directory/cd_wrong_option.c\
				srcs/builtin/change_directory/check_cd_parameters.c\
				srcs/builtin/change_directory/fill_directory_to_reach.c\
       			srcs/builtin/env/check_env.c\
				srcs/builtin/env/check_env_params.c\
				srcs/builtin/env/convert_list.c\
				srcs/builtin/env/env_builtin.c\
				srcs/builtin/env/export_env_to_list.c\
				srcs/builtin/env/prepare_new_env.c\
				srcs/builtin/env/print_env.c\
				srcs/builtin/env/send_to_right_env_function.c\
				srcs/builtin/env/setenv.c\
				srcs/builtin/env/unsetenv_builtin.c\
				srcs/builtin/fg/fg_builtin.c\
				srcs/builtin/jobs/jobs.c\
				srcs/builtin/local_variables/add_local_variable.c\
				srcs/builtin/local_variables/existing_var.c

DATATOOLS_FILES = 	srcs/datatools/cleaning_functions/current_case_cleaning.c\
		srcs/datatools/cleaning_functions/clear_local_variables.c\
		srcs/datatools/cleaning_functions/clear_redirections.c\
		srcs/datatools/cleaning_functions/free_data.c\
		srcs/datatools/initialization_functions/termcaps_tools.c\
		srcs/datatools/initialization_functions/parsing_functions_tab_initialization.c\
		srcs/datatools/initialization_functions/terminal_configuration_management.c\
		srcs/datatools/initialization_functions/export_and_adapt_env.c\
		srcs/datatools/initialization_functions/termcaps_initialization.c\
		srcs/datatools/initialization_functions/data_struct_initialization.c\
		srcs/datatools/initialization_functions/set_data_values.c\
		srcs/datatools/hash_tab/create_hash_tab.c\
		srcs/datatools/hash_tab/free_hash_tab.c\
		srcs/datatools/hash_tab/search_in_hash_tab.c\
		srcs/datatools/hash_tab/multi_path.c\
		srcs/datatools/hash_tab/fill_comp_struct_from_hash_tab.c

LINE_EDITION_FILES =	 srcs/input/bell.c\
			 srcs/input/analyse_input_buf.c\
			 srcs/input/paste_clipboard.c\
			 srcs/input/intern_select/select_part_of_input.c\
			 srcs/input/intern_select/moves_left_arrow.c\
			 srcs/input/intern_select/moves_right_arrow.c\
			 srcs/input/intern_select/intern_select_data_management.c\
			 srcs/input/intern_select/specific_writes.c\
			 srcs/input/print_input.c\
			 srcs/input/read_loop.c\
			 srcs/input/input_datatools/history.c\
			 srcs/input/input_datatools/reader_data.c\
			 srcs/input/input_datatools/screensize.c\
			 srcs/input/completion/completion.c\
			 srcs/input/completion/completion_data_management.c\
			 srcs/input/completion/path_completion.c\
			 srcs/input/completion/completion_concat_result.c\
			 srcs/input/deletions/backspace.c\
			 srcs/input/movements/arrow.c\
			 srcs/input/movements/cursor_management.c\
			 srcs/input/movements/down_arrow.c\
			 srcs/input/movements/move_by_word.c\
			 srcs/input/movements/move_line_up.c\
			 srcs/input/movements/right_arrow.c\
			 srcs/input/movements/up_arrow.c\
			 srcs/input/insertions/insert_char.c\
			 srcs/input/insertions/new_line.c\
			 srcs/input/movements/alt_arrow.c\
			 srcs/input/insertions/space.c

MONITOR_FILES = 	srcs/monitor/monitor.c\
			srcs/monitor/execution_tools/and_logical_monitor.c\
			srcs/monitor/execution_tools/check_command_validity.c\
			srcs/monitor/execution_tools/load_children_shell_level.c\
			srcs/monitor/execution_tools/or_logical_monitor.c\
			srcs/monitor/execution_tools/prepare_verify_and_exec_pipeline.c\
			srcs/monitor/execution_tools/subshell_execution.c\
			srcs/monitor/generic_display/ft_prompt.c\
			srcs/monitor/generic_display/ft_invalid_com.c\
			srcs/monitor/job_control_tools/add_job_to_list.c\
			srcs/monitor/job_control_tools/completed_jobs_verification.c\
			srcs/monitor/job_control_tools/display_job_number_and_pid.c\
			srcs/monitor/job_control_tools/display_job_status.c\
			srcs/monitor/job_control_tools/export_command_buf.c\
			srcs/monitor/job_control_tools/finish_job_and_free_memory.c\
			srcs/monitor/job_control_tools/job_loader.c\
			srcs/monitor/job_control_tools/kill_zombies_process.c\
			srcs/monitor/job_control_tools/load_job_control_informations_in_data.c\
			srcs/monitor/job_control_tools/new_background_current_job.c\
			srcs/monitor/pipeline_tools/intermediate_command.c\
			srcs/monitor/pipeline_tools/first_command.c\
			srcs/monitor/pipeline_tools/last_command.c\
			srcs/monitor/pipeline_tools/pipeline_execution.c\
			srcs/monitor/redirection_tools/apply_redirections.c\
			srcs/monitor/redirection_tools/prepare_redirections.c\
			srcs/monitor/redirection_tools/prepare_output_redirections.c\
			srcs/monitor/redirection_tools/prepare_input_redirections.c\
			srcs/monitor/simple_command/background_simple_command.c\
			srcs/monitor/simple_command/foreground_simple_command.c\
			srcs/monitor/simple_command/fork_for_simple_command.c\
			srcs/monitor/simple_command/set_and_exec_simple_command.c\
			srcs/monitor/simple_command/simple_command.c\
			srcs/monitor/term_and_sig_tools/command_term_and_sig_configuration.c\
			srcs/monitor/term_and_sig_tools/empty_handler.c\
			srcs/monitor/term_and_sig_tools/shell_term_and_sig_configuration.c\
			srcs/monitor/term_and_sig_tools/sig_interrupt.c\
			srcs/monitor/term_and_sig_tools/sigchld.c\
			srcs/monitor/term_and_sig_tools/signal_stopped_child_management.c\
			srcs/monitor/term_and_sig_tools/signals.c

PARSING_FILES = 	srcs/parser/parser.c\
			srcs/parser/input_redirections/left_rafter.c\
			srcs/parser/input_redirections/set_heredoc.c\
			srcs/parser/input_redirections/sigint_management.c\
			srcs/parser/input_redirections/set_input_redirection_case.c\
			srcs/parser/output_redirections/right_rafter.c\
			srcs/parser/output_redirections/set_redirected_fd.c\
			srcs/parser/output_redirections/absoluth_path_redirection.c\
			srcs/parser/parser_datatools/parsing_structure_management.c\
			srcs/parser/parser_datatools/params_to_data.c\
			srcs/parser/parser_datatools/vars_tools.c\
			srcs/parser/parser_datatools/create_redirection_case.c\
			srcs/parser/parser_datatools/create_pipe_line_cases.c\
			srcs/parser/special_chars/backslash_parsing.c\
			srcs/parser/special_chars/check_from_env_variables.c\
			srcs/parser/special_chars/dollar_parsing.c\
			srcs/parser/special_chars/dquote.c\
			srcs/parser/special_chars/esp_parsing.c\
			srcs/parser/special_chars/pipe_parsing.c\
			srcs/parser/special_chars/semi_colon_parsing.c\
			srcs/parser/special_chars/space_parsing.c\
			srcs/parser/special_chars/squote.c\
			srcs/parser/special_chars/tild_parsing.c

FLAGS = -Wall -Werror -Wextra			\
	-g -fsanitize=address			\
	-fno-omit-frame-pointer			\
	-fsanitize-address-use-after-scope	\
#	-fsanitize=leak

LIBFT = libft/libft.a

CC = gcc

OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))
BUILTIN_OBJS = $(patsubst srcs/%.c,objs/%.o,$(BUILTIN_FILES))
DATATOOLS_OBJS = $(patsubst srcs/%.c,objs/%.o,$(DATATOOLS_FILES))
LINE_EDITION_OBJS = $(patsubst srcs/%.c,objs/%.o,$(LINE_EDITION_FILES))
MONITOR_OBJS = $(patsubst srcs/%.c,objs/%.o,$(MONITOR_FILES))
PARSING_OBJS = $(patsubst srcs/%.c,objs/%.o,$(PARSING_FILES))

objects = $(OBJ) $(BUILTIN_OBJS) $(DATATOOLS_OBJS) $(LINE_EDITION_OBJS) $(MONITOR_OBJS) $(PARSING_OBJS)

objs/%.o: srcs/%.c
	@$(CC) -c $< $(FLAGS) -o $@ -I includes
	@printf '\033[34;01m%s\n\033[0m' 'Transformorming $< into object'

objs/builtin/%.o: srcs/builtin/%.c
	@$(CC) -c $< $(FLAGS) -o $@ -I includes
	@printf '\033[34;01m%s\n\033[0m' 'Transformorming $< into object'

objs/builtin/change_directory/%.o: $(CD_H) srcs/builtin/change_directory/%.c
	@$(CC) -c $< $(FLAGS) -o $@ -I includes
	@printf '\033[34;01m%s\n\033[0m' 'Transformorming $< into object'

all: libft_comp create_directories $(NAME)

$(NAME): $(objects) $(LIBFT)
	@$(CC) -o $(NAME) $(FLAGS) $(objects) -ltermcap $(LIBFT)
	@printf '\033[34;01m\033[1m%s\n\033[0m' 'Objects successfull linked : $(NAME) available'

$(CD_H): includes/cd.h $(DATA_STRUCT_H) includes/libft.h includes/env.h

$(DATATOOLS_OBJS): $(DATA_STRUCT_H)

$(LINE_EDITION_OBJS): $(DATA_STRUCT_H)

$(MONITOR_OBJS): $(DATA_STRUCT_H) includes/monitor.h

$(PARSING_OBJS): $(DATA_STRUCT_H) includes/parse_buffer.h

$(DATA_STRUCT_H): includes/data_struct.h includes/pipe_lines_struct.h includes/parsing_struct.h

create_directories :
	@mkdir -p objs/builtin/change_directory && mkdir objs/builtin/env && mkdir objs/builtin/fg \
		&& mkdir objs/builtin/jobs && mkdir objs/builtin/local_variables
	@mkdir -p objs/datatools/cleaning_functions && mkdir objs/datatools/hash_tab \
		&& mkdir objs/datatools/initialization_functions && mkdir objs/datatools/sig_management
	@mkdir -p objs/input/completion && mkdir objs/input/deletions && mkdir objs/input/input_datatools \
		&& mkdir objs/input/insertions && mkdir objs/input/intern_select && mkdir objs/input/movements
	@mkdir -p objs/monitor/execution_tools && mkdir objs/monitor/generic_display && mkdir objs/monitor/job_control_tools \
		&& mkdir objs/monitor/pipeline_tools && mkdir objs/monitor/redirection_tools && mkdir objs/monitor/simple_command \
		&& mkdir objs/monitor/term_and_sig_tools
	@mkdir -p objs/parser/input_redirections && mkdir objs/parser/output_redirections && mkdir objs/parser/parser_datatools \
		&& mkdir objs/parser/special_chars


libft_comp :
	@printf '\033[33;01m'
	@make -C libft/ -w
	@printf '\033[0m'

clean:
	@make clean -C libft/
	@rm -rf objs
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of objects (binary files)'

fclean: clean
	@rm -rf $(NAME).dSYM
	@rm -rf libft/libft.a
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of libft.a'
	@rm -rf $(NAME)
	@printf '\033[31;01m%s\n\033[0m' 'Deletion of $(NAME)'

re: fclean all

.PHONY: all clean fclean re
