/*
** shell.h for shell in /home/bougon_p/rendu/PSU_2015_minisell2/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:09:58 2016 bougon_p
** Last update Sun Apr 10 16:30:07 2016 bougon_p
*/

#ifndef	SHELL_H_
# define SHELL_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "my.h"
# include "list.h"
# include "struct.h"
# include "get_next_line.h"

/*
** DEFINES
*/

# define NB_BUILTINS 5

# define UNUSED __attribute__((__unused__))

/*
**     _____________________
**    / ____________________\
** ## |PROTOTYPING FUNCTIONS| ##
**    +---------------------+
**
*/


/*
** BUILTINS
*/

int	m_cd(t_data *);
int	m_setenv(t_data *);
int	m_unsetenv(t_data *);
int	m_env(t_data *);
int	m_exit(t_data *);
int	check_builtin(t_data *, char **);
int	init_builtins(t_data *);
char	*strcatnext_file(char *, char *);
void	modify_pwd(char *);
int	check_exit(char *);
char	*set_home(t_data *, bool *, char *);
void	go_to_home(t_data *);
char	*rework_home(char *);

/*
** MAIN
*/

int	exec_cmd(char *, t_data *);
void	putstr_err(char *);
int	count_spaces(char *);
int	count_cmd(char *);
void	parse_args(char *, t_data *);
char	*get_next_path(t_data *);
bool	parse_pipes(t_cdlist *);
int	check_pipe_err(t_cdlist *);
void	check_cmd_exist(t_data *, char *, bool *);
bool	check_cmd(char *);
bool	check_path_exist(t_data *, char **, bool *);
char	*rewrite_cmd(char *);
char	*rewrite_bin_cmd(char *);
void	cmd_err(t_data *, char **);
int	m_execve(char *, char **, char **);
void	wait_exit();
void	copy_env(char **, t_data *);
void	get_usr_name(t_data *);

/*
** FREE
*/

void	free_tab(char **);

/*
** TOOLS
*/

char	*my_epur_str(char *);
void	epur_all_cmd(t_cdlist *);
char	**init_tab(int, int);
char	*get_var_from_env(t_data *, char *);
char	*get_full_var_from_env(t_data *, char *);
int	get_pos_from_env(t_data *, char *);

/*
** ShowTab
*/
void	show_all_tab(t_cdlist *, t_data *);

#endif /* !SHELL_H_ */
