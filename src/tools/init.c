/*
** init.c for init in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 18:17:18 2016 bougon_p
** Last update Tue Apr  5 19:37:07 2016 bougon_p
*/

#include "shell.h"

char    **init_tab(int line, int col)
{
  char  **tab_to_malloc;
  int   i;

  i = 0;
  if ((tab_to_malloc = malloc(sizeof(char *) * (line + 1))) == NULL)
    exit(1);
  tab_to_malloc[line] = NULL;
  while (i < line)
    {
      if ((tab_to_malloc[i] = malloc(sizeof(char) * (col + 1))) == NULL)
        exit(1);
      tab_to_malloc[i] = my_bzero(tab_to_malloc[i], col + 1);
      i++;
    }
  return (tab_to_malloc);
}

int	init_builtins(t_data *data)
{
  if ((data->builtin = malloc(sizeof(data->builtin) * 5)) == NULL)
    return (1);
  data->builtin[0] = &m_cd;
  data->builtin[1] = &m_setenv;
  data->builtin[2] = &m_unsetenv;
  data->builtin[3] = &m_env;
  data->builtin[4] = &m_exit;
  if ((data->builtins = malloc(sizeof(char *) * 6)) == NULL)
    return (1);
  data->builtins[5] = NULL;
  if ((data->builtins[0] = my_strdup("cd")) == NULL ||
      (data->builtins[1] = my_strdup("setenv")) == NULL ||
      (data->builtins[2] = my_strdup("unsetenv")) == NULL ||
      (data->builtins[3] = my_strdup("env")) == NULL ||
      (data->builtins[4] = my_strdup("exit")) == NULL)
    return (1);
  return (0);
}
