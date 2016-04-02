/*
** initlist.c for LIST in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr  2 18:09:38 2016 bougon_p
** Last update Sun Apr  3 01:04:09 2016 bougon_p
*/

#include "shell.h"

int		create_cdlist(t_cdlist **root)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  *root = elem;
  elem->prev = *root;
  elem->next = *root;
  return (0);
}

int		add_last_cdl(t_cdlist *root, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (root != NULL)
    {
      elem->prev = root->prev;
      elem->next = root;
      root->prev->next = elem;
      root->prev = elem;
    }
  elem->data = _data;
  return (0);
}

int		free_list(t_arglist *arg)
{
  t_cdlist	*tmp;
  t_cdlist	*tmp2;

  tmp = arg->root->next;
  while (tmp != arg->root)
    {
      tmp2 = tmp->next;
      free_tab(tmp->data->cmd);
      free(tmp->data);
      free(tmp);
      tmp = tmp2;
    }
  free(arg->root);
  return (0);
}
