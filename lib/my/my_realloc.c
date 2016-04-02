/*
** my_realloc.c for realloc in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr  1 20:37:47 2016 bougon_p
** Last update Fri Apr  1 23:36:15 2016 bougon_p
*/

#include "my.h"

char	*my_realloc(char *line, size_t add)
{
  char  *new_line;
  int   size;
  int   i;

  i = 0;
  size = 0;
  while (line[size] != 0)
    size++;
  if ((new_line = malloc(sizeof(char) * (size + add + 2))) == NULL)
    return (NULL);
  while (i < size)
    {
      new_line[i] = line[i];
      i++;
    }
  while (i < (size + (int)add + 2))
    new_line[i++] = 0;
  free(line);
  return (new_line);
}
