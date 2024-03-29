/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:39:36 by jlinguet          #+#    #+#             */
/*   Updated: 2024/02/10 18:05:41 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	t_cmd	cmd;
	int		file;

	cmd = parse(ac, av);
	if (!cmd.file2)
		return (0);
	if (pipe(fd))
		return (perror("Pipe failed"), 1);
	pid = fork();
	if (pid == CHILD_PROCESS)
	{
		file = open(cmd.file1, O_RDONLY);
		//char *arg[] = { "/bin/ls", "-l", ".", NULL};
		dup2(fd[WR_END], STDOUT_FILENO);
		close(fd[WR_END]);
		close(fd[RD_END]);
		if(execve(cmd.prog1[0], cmd.prog1, env))
			return (perror("Execution of cmd1 failed"), 1);
	}
	else if (pid < 0)
		return (perror("Fork failed"), 1);
	else
	{
		file = open(cmd.file2, O_WRONLY | O_CREAT, BASIC_FILE_MODE);
		//char *arg[] = {"/usr/bin/wc", "-l", NULL};
		dup2(file, STDOUT_FILENO);
		dup2(fd[RD_END], STDIN_FILENO);
		close(fd[WR_END]);
		close(fd[RD_END]);
		if(execve(cmd.prog2[0], cmd.prog2, env))
			return (perror("Execution of cmd2 failed"), 1);
	}
}
