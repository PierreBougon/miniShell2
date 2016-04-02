/*
** main.c for SHELL in /home/bougon_p/rendu/PSU_2015_minisell2/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:12:24 2016 bougon_p
** Last update Sun Apr  3 01:13:26 2016 bougon_p
*/

#include "shell.h"

int	start_shell(t_data *data)
{
  char	*buf;
  int	ret;

  while (1)
    {
      my_putstr(data->user);
      if ((buf = get_next_line(0)) == NULL)
	return (0);
      if ((ret = exec_cmd(buf, data)) == 1 || ret == -1 || ret == -2)
	return (0);
    }
  return (0);
}

void	get_usr_name(t_data *data)
{
  char	*tmp;

  if ((tmp = get_var_from_env(data, "USER")) == NULL)
    data->user = "$>";
  if ((data->user = malloc(sizeof(char) * (my_strlen(tmp) + 3))) == NULL)
    exit(1);
  my_bzero(data->user, my_strlen(tmp) + 3);
  my_strcpy(data->user, tmp);
  data->user[my_strlen(tmp) + 2] = 0;
  my_strcat(data->user, "$ ");
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
  get_usr_name(data);
  data->pwd = my_strdup(get_full_var_from_env(data, "PWD"));
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_data	data;

  signal(SIGINT, SIG_IGN);
  init_builtins(&data);
  copy_env(env, &data);
  start_shell(&data);
  free(data.builtin);
  free_tab(data.builtins);
  free_tab(data.env);
  free(data.pwd);
  free(data.user);
  return (0);
}
