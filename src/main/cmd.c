/*
** cmd.c for CMD in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 13:59:56 2016 bougon_p
** Last update Fri Apr  8 17:58:55 2016 bougon_p
*/

#include "shell.h"

int	exec_forked(t_data *data, char **tab)
{
  bool	full_test;

  full_test = true;
  check_cmd_exist(data, tab[0], &full_test);
  while (tab[0][0] != 0 &&
	 m_execve(tab[0], tab, data->env) == -1)
    {
      if (full_test)
	{
	  tab[0] = rewrite_bin_cmd(tab[0]);
	  if (((tab[0] = get_next_path(data)) == NULL))
	    full_test = false;
	}
      if (!full_test)
	cmd_err(data, tab);
    }
  cmd_err(data, tab);
  return (0);
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

  cpid = fork();
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
  if (cpid != 0)
    wait_exit();
  return (cpid);
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
