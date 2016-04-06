/*
** epur.c for epur in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 18:16:34 2016 bougon_p
** Last update Mon Apr  4 16:34:16 2016 bougon_p
*/

#include "shell.h"

char    *my_epur_str(char *str)
{
  char  *new;
  int   i;
  int   n;

  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  new = my_bzero(new, my_strlen(str) + 1);
  n = 0;
  i = 0;
  while (str[i])
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i])
        i++;
      if (i > 0 && n > 0 && (str[i - 1] == ' '
		    || str[i - 1] == '\t') && str[i])
        new[n++] = ' ';
      while ((str[i] != ' ' && str[i] != '\t') && str[i])
        new[n++] = str[i++];
    }
  if (new[n - 1] == ' ' || new[n - 1] == '\t')
    new[n - 1] = 0;
  new[n] = 0;
  free(str);
  str = new;
  return (new);
}
