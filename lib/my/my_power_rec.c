/*
** my_power_rec.c for pow in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:24:47 2016 bougon_p
** Last update Mon Mar 28 12:24:57 2016 bougon_p
*/

#include "my.h"

int     my_power_rec(int nb, int i)
{
  if (i < 0 || i > 100000)
    return (0);
  if (i == 0)
    return (1);
  return (nb * my_power_rec(nb, i - 1));
}
