/*
** cd.c for cd in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 22:48:45 2016 bougon_p
** Last update Fri Apr  1 18:11:00 2016 bougon_p
*/

#include "shell.h"

char    *strcatnext_file(char *dest, char *src)
{
  int   i;
  int   p;

  i = -1;
  p = -1;
  while (dest[++i] != 0);
  dest[i++] = '/';
  while (src[++p] != 0 && src[p] != '/')
    dest[i++] = src[p];
  dest[i] = 0;
  return (dest);
}

void	modify_pwd(char *pwd)
{
  int	i;

  i = my_strlen(pwd);
  while (pwd[--i] != '/')
    pwd[i] = 0;
  pwd[i] = 0;
}

void	get_real_path(char *pwd_asked, char *act_pwd)
{
  int	i;
  bool	next;

  i = -1;
  printf("ASKED PWD = %s\n", pwd_asked);
  next = true;
  while (pwd_asked[++i])
    {
      if (pwd_asked[i] == '.')
	{
	  if (pwd_asked[i + 1] == '.')
	    modify_pwd(act_pwd);
	}
      else if (pwd_asked[i] != '/' && next)
	{
	  strcatnext_file(act_pwd, &pwd_asked[i]);
	  next = false;
	}
      else if (pwd_asked[i] == '/')
	next = true;
    }
  printf("MODIF PWD = %s\n", act_pwd);
}

void	change_path(t_data *data, char *pwd_asked, char *act_pwd)
{
  int	j;

  get_real_path(pwd_asked, act_pwd);
  j = get_pos_from_env(data, "PWD");
  my_strcpy(&data->env[j][4], act_pwd);
}

int	m_cd(t_data *data)
{
  char	*pwd_asked;
  char	*act_pwd;
  int	ret;

  pwd_asked = data->cmd[1];
  ret = chdir(pwd_asked);
  printf("%d\n", ret);
  if (ret == 0)
    {
      act_pwd = get_var_from_env(data, "PWD");
      printf("ACT PWD = %s\n", act_pwd);
      change_path(data, pwd_asked, act_pwd);
    }
  else
    {
      my_putstr("Cannot access : ");
      my_putstr(pwd_asked);
      my_putstr("\n");
    }
  return (0);
}
