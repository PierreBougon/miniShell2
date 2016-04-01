/*
** builtins.c for builtins in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 23:00:39 2016 bougon_p
** Last update Fri Apr  1 14:48:36 2016 bougon_p
*/

#include "shell.h"

int	check_builtin(t_data *data, char **cmd)
{
  int	i;

  i = 0;
  while (i < NB_BUILTINS)
    {
      if (my_strcmp(data->builtins[i], cmd[0]) == 0)
	{
	  data->builtin[i](data);
	  break ;
	}
      i++;
    }
  return (0);
}
