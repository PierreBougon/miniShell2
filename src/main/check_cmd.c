/*
** check_cmd.c for CHECK in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  8 17:54:05 2016 bougon_p
** Last update Sun Apr 10 13:44:03 2016 bougon_p
*/

#include "shell.h"

bool	check_path_exist(t_data *data, char **tab, bool *full_test)
{
  int	nb_path;

  data->nb_path = 1;
  if ((nb_path = get_pos_from_env(data, "PATH")) == -1)
    {
      *tab = rewrite_cmd(*tab);
      *full_test = false;
    }
  return (true);
}

bool	check_cmd(char *cmd)
{
  int	i;
  bool	slash;

  slash = false;
  i = -1;
  while (cmd[++i])
    {
      if (cmd[i] == '/' && slash)
	return (true);
      if (cmd[i] == '/')
	slash = true;
      else
	slash = false;
    }
  return (false);
}

void	check_cmd_exist(t_data *data, char *tab, bool *full_test)
{
  if (check_path_exist(data, &tab, full_test) == false)
    exit(1);
  data->savecmd = my_strdup(tab);
}
