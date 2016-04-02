/*
** cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 13:59:56 2016 bougon_p
** Last update Sat Apr  2 20:31:11 2016 bougon_p
*/

#include "shell.h"

int	count_spaces(char *str)
{
  int	i;
  int	n;

  i = -1;
  n = 0;
  while (str[++i])
    {
      if (str[i] == ' ')
	n++;
    }
  return (n);
}

int	count_cmd(char *str)
{
  int	i;
  int	n;

  i = -1;
  n = 0;
  while (str[++i])
    {
      if (str[i] == ';')
	n++;
    }
  return (n);
}

void	init_all_cmd(t_data *data, char *buf, int len_max)
{
  int		n_max;
  int		i;
  t_cdlist	*tmp;
  t_cmd		*cmd;

  create_cdlist(&data->all_cmd.root);
  i = 0;
  tmp = data->all_cmd.root;
  n_max = count_cmd(buf) + 1;
  while (i < n_max)
    {
      if ((cmd = malloc(sizeof(cmd) * 1)) == NULL)
	exit(1);
      if ((cmd->cmd = init_tab(len_max, my_strlen(buf))) == NULL)
	exit(1);
      add_last_cdl(data->all_cmd.root, cmd);
      tmp = tmp->next;
      i++;
    }
}

void		parse_args(char *buf, t_data *data)
{
  int		i;
  int		n;
  int		n_max;
  int		k;
  t_cdlist	*tmp;

  if ((buf = my_epur_str(buf)) == NULL)
    exit(1);
  n_max = count_spaces(buf) + 1;
  init_all_cmd(data, buf, n_max);
  i = -1;
  n = 0;
  k = 0;
  tmp = data->all_cmd.root->next;
  while (buf[++i])
    {
      if (buf[i] == ';')
  	{
  	  while (n++ < n_max)
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
      else if (buf[i] != ' ')
  	tmp->data->cmd[n][k++] = buf[i];
      printf("%d\n", n);
    }
  while (n++ < n_max)
    tmp->data->cmd[n] = NULL;
  free(buf);
}

char	*rewrite_cmd(char *cmd)
{
  char	*new;

  if ((new = malloc(sizeof(char) * my_strlen(cmd) + 6)) == NULL)
    return (NULL);
  my_bzero(new, my_strlen(cmd) + 6);
  if (my_strncmp(cmd, "/bin/", 5) == 0)
    return (cmd);
  my_strcpy(new, "/bin/");
  my_strcat(new, cmd);
  free(cmd);
  return (new);
}

int	launch_cmd(UNUSED char *buf, t_data *data, char **tab)
{
  pid_t	cpid;
  int	status;

  tab[0] = rewrite_cmd(tab[0]);
  cpid = fork();
  if (cpid != 0)
    wait(&status);
  if (cpid == 0)
    {
      if (execve(tab[0], tab, data->env) == -1)
	{
	  putstr_err("cannot exec the following comand : ");
	  putstr_err(&tab[0][5]);
	  putstr_err("\n");
	}
      free_tab(tab);
      exit(1);
    }
  /* free_tab(tab); */
  return (cpid);
}

void		show_all_tab(t_arglist *arg)
{
  t_cdlist	*tmp;
  int		j;

  tmp = arg->root->next;
  while (tmp != arg->root)
    {
      j = -1;
      while (tmp->data->cmd[++j] != NULL)
	printf("%s\n", tmp->data->cmd[j]);
      tmp = tmp->next;
    }
}

int		exec_cmd(char *buf, t_data *data)
{
  int		ret;
  t_cdlist	*tmp;

  parse_args(buf, data);
  tmp = data->all_cmd.root->next;
  show_all_tab(&data->all_cmd);
  while (tmp != data->all_cmd.root)
    {
      tmp->data->cmd[0] = my_epur_str(tmp->data->cmd[0]);
      if ((ret = check_builtin(data, tmp->data->cmd)) == 1)
	return (-2);
      else if (ret == 2)
	launch_cmd(buf, data, tmp->data->cmd);
      tmp = tmp->next;
    }
  return (0);
}
