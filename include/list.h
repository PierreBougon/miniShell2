/*
** list.h for LIST in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr  2 18:10:26 2016 bougon_p
** Last update Sat Apr  2 19:30:01 2016 bougon_p
*/

#ifndef LIST_H_
# define LIST_H_

typedef	struct		s_cmd
{
  char			**cmd;
}			t_cmd;

typedef struct          s_cdlist
{
  struct s_cmd		*data;
  struct s_cdlist       *prev;
  struct s_cdlist       *next;
}                       t_cdlist;

typedef struct          s_arglist
{
  t_cdlist              *root;
}                       t_arglist;

int			create_cdlist(t_cdlist **);
int			add_last_cdl(t_cdlist *, void *);
int			free_lablist(t_arglist *);

#endif /* !LIST_H_ */
