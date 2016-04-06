/*
** show_tab.c for showtab in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr  3 15:58:06 2016 bougon_p
** Last update Wed Apr  6 17:35:25 2016 bougon_p
*/

#include "shell.h"

void            show_all_tab(t_cdlist *tmp, t_data *data)
{
  int           j;

  dprintf(2, "=== Here cmd ===\n");
  j = -1;
  while (tmp->data->cmd[++j] != NULL)
    dprintf(2, "%s$\n", tmp->data->cmd[j]);
  if (data->pipe)
    {
      dprintf(2, "=== Here cmd piped ===\n");
      j = -1;
      while (tmp->data->cmd_pip[++j] != NULL)
	dprintf(2, "%s$\n", tmp->data->cmd_pip[j]);
    }
  dprintf(2, "\n\n=== --------------- ===\n\n");
}
