/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:03:32 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/04 16:22:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_philos(t_philo **philos, t_core *core)
{
	t_philo			*phs;
	pthread_mutex_t	*forks;
	int				i;

	// TODO: check leaks if allocated failed
	phs = (t_philo *) malloc(sizeof(t_philo) * core->n_philo);
	if (!phs)
		return (0);
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * core->n_philo);
	if (!forks)
		return (0);
	ft_init_forks(forks, core->n_philo);
	i = 0;
	while (i < core->n_philo)
	{
		phs[i].position = i;
		phs[i].core = core;
		phs[i].l_fork = ft_get_fork(pthread_mutex_t *forks, core->n_philo, i);
		phs[i].r_fork = ft_get_fork(pthread_mutex_t *forks, core->n_philo, i);
		i++;
	}
	*philos = phs;
	return (1);
}
