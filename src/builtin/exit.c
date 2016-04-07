/*
** exit.c for exit in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:50:49 2016 bougon_p
** Last update Thu Apr  7 20:33:48 2016 bougon_p
*/

#include "shell.h"

int	m_exit(UNUSED t_data *data)
{
  /* free_list(&data->all_cmd); */
  if (data->cmd[1] != NULL && is_num(data->cmd[1]) == false)
    {
      putstr_err("exit: Expression Syntax.\n");
      return (0);
    }
  if (data->cmd[1] == NULL)
    {
      my_realloc_tab(data->cmd, 1);
      data->cmd[1] = my_strdup("0");
    }
  return (1);
}
