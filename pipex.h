/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:00:20 by jlinguet          #+#    #+#             */
/*   Updated: 2024/02/10 16:12:21 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* open() */
# include <fcntl.h>

/* close(), read(), write(), access(), dup(),
 * dup2(), execve(), fork(), pipe(), unlink() */
# include <unistd.h>

/* malloc(), free(), exit() */
# include <stdlib.h>

/* perror() */
# include <stdio.h>

/* strerror() */
# include <string.h>
# include <errno.h>

/* wait(), waitpid() */
# include <sys/wait.h>

/* ft_printf() */
# include "ft_printf/ft_printf.h"

/* ft_split() */
# include "libft/libft.h"

# define CHILD_PROCESS 0

# define RD_END 0
# define WR_END 1

# define BASIC_FILE_MODE 0644

typedef struct s_cmd
{
	char	*file1;
	char	**prog1;
	char	**prog2;
	char	*file2;
}	t_cmd;

t_cmd	parse(int ac, char **av);

#endif
