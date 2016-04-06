/*
** count.c for count in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr  3 15:51:24 2016 bougon_p
** Last update Sun Apr  3 16:07:34 2016 bougon_p
*/

#include "shell.h"

int	count_spaces(char *str)
{
  int	i;
  int	n;

  i = -1;
  n = 0;
  while (str[++i])
    {
      if (str[i] == ' ')
	n++;
    }
  return (n);
}

int	count_cmd(char *str)
{
  int	i;
  int	n;

  i = -1;
  n = 0;
  while (str[++i])
    {
      if (str[i] == ';')
	n++;
    }
  return (n);
}
