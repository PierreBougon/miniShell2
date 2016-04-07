/*
** cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 13:59:56 2016 bougon_p
** Last update Thu Apr  7 20:44:16 2016 bougon_p
*/

#include "shell.h"

char	*rewrite_cmd(char *cmd)
{
  char	*new;

  if ((new = malloc(sizeof(char) * my_strlen(cmd) + 6)) == NULL)
    return (NULL);
  my_bzero(new, my_strlen(cmd) + 6);
  if (my_strncmp(cmd, "/bin/", 5) == 0)
    return (free(new), cmd);
  my_strcpy(new, "/bin/");
  my_strcat(new, cmd);
  free(cmd);
  return (new);
}

char	*rewrite_bin_cmd(char *cmd)
{
  char	*new;

  if (my_strncmp(cmd, "/bin/", 5) != 0)
    return (cmd);
  new = my_strdup(&cmd[5]);
  free(cmd);
  return (new);
}

int	exec_forked(t_data *data, char **tab)
{
  bool	full_test;
  int	nb_path;

  data->nb_path = 1;
  full_test = true;
  /* if (tab[0][0] == '/') */
  /*   return (putstr_err("Invalid command\n"), 1); */
  if ((nb_path = get_pos_from_env(data, "PATH")) == -1)
    {
      tab[0] = rewrite_cmd(tab[0]);
      full_test = false;
    }
  data->savecmd = tab[0];
  dprintf(2, "first cmd = %s\n", tab[0]);
  while (tab[0][0] != 0
	 && execve(tab[0], tab, data->env) == -1)
    {
      if (full_test)
	{
	  tab[0] = rewrite_bin_cmd(tab[0]);
	  if ((tab[0] = get_next_path(data)) == NULL)
	    full_test = false;
	}
      if (!full_test)
	{
	  putstr_err(data->savecmd);
	  putstr_err(": Command not found.\n");
	  break ;
	}
    }
  free_tab(tab);
  exit(1);
}

void	exec_pipe(t_data *data, char **tab, char **tab_pipe)
{
  pid_t	cpid_2;
  int	pipefd[2];
  int	status;

  pipe(pipefd);
  cpid_2 = fork();
  if (cpid_2 != 0)
    wait(&status);
  if (cpid_2 == 0)
    {
      dup2(pipefd[1], 1);
      close(pipefd[0]);
      if (exec_forked(data, tab) == 1)
	exit(1);
    }
  else
    {
      dup2(pipefd[0], 0);
      close(pipefd[1]);
      if (exec_forked(data, tab_pipe) == 1)
	exit(1);
    }
}

int	launch_cmd(t_data *data, char **tab, char **tab_pipe)
{
  pid_t	cpid;
  int	status;

  cpid = fork();
  if (cpid != 0)
    wait(&status);
  if (cpid == 0)
    {
      if (!data->pipe)
	{
	  if (exec_forked(data, tab) == 1)
	    exit(1);
	}
      else
	exec_pipe(data, tab, tab_pipe);
    }
  return (cpid);
}

void	epur_all_cmd(t_cdlist *tmp)
{
  int	j;

  j = -1;
  while (tmp->data->cmd[++j] != NULL)
    tmp->data->cmd[j] = my_epur_str(tmp->data->cmd[j]);
}

int		exec_cmd(char *buf, t_data *data)
{
  int		ret;
  t_cdlist	*tmp;

  parse_args(buf, data);
  tmp = data->all_cmd.root->next;
  while (tmp != data->all_cmd.root)
    {
      epur_all_cmd(tmp);
      if ((data->pipe = parse_pipes(tmp)) == true)
	if (check_pipe_err(tmp) == 1)
	  return (0);
      show_all_tab(tmp, data);
      if (tmp->data->cmd[0][0] != 0)
	{
	  if ((ret = check_builtin(data, tmp->data->cmd)) == 1)
	    return (-2);
	  else if (ret == 2)
	    launch_cmd(data, tmp->data->cmd, tmp->data->cmd_pip);
	}
      tmp = tmp->next;
    }
  free_list(&data->all_cmd);
  return (0);
}
