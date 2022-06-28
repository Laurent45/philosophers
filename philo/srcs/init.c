/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:07:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 10:37:09 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "clear.h"
#include "error.h"
#include <stdlib.h>

int	ft_create_forks(pthread_mutex_t **forks, int n_fork, t_core *core)
{
	int	i;

	*forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * n_fork);
	if (!*forks)
	{
		ft_clear_core(core);
		return (0);
	}
	i = 0;
	while (i < n_fork)
	{
		if (pthread_mutex_init(*forks + i, NULL) != 0)
		{
			ft_clear_core(core);
			ft_clear_forks(forks, i);
			return (ft_puterror("Failed init mutex\n", 0));
		}
		i++;
	}
	return (1);
}

int	ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core)
{
	int	i;

	*philos = (t_philo *) malloc(sizeof(t_philo) * core->n_philo);
	if (!*philos)
	{
		ft_clear_forks(forks, core->n_philo);
		ft_clear_core(core);
		return (0);
	}
	i = 0;
	while (i < core->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].core = core;
		if (i == 0)
			(*philos)[i].l_fork = *forks + (core->n_philo - 1);
		else
			(*philos)[i].l_fork = *forks + (i - 1);
		(*philos)[i].r_fork = *forks + i;
		i++;
	}
	return (1);
}

static	int	ft_free_core(t_core *core)
{
	if (core->m_print)
		free(core->m_print);
	return (0);
}

int	ft_init_core(t_core *core)
{
	core->ready = 0;
	core->died = 0;
	core->m_print = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	if (!core->m_print)
		return (ft_free_core(core));
	if (pthread_mutex_init(core->m_print, NULL) != 0)
	{
		ft_free_core(core);
		return (ft_puterror("Failed to init mutex print\n", 0));
	}
	return (1);
}
