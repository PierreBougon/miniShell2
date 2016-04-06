/*
** pwd.c for pwd in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr  3 19:16:45 2016 bougon_p
** Last update Sun Apr  3 21:17:23 2016 bougon_p
*/

#include "shell.h"

char	*strcatnext_file(char *dest, char *src)
{
  int   i;
  int   p;

  i = -1;
  p = -1;
  while (dest[++i] != 0);
  dest[i++] = '/';
  while (src[++p] != 0 && src[p] != '/')
    dest[i++] = src[p];
  dest[i] = 0;
  return (dest);
}

void	modify_pwd(char *pwd)
{
  int   i;

  i = my_strlen(pwd);
  if ((my_strcmp(&pwd[4], "/home") == 0) ||
      (my_strcmp(&pwd[4], "/")) == 0)
    {
      my_strcpy(pwd, "PWD=/");
      return ;
    }
  while (pwd[--i] != '/')
    pwd[i] = 0;
  pwd[i] = 0;
}
