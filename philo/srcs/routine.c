/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:02:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/17 16:19:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"
#include "time.h"
#include <stdio.h>

static int	ft_print_state(t_philo *philo, const char *state)
{
	long	time;

	time = ft_time(philo->core->start);
	pthread_mutex_lock(philo->core->m_print);
	pthread_mutex_lock(philo->core->m_died);
	if (philo->core->died)
	{
		pthread_mutex_unlock(philo->core->m_died);
		pthread_mutex_unlock(philo->core->m_print);
		return (0);
	}
	printf("%ld %d %s\n", time, philo->id, state);
	pthread_mutex_unlock(philo->core->m_died);
	pthread_mutex_unlock(philo->core->m_print);
	return (1);
}

static int	ft_isdead(t_philo *philo, int eat, struct timeval *time)
{
	struct timeval	*t;

	t = time;
	if (eat == 0)
		t = philo->core->start;
	if (ft_time(t) >= philo->core->t_die)
		return (1);
	return (0);
}

int	ft_fork(t_philo *p, int eat, struct timeval *s_eat, pthread_mutex_t *fork)
{
	while (fork->__data.__lock)
	{
		if (ft_isdead(p, eat, s_eat))
		{
			if (ft_print_state(p, "died"))
			{
				pthread_mutex_lock(p->core->m_died);
				p->core->died = 1;
				pthread_mutex_unlock(p->core->m_died);
			}
			return (0);
		}
	}
	pthread_mutex_lock(fork);
	if (!ft_print_state(p, "has taken a fork"))
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	return (1);
}

int	ft_eating(t_philo *philo, int eat, struct timeval *start_eat)
{
	gettimeofday(start_eat, NULL);
	if (!ft_print_state(philo, "is eating"))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	while (ft_time(start_eat) < philo->core->t_eat)
	{
		if (philo->core->died || ft_isdead(philo, eat, start_eat))
		{
			if (ft_print_state(philo, "died"))
			{
				pthread_mutex_lock(philo->core->m_died);
				philo->core->died = 1;
				pthread_mutex_unlock(philo->core->m_died);
			}
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			return (0);
		}
	}
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (1);
}

int	ft_sleeping(t_philo	*philo, int eat, struct timeval *start_eat)
{
	if (!ft_print_state(philo, "is sleeping"))
		return (0);
	while (ft_time(start_eat) < (philo->core->t_eat + philo->core->t_sleep))
	{
		if (philo->core->died || ft_isdead(philo, eat, start_eat))
		{
			if (ft_print_state(philo, "died"))
			{
				pthread_mutex_lock(philo->core->m_died);
				philo->core->died = 1;
				pthread_mutex_unlock(philo->core->m_died);
			}
			return (0);
		}
	}
	if (!ft_print_state(philo, "is thinking"))
		return (0);
	return (1);
}
