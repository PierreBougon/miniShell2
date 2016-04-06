/*
** pipe.c for pipe in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Apr  5 19:02:48 2016 bougon_p
** Last update Wed Apr  6 22:28:01 2016 bougon_p
*/

#include "shell.h"

int	check_pipe_err(t_cdlist *tmp)
{
  if (my_strcmp(tmp->data->cmd[0], "|") == 0 || tmp->data->cmd_pip == NULL)
    {
      putstr_err("Invalid null command\n");
      return (1);
    }
  return (0);
}

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

int	separ_cmd(t_cdlist *tmp, int j)
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
  if (tmp->data->cmd_pip[0] == NULL)
    return (1);
  return (0);
}

bool	parse_pipes(t_cdlist *tmp)
{
  bool	pipe;
  int	j;

  j = -1;
  pipe = false;
  tmp->data->cmd_pip = NULL;
  while (tmp->data->cmd[++j] != NULL)
    {
      if (my_strcmp(tmp->data->cmd[j], "|") == 0)
	{
	  if (j == 0)
	    return (true);
	  pipe = true;
	  break ;
	}
    }
  if (pipe)
    if (separ_cmd(tmp, j) == 1)
      return (true);
  return (pipe);
}
