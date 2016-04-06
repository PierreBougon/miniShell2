/*
** pipe.c for pipe in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Apr  5 19:02:48 2016 bougon_p
** Last update Wed Apr  6 17:20:53 2016 bougon_p
*/

#include "shell.h"

void	count_line_col(t_cdlist *tmp, int *lines, int *cols)
{
  *lines = 0;
  *cols = 0;
  while (tmp->data->cmd[*lines])
    {
      *cols = (*cols < my_strlen(tmp->data->cmd[*lines]))
	? my_strlen(tmp->data->cmd[*lines]) : *cols;
      *lines += 1;
    }
}

void	separ_cmd(t_cdlist *tmp, int j)
{
  int	lines;
  int	cols;
  int	n;

  count_line_col(tmp, &lines, &cols);
  tmp->data->cmd_pip = init_tab(lines, cols);
  free(tmp->data->cmd[j]);
  tmp->data->cmd[j] = NULL;
  n = 0;
  while (++j < lines)
    {
      my_strcpy(tmp->data->cmd_pip[n++], tmp->data->cmd[j]);
      free(tmp->data->cmd[j]);
      tmp->data->cmd[j] = NULL;
    }
  tmp->data->cmd_pip[n] = NULL;
}

bool	parse_pipes(t_cdlist *tmp)
{
  bool	pipe;
  int	j;

  j = -1;
  pipe = false;
  while (tmp->data->cmd[++j] != NULL)
    {
      if (my_strcmp(tmp->data->cmd[j], "|") == 0)
	{
	  pipe = true;
	  break ;
	}
    }
  if (pipe)
    separ_cmd(tmp, j);
  return (pipe);
}
