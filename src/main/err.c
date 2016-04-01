/*
** err.c for err in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 18:19:06 2016 bougon_p
** Last update Mon Mar 28 18:19:20 2016 bougon_p
*/

#include "shell.h"

void    putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}
