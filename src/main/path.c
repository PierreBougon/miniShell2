/*
** path.c for path in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Apr  4 17:58:03 2016 bougon_p
** Last update Tue Apr 12 11:52:43 2016 bougon_p
*/

#include "shell.h"

int	max_path(char *path)
{
  int	i;
  int	n;

  i = -1;
  n = 1;
  while (path[++i] != 0)
    {
      if (path[i] == ':')
	n++;
    }
  return (n);
}

int		copy_next_path(char *cmd, char *path, int num_path)
{
  int		count_separ;
  int		n;
  int		i;

  i = -1;
  count_separ = 1;
  if (num_path > max_path(path))
    return (1);
  while (count_separ < num_path && path[++i])
    {
      if (path[i] == ':')
	count_separ++;
      if (count_separ >= num_path)
	break ;
    }
  n = 0;
  while (path[++i] && path[i] != ':')
    {
      cmd[n++] = path[i];
    }
  cmd[n] = '/';
  cmd[n + 1] = 0;
  return (0);
}

char		*get_next_path(t_data *data)
{
  char		*path;
  char		*new;

  path = get_var_from_env(data, "PATH");;
  if ((new = malloc(sizeof(char) *
		    my_strlen(data->savecmd) + my_strlen(path) + 2)) == NULL)
    exit(1);
  my_bzero(new, my_strlen(data->savecmd) + my_strlen(path));
  if (copy_next_path(new, path, data->nb_path) == 1)
    return (NULL);
  my_strcat(new, data->savecmd);
  data->nb_path++;
  return (new);
}
