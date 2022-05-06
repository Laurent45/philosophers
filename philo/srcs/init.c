/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:07:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:46:05 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
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
			free(*forks);
			*forks = NULL;
			return (ft_puterror("Failed init mutex\n", 0));
		}
		i++;
	}
	*forks = fks;
	return (1);
}

static pthread_mutex_t	*ft_left_fork(pthread_mutex_t *forks, int n_fork, int p)
{
	if (p == 0)
		return (forks + (n_fork - 1));
	return (forks + (p - 1));
}

int	ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core)
{
	t_philo			*phs;
	int				i;

	phs = (t_philo *) malloc(sizeof(t_philo) * core->n_philo);
	if (!phs)
	{
		free(*forks);
		*forks = NULL;
		*philos = NULL;
		return (0);
	}
	i = 0;
	while (i < core->n_philo)
	{
		phs[i].position = i + 1;
		phs[i].core = core;
		phs[i].l_fork = ft_left_fork(*forks, core->n_philo, i);
		phs[i].r_fork = *forks + i; 
		i++;
	}
	*philos = phs;
	return (1);
}

int	ft_init_core(t_core *core)
{
	core->ready = 0;
	core->start = (struct timeval *) malloc(sizeof(struct timeval));
	if (!core->start)
		return (0);
	core->m_print = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	if (!core->m_print)
	{
		free(core->start);
		return (0);
	}
	pthread_mutex_init(core->m_print, NULL);
	return (1);
}
