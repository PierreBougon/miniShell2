/*
** my_strdup.c for strdup in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:33:47 2016 bougon_p
** Last update Mon Mar 28 12:33:59 2016 bougon_p
*/

#include "my.h"

char    *my_strdup(char *src)
{
  int   i;
  char  *dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
