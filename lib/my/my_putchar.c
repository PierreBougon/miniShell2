/*
** my_putchar.c for my_putchar in /home/bougon_p/rendu/Piscine_C_J07
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Oct  6 16:13:25 2015 Pierre Bougon
** Last update Mon Mar 28 12:20:44 2016 bougon_p
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
