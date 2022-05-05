/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:56:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"
#include "error.h"
#include <stdlib.h>

int	ft_create_forks(pthread_mutex_t **forks, int n_fork)
{
	pthread_mutex_t	*fks;
	int				i;

	fks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * n_fork);
	if (!fks)
		return (0);
	*forks = fks;
	i = 0;
	while (i < n_fork)
	{
		if (pthread_mutex_init(fks + i, NULL) != 0)
		{
			ft_clear_forks(forks, n_fork);
			return (ft_puterror("Failed init mutex\n", 0));
		}
		i++;
	}
	*forks = fks;
	return (1);
}

int	ft_destroy_forks(pthread_mutex_t *forks, int n_fork)
{
	int	i;
	int	failed;

	i = 0;
	failed = 1;
	while (i < n_fork)
	{
		if (pthread_mutex_destroy(forks + i) != 0)
			failed = 0;
	}
	return (failed);
}

void	ft_clear_forks(pthread_mutex_t **forks, int n_fork)
{
	int	i;

	i = 0;
	while (i < n_fork)
	{
		free(*forks + i);
		i++;
	}
	*forks = NULL;
}

pthread_mutex_t	*ft_left_fork(pthread_mutex_t *forks, int n_fork, int position)
{
	if (position == 0)
		return (forks + (n_fork - 1));
	return (forks + (position - 1));
}

pthread_mutex_t	*ft_right_fork(pthread_mutex_t *forks, int n_fork, int position)
{
	if (position == (n_fork - 1))
		return (forks);
	return (forks + (position + 1));
}
