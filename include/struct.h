/*
** struct.h for STRUCT in /home/bougon_p/rendu/gfx_raytracer1/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 11 18:20:50 2016 bougon_p
** Last update Thu Apr  7 18:46:38 2016 bougon_p
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_data
{
  char			**env;
  char			**cmd;
  char			*pwd;
  char			*old_pwd;
  char			*user;
  char			*savecmd;
  bool			pipe;
  t_arglist		all_cmd;
  int			nb_path;
  int			n_max;
  char			**builtins;
  int			(**builtin)(struct s_data *);
}			t_data;

#endif /* !STRUCT_H_  */
