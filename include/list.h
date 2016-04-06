/*
** list.h for LIST in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr  2 18:10:26 2016 bougon_p
** Last update Wed Apr  6 17:20:47 2016 bougon_p
*/

#ifndef LIST_H_
# define LIST_H_

typedef	struct		s_coms
{
  char			**cmd;
  char			**cmd_pip;
}			t_coms;

typedef struct          s_cdlist
{
  struct s_coms		*data;
  struct s_cdlist       *prev;
  struct s_cdlist       *next;
}                       t_cdlist;

typedef struct          s_arglist
{
  t_cdlist              *root;
}                       t_arglist;

int			create_cdlist(t_cdlist **);
int			add_last_cdl(t_cdlist *, void *);
int			free_list(t_arglist *);

#endif /* !LIST_H_ */
