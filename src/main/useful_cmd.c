/*
** useful_cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  8 17:57:30 2016 bougon_p
** Last update Sun Apr 10 13:41:42 2016 bougon_p
*/

#include "shell.h"

void	cmd_err(t_data *data, char **tab)
{
  putstr_err(data->savecmd);
  putstr_err(": Command not found.\n");
  free_tab(tab);
  exit(1);
}

int	m_execve(char *cmd, char **tab, char **env)
{
  int	ret;

  ret = -1;
  if (access(cmd, F_OK | X_OK) == 0 && check_cmd(tab[0]) == false)
    ret = execve(cmd, tab, env);
  return (ret);
}

void	wait_exit()
{
  int	status;

  wait(&status);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	my_putstr("Segmentation fault (core dumped)\n");
    }
}
