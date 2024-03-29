/*
** get_var.c for getvar in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  1 16:37:14 2016 bougon_p
** Last update Thu Apr  7 19:56:02 2016 bougon_p
*/

#include "shell.h"

char	*get_full_var_from_env(t_data *data, char *to_find)
{
  int	size;
  int	j;

  if (data->env == NULL)
    return (NULL);
  size = my_strlen(to_find);
  j = -1;
  while (data->env[++j] != NULL)
    {
      if (my_strncmp(data->env[j], to_find, size) == 0)
	return (&data->env[j][0]);
    }
  return (NULL);
}

char	*get_var_from_env(t_data *data, char *to_find)
{
  int	size;
  int	j;

  if (data->env == NULL)
    return (NULL);
  size = my_strlen(to_find);
  j = -1;
  while (data->env[++j] != NULL)
    {
      if (my_strncmp(data->env[j], to_find, size) == 0)
	return (&data->env[j][size + 1]);
    }
  return (NULL);
}

int	get_pos_from_env(t_data *data, char *to_find)
{
  int	size;
  int	j;

  if (data->env == NULL)
    return (-1);
  size = my_strlen(to_find);
  j = -1;
  while (data->env[++j] != NULL)
    {
      if (my_strncmp(data->env[j], to_find, size) == 0)
	return (j);
    }
  return (-1);
}
