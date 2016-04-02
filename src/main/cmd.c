/*
** cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 13:59:56 2016 bougon_p
** Last update Sat Apr  2 02:02:01 2016 bougon_p
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

char	**parse_args(char *buf)
{
  int	i;
  int	n;
  int	n_max;
  int	k;
  char	**tab;

  if ((buf = my_epur_str(buf)) == NULL)
    return (NULL);
  n_max = count_spaces(buf) + 1;
  i = -1;
  n = 0;
  k = 0;
  if ((tab = init_tab(n_max, my_strlen(buf))) == NULL)
    return (NULL);
  while (buf[++i])
    {
      if (buf[i] == ' ')
	{
	  n++;
	  k = 0;
	}
      else
	tab[n][k++] = buf[i];
    }
  while (n++ < n_max)
    tab[n] = NULL;
  free(buf);
  return (tab);
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
  free_tab(tab);
  return (cpid);
}

int	exec_cmd(char *buf, t_data *data)
{
  char	**tab;
  int	ret;

  tab = parse_args(buf);
  data->cmd = tab;
  if ((ret = check_builtin(data, tab)) == 1)
    return (-2);
  else if (ret == 2)
    launch_cmd(buf, data, tab);
  return (0);
}
