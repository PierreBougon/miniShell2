/*
** main.c for SHELL in /home/bougon_p/rendu/PSU_2015_minisell2/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:12:24 2016 bougon_p
** Last update Fri Apr  1 14:46:49 2016 bougon_p
*/

#include "shell.h"

int	start_shell(t_data *data)
{
  char	*buf;
  int	ret;

  while (1)
    {
      my_putstr(PROMPT);
      if ((buf = get_next_line(0)) == NULL)
	return (0);
      if ((ret = exec_cmd(buf, data)) == 1 || ret == -1 || ret == -2)
	return (0);
    }
  return (0);
}

void	copy_env(char **env, t_data *data)
{
  int	i;
  int	j;

  j = 0;
  i = 1;
  while (env[j] != NULL)
    j++;
  if ((data->env = malloc(sizeof(char *) * (j + 1))) == NULL)
    return ;
  data->env[j] = NULL;
  i = -1;
  while (env[++i] != NULL)
    data->env[i] = my_strdup(env[i]);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_data	data;

  /* signal(SIGINT, SIG_IGN); */
  init_builtins(&data);
  copy_env(env, &data);
  start_shell(&data);
  return (0);
}
