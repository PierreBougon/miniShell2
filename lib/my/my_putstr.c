/*
** my_putstr.c for PUTSTR in /home/bougon_p/rendu/PSU_2015_minisell2/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:07:26 2016 bougon_p
** Last update Mon Mar 28 12:20:55 2016 bougon_p
*/

#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
