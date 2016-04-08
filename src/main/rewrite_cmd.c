/*
** rewrite_cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  8 17:55:17 2016 bougon_p
** Last update Fri Apr  8 17:55:25 2016 bougon_p
*/

#include "shell.h"

char	*rewrite_cmd(char *cmd)
{
  char	*new;

  if (my_strncmp(cmd, "/bin/", 5) == 0)
    return (cmd);
  if ((new = malloc(sizeof(char) * my_strlen(cmd) + 6)) == NULL)
    return (NULL);
  my_bzero(new, my_strlen(cmd) + 6);
  my_strcpy(new, "/bin/");
  my_strcat(new, cmd);
  free(cmd);
  return (new);
}

char	*rewrite_bin_cmd(char *cmd)
{
  char	*new;

  if (my_strncmp(cmd, "/bin/", 5) != 0)
    return (cmd);
  new = my_strdup(&cmd[5]);
  free(cmd);
  return (new);
}
