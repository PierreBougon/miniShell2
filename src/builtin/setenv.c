/*
** setenv.c for setenv in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 22:49:53 2016 bougon_p
** Last update Mon Apr  4 16:17:36 2016 bougon_p
*/

#include "shell.h"

void	create_var(t_data *data)
{
  int	j;

  j = -1;
  if (data->cmd[2] == NULL)
    {
      putstr_err("Variable value is not specified\n");
      return ;
    }
  while (data->env[++j] != NULL);
  data->env = my_realloc_tab(data->env, 1);
  if ((data->env[j] = malloc(sizeof(char)
  			     * (my_strlen(data->cmd[1]) +
  				my_strlen(data->cmd[2]) + 2))) == NULL)
    exit(1);
  my_strcpy(data->env[j], data->cmd[1]);
  my_strcpy(&data->env[j][my_strlen(data->env[j])], "=");
  my_strcpy(&data->env[j][my_strlen(data->env[j])], data->cmd[2]);
}

void	modify_var(t_data *data)
{
  int	j;

  j = get_pos_from_env(data, data->cmd[1]);
  if (j == -1)
    return (create_var(data));
  if (data->cmd[2] == NULL)
    {
      if ((data->cmd[2] = malloc(sizeof(char) * 1)) == NULL)
	exit(1);
      data->cmd[2][0] = 0;
      my_strcpy(&data->env[j][my_strlen(data->cmd[1]) + 1], data->cmd[2]);
      free(data->cmd[2]);
      data->cmd[2] = NULL;
      return ;
    }
  data->env[j] = my_realloc(data->env[j], my_strlen(data->cmd[2]) + 1);
  my_strcpy(&data->env[j][my_strlen(data->cmd[1]) + 1], data->cmd[2]);
}

int	m_setenv(t_data *data)
{
  if (data->cmd[1] == NULL)
    {
      m_env(data);
      return (0);
    }
  modify_var(data);
  return (0);
}
