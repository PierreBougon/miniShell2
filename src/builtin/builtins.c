/*
** builtins.c for builtins in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 23:00:39 2016 bougon_p
** Last update Sat Apr  2 01:58:32 2016 bougon_p
*/

#include "shell.h"

int	check_builtin(t_data *data, char **cmd)
{
  int	i;
  int	ret;

  i = 0;
  while (i < NB_BUILTINS)
    {
      if (my_strcmp(data->builtins[i], cmd[0]) == 0)
	{
	  ret = data->builtin[i](data);
	  return (free_tab(cmd), ret);
	}
i++;
    }
  return (2);
}
