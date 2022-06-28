/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:02:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 20:04:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"
#include "time.h"
#include <unistd.h>
#include <stdio.h>

static int	ft_print_state(t_philo *philo, const char *state, int died)
{
	long	time;

	pthread_mutex_lock(philo->core->m_print);
	time = ft_time(&philo->core->start);
	if (philo->core->died)
	{
		pthread_mutex_unlock(philo->core->m_print);
		return (DIED);
	}
	if (died == DIED)
		philo->core->died = 1;
	printf("%ld %d %s\n", time, philo->id, state);
	pthread_mutex_unlock(philo->core->m_print);
	return (ALIVE);
}

static int	ft_isdead(t_philo *philo, int eat, struct timeval *time)
{
	struct timeval	*t;

	t = time;
	if (eat == 0)
		t = &philo->core->start;
	if (ft_time(t) >= philo->core->t_die)
		return (DIED);
	return (ALIVE);
}

int	ft_fork(t_philo *p, int eat, struct timeval *s_eat, pthread_mutex_t *fork)
{
	while (fork->__data.__lock)
	{
		if (ft_isdead(p, eat, s_eat) == DIED)
		{
			ft_print_state(p, "died", DIED);
			return (DIED);
		}
	}
	pthread_mutex_lock(fork);
	if (ft_print_state(p, "has taken a fork", ALIVE) == DIED)
	{
		pthread_mutex_unlock(fork);
		return (DIED);
	}
	return (ALIVE);
}

int	ft_eating(t_philo *philo, int eat, struct timeval *start_eat)
{
	gettimeofday(start_eat, NULL);
	if (ft_print_state(philo, "is eating", ALIVE) == DIED)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (DIED);
	}
	while (ft_time(start_eat) < philo->core->t_eat)
	{
		if (ft_isdead(philo, eat, start_eat) == DIED || philo->core->died)
		{
			ft_print_state(philo, "died", DIED);
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			return (DIED);
		}
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (ALIVE);
}

int	ft_sleeping(t_philo	*philo, int eat, struct timeval *start_eat)
{
	if (ft_print_state(philo, "is sleeping", ALIVE) == DIED)
		return (DIED);
	while (ft_time(start_eat) < (philo->core->t_eat + philo->core->t_sleep))
	{
		if (ft_isdead(philo, eat, start_eat) == DIED || philo->core->died)
		{
			ft_print_state(philo, "died", DIED);
			return (DIED);
		}
	}
	if (ft_print_state(philo, "is thinking", ALIVE) == DIED)
		return (DIED);
	usleep(50000);
	return (ALIVE);
}
