/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:03:32 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 14:57:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "fork.h"
#include <stdlib.h>

int	ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core)
{
	t_philo			*phs;
	int				i;

	// TODO: check leaks if allocated failed
	phs = (t_philo *) malloc(sizeof(t_philo) * core->n_philo);
	if (!phs)
	{
		ft_clear_forks(forks, core->n_philo);
		*philos = NULL;
		return (0);
	}
	i = 0;
	while (i < core->n_philo)
	{
		phs[i].position = i;
		phs[i].core = core;
		phs[i].l_fork = ft_left_fork(*forks, core->n_philo, i);
		phs[i].r_fork = ft_right_fork(*forks, core->n_philo, i);
		i++;
	}
	*philos = phs;
	return (1);
}

void	ft_clear_philo(t_philo **philos, pthread_mutex_t **forks, int n_philo)
{
	int	i;

	ft_clear_forks(forks, n_philo);
	i = 0;
	while (i < n_philo)
	{
		free(*philos + i);
		i++;
	}
	*philos = NULL;
}

