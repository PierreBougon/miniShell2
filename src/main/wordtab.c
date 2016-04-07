/*
** wordtab.c for wordtab in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Apr  4 16:20:26 2016 bougon_p
** Last update Thu Apr  7 14:00:50 2016 bougon_p
*/

#include "shell.h"

void	init_all_cmd(t_data *data, char *buf, int len_max)
{
  int		n_max;
  int		i;
  t_cdlist	*tmp;
  t_coms	*com;

  create_cdlist(&data->all_cmd.root);
  i = 0;
  tmp = data->all_cmd.root;
  n_max = count_cmd(buf) + 1;
  while (i < n_max)
    {
      if ((com = malloc(sizeof(t_coms) * 1)) == NULL)
	exit(1);
      if ((com->cmd = init_tab(len_max, my_strlen(buf))) == NULL)
	exit(1);
      add_last_cdl(data->all_cmd.root, com);
      tmp = tmp->next;
      i++;
    }
}

void		word_tab(t_data *data, char *buf, int n, int k)
{
  t_cdlist	*tmp;
  int		i;

  tmp = data->all_cmd.root->next;
  i = -1;
  while (buf[++i])
    {
      if (buf[i] == ';')
  	{
  	  while (n++ < data->n_max)
  	    tmp->data->cmd[n] = NULL;
  	  tmp = tmp->next;
  	  n = 0;
  	  k = 0;
  	}
      else if (buf[i] == ' ' && k > 0 && buf[i + 1] != ';')
  	{
	  n++;
  	  k = 0;
  	}
      else if (buf[i] == '|' && k > 0 && buf[i + 1] != ';')
  	{
	  n++;
  	  k = 0;
	  tmp->data->cmd[n][k++] = buf[i];
	  n++;
  	  k = 0;
  	}
      else if (buf[i] != ' ')
  	tmp->data->cmd[n][k++] = buf[i];
    }
  while (n++ < data->n_max)
    tmp->data->cmd[n] = NULL;
}

void		parse_args(char *buf, t_data *data)
{
  int		n;
  int		k;

  if ((buf = my_epur_str(buf)) == NULL)
    exit(1);
  data->n_max = count_spaces(buf) + 1;
  init_all_cmd(data, buf, data->n_max);
  n = 0;
  k = 0;
  word_tab(data, buf, n, k);
  free(buf);
}
