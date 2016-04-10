/*
** env.c for env in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 10 14:24:16 2016 bougon_p
** Last update Sun Apr 10 14:27:53 2016 bougon_p
*/

#include "shell.h"

void	create_env(t_data *data)
{
  char	pwd[4096];

  if ((data->env = malloc(sizeof(char *) * (2))) == NULL)
    return ;
  data->env[1] = NULL;
  data->env[0] = my_strdup("PWD=");
  getcwd(&pwd[0], 4096);
  data->env[0] = my_realloc(data->env[0], 5 + my_strlen(pwd));
  my_strcat(data->env[0], &pwd[0]);
  get_usr_name(data);
  data->pwd = my_strdup(get_full_var_from_env(data, "PWD"));
  if ((data->path = malloc(sizeof(char) * 1)) == NULL)
    exit(1);
  data->path[0] = 0;
  return ;
}

void	copy_env(char **env, t_data *data)
{
  int	i;
  int	j;

  if (*env == NULL)
    return (create_env(data));
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
  data->path = my_strdup(get_var_from_env(data, "PATH"));
}
