/*
** unsetenv.c for unsetenv in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 22:50:32 2016 bougon_p
** Last update Sat Apr  2 17:47:16 2016 bougon_p
*/

#include "shell.h"

char	**realloc_inv(char **tab, int to_kill)
{
  char	**new_tab;
  int	act_lines;
  int	j;

  act_lines = -1;
  while (tab[++act_lines] != NULL);
  if ((new_tab = malloc(sizeof(char *)
			* (act_lines))) == NULL)
    return (NULL);
  new_tab[act_lines - 1] = NULL;
  j = -1;
  while (++j < act_lines)
    if (j != to_kill)
      new_tab[j] = tab[j];
  free(tab);
  return (new_tab);
}

void	find_and_kill_var(t_data *data)
{
  int	j;

  j = get_pos_from_env(data, data->cmd[1]);
  if (j == -1)
    return ;
  data->env = realloc_inv(data->env, j);
}

int	m_unsetenv(t_data *data)
{
  if (data->cmd[1] == NULL)
    {
      putstr_err("Too few arguments for : ");
      putstr_err(data->cmd[0]);
      putstr_err("\n");
      return (0);
    }
  find_and_kill_var(data);
  return (0);
}
