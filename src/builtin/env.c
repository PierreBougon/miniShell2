/*
** env.c for env in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 22:54:08 2016 bougon_p
** Last update Fri Apr  1 18:16:17 2016 bougon_p
*/

#include "shell.h"

int	m_env(t_data *data)
{
  int	j;

  j = -1;
  while (data->env[++j] != NULL)
    {
      my_putstr(data->env[j]);
      my_putstr("\n");
    }
  return (0);
}
