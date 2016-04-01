/*
** my_getnbr.c for GETNBR in /home/bougon_p/rendu/PSU_2015_minisell2/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:07:39 2016 bougon_p
** Last update Mon Mar 28 12:23:34 2016 bougon_p
*/

#include "my.h"

int             my_getnbr(char *str)
{
  unsigned int  total;
  int           isneg;
  int           i;

  i = 0;
  isneg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
        isneg = -isneg;
      i = i + 1;
    }
  total = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      total = ((total * 10) + (str[i] - 48));
      i = i + 1;
    }
  return (total * isneg);
}
