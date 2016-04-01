/*
** shell.h for shell in /home/bougon_p/rendu/PSU_2015_minisell2/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:09:58 2016 bougon_p
** Last update Fri Apr  1 16:42:30 2016 bougon_p
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
# include "struct.h"
# include "get_next_line.h"

/*
** DEFINES
*/

# define PROMPT "$> "
# define PROMPT_SIZE 3
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

/*
** MAIN
*/

int	exec_cmd(char *, t_data *);
void	putstr_err(char *);

/*
** BUILTIN
*/

int	check_exit(char *);

/*
** FREE
*/

void	free_tab(char **);

/*
** TOOLS
*/

char	*my_epur_str(char *);
char	**init_tab(int, int);
char	*get_var_from_env(t_data *, char *);

#endif /* !SHELL_H_ */
