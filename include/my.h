/*
** my.h for MY in /home/bougon_p/rendu/PSU_2015_minitalk/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 21:02:13 2016 bougon_p
** Last update Fri Apr  1 20:51:54 2016 bougon_p
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>

void	my_putchar(char);
int	my_putstr(char *);
int	my_strcmp(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
char	*my_realloc(char *, size_t);
int	my_strncmp(char *, char *, int);
int	my_strlen(char *);
int	my_getnbr(char *);
void	my_put_nbr(int);
char	*my_revstr(char *);
char	*my_strdup(char *);
void	*my_bzero(void *, size_t);
int	my_printf(const char *, ...);

#endif /* !MY_H_ */
