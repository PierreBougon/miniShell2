/*
** free_tab.c for tab in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 18:18:18 2016 bougon_p
** Last update Wed Apr  6 23:32:38 2016 bougon_p
*/

#include "shell.h"

void    free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      /* printf("%d -> ", i); */
      /* printf("%s\n", tab[i]); */
      free(tab[i++]);
    }
  free(tab);
}
