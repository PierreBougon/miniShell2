/*
** cd.c for cd in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 30 22:48:45 2016 bougon_p
** Last update Sat Apr  2 01:50:25 2016 bougon_p
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
  if ((my_strcmp(&pwd[4], "/home") == 0) ||
      (my_strcmp(&pwd[4], "/")) == 0)
    {
      my_strcpy(pwd, "PWD=/");
      return ;
    }
  while (pwd[--i] != '/')
    pwd[i] = 0;
  pwd[i] = 0;
}

size_t		next_file_len(char *str)
{
  size_t	len;

  len = 0;
  while (str[len] && str[len] != '/')
    len++;
  return (len);
}

char		*get_real_path(char *pwd_asked, char *act_pwd)
{
  int		i;
  bool		next;
  size_t	len;

  i = -1;
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
	  len = next_file_len(&pwd_asked[i]);
	  act_pwd = my_realloc(act_pwd, len);
	  strcatnext_file(act_pwd, &pwd_asked[i]);
	  next = false;
	}
      else if (pwd_asked[i] == '/')
	next = true;
    }
  return (act_pwd);
}

char	*rework_home(char *home)
{
  int	i;
  char	*tmp;

  tmp = my_strdup(home);
  tmp[0] = 'P';
  tmp[1] = 'W';
  tmp[2] = 'D';
  tmp[3] = '=';
  i = 4;
  while (tmp[++i])
    {
      tmp[i - 1] = home[i];
    }
  tmp[i - 1] = 0;
  return (tmp);
}

void	change_path(t_data *data, char *pwd_asked,
		    char *start_pwd, bool go_home)
{
  char	*act_pwd;
  int	j;
  char	*home;

  if (start_pwd == NULL)
    return ;
  if (go_home)
    {
      j = get_pos_from_env(data, "PWD");
      free(data->env[j]);
      home = get_full_var_from_env(data, "HOME");
      data->env[j] = rework_home(home);
      return ;
    }
  if ((act_pwd = malloc(sizeof(char) * my_strlen(start_pwd) + 1)) == NULL)
    exit(1);
  my_bzero(act_pwd, my_strlen(start_pwd) + 1);
  my_strcpy(act_pwd, start_pwd);
  act_pwd = get_real_path(pwd_asked, act_pwd);
  j = get_pos_from_env(data, "PWD");
  free(data->env[j]);
  data->env[j] = act_pwd;
}

int	m_cd(t_data *data)
{
  char	*pwd_asked;
  char	*act_pwd;
  int	ret;
  bool	go_home;

  go_home = false;
  pwd_asked = data->cmd[1];
  if (pwd_asked == NULL)
    {
      pwd_asked = get_var_from_env(data, "HOME");
      go_home = true;
    }
  ret = chdir(pwd_asked);
  if (ret == 0)
    {
      act_pwd = get_full_var_from_env(data, "PWD");
      change_path(data, pwd_asked, act_pwd, go_home);
    }
  else
    {
      my_putstr("Cannot access : ");
      my_putstr(pwd_asked);
      my_putstr("\n");
    }
  return (0);
}
