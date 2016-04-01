/*
** my_strlen.c for STRLEN in /home/bougon_p/rendu/CPE_2015_Allum1/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 18 16:41:17 2016 bougon_p
** Last update Mon Mar 28 12:22:14 2016 bougon_p
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0);
  return (i);
}
