/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:49:18 by jlinguet          #+#    #+#             */
/*   Updated: 2024/02/10 17:38:27 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
static char	**ft_append(char **tab, char *s)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc((i + 2) * sizeof (char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = s;
	new_tab[i + 1] = NULL;
	return (free(tab), new_tab);
}
*/
t_cmd	parse(int ac, char **av)
{
	t_cmd	cmd;

	cmd.file2 = NULL;
	if (ac != 5)
		return (perror("Incorrect arguments"), cmd);
	if (access(av[1], R_OK))
		return (perror("Cannot accoss or read file1"), cmd);
	cmd.file1 = av[1];
	cmd.prog1 = ft_split(av[2], ' ');
	if (access(cmd.prog1[0], F_OK))
		return (perror("Cannot access cmd1"), cmd);
	//cmd.prog1 = ft_append(cmd.prog1, av[1]);
	cmd.prog2 = ft_split(av[3], ' ');
	if (access(cmd.prog2[0], F_OK))
		return (perror("Cannot access cmd2"), cmd);
	if (!av[4][0] || (!access(av[4], F_OK) && access(av[4], R_OK)))
		return (perror("Cannot write in file2"), cmd);
	cmd.file2 = av[4];
	return (cmd);
}
