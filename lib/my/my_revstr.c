/*
** my_revstr.c for revstr in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:26:58 2016 bougon_p
** Last update Mon Mar 28 12:27:15 2016 bougon_p
*/

#include "my.h"

char    *my_revstr(char *str)
{
  int   i;
  int   end;
  char  stock;

  i = 0;
  end = my_strlen(str) - 1;
  while (i < (my_strlen(str) / 2))
    {
      stock = str[i];
      str[i] = str[end];
      str[end] = stock;
      i = i + 1;
      end = end - 1;
    }
  return (str);
}
