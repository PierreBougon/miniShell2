/*
** exit.c for exit in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:50:49 2016 bougon_p
** Last update Sun Apr  3 01:05:01 2016 bougon_p
*/

#include "shell.h"

int	m_exit(UNUSED t_data *data)
{
  free_list(&data->all_cmd);
  return (1);
}
