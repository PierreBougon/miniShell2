/*
** my_put_nbr.c for put nbr in /home/bougon_p
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Oct  6 11:34:10 2015 Pierre Bougon
** Last update Mon Mar 28 12:26:32 2016 bougon_p
*/

#include "my.h"

void	my_calc_nbr(int nbr)
{
  if (nbr >= 10)
    my_calc_nbr(nbr / 10);
  if (nbr > 0)
    my_putchar((nbr % 10) + 48);
}

void	my_put_nbr(int nbr)
{
  if (nbr == 0)
    {
      my_putchar('0');
      return ;
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  my_calc_nbr(nbr);
}
