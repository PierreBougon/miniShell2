/*
** cd_home.c for home in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 10 16:25:02 2016 bougon_p
** Last update Sun Apr 10 16:27:14 2016 bougon_p
*/

#include "shell.h"

void	go_to_home(t_data *data)
{
  int	j;
  char	*home;

  j = get_pos_from_env(data, "PWD");
  free(data->env[j]);
  home = get_full_var_from_env(data, "HOME");
  data->env[j] = rework_home(home);
  free(data->pwd);
  data->pwd = my_strdup(data->env[j]);
  return ;
}

char	*rework_home(char *home)
{
  int	i;
  char	*tmp;

  tmp = my_strdup(home);
  tmp[0] = 'P';
  tmp[1] = 'W';
  tmp[2] = 'D';
  tmp[3] = '=';
  i = 4;
  while (tmp[++i])
    {
      tmp[i - 1] = home[i];
    }
  tmp[i - 1] = 0;
  return (tmp);
}

char	*set_home(t_data *data, bool *go_home, char *pwd_asked)
{
  if (pwd_asked == NULL)
    {
      pwd_asked = get_var_from_env(data, "HOME");
      *go_home = true;
    }
  return (pwd_asked);
}
