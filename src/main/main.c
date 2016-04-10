/*
** main.c for SHELL in /home/bougon_p/rendu/PSU_2015_minisell2/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:12:24 2016 bougon_p
** Last update Sun Apr 10 14:30:55 2016 bougon_p
*/

#include "shell.h"

void	get_usr_name(t_data *data)
{
  char	*tmp;

  if (data->user != NULL)
    free(data->user);
  if ((tmp = get_var_from_env(data, "USER")) == NULL)
    {
      data->user = my_strdup("$> ");
      return ;
    }
  data->user = my_strdup(tmp);
  data->user = my_realloc(data->user, 3);
  data->user[my_strlen(tmp) + 2] = 0;
  my_strcat(data->user, "$ ");
}

int	start_shell(t_data *data)
{
  char	*buf;
  int	ret;

  while (1)
    {
      get_usr_name(data);
      my_putstr(data->user);
      if ((buf = get_next_line(0)) == NULL)
      	return (0);
      if (buf[0] == 0)
	free(buf);
      else if ((ret = exec_cmd(buf, data)) == 1 || ret == -1)
	return (0);
      else if (ret == -2)
	return (-2);
    }
  return (0);
}

void	free_all(t_data *data)
{
  free(data->builtin);
  free_tab(data->builtins);
  free_tab(data->env);
  free(data->pwd);
  free(data->user);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_data	data;

  data.user = NULL;
  data.old_pwd = NULL;
  signal(SIGINT, SIG_IGN);
  init_builtins(&data);
  copy_env(env, &data);
  if (start_shell(&data) == -2)
    {
      free_all(&data);
      return (my_getnbr(data.cmd[1]));
    }
  free_all(&data);
  return (0);
}
