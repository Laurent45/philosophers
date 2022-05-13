/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:45:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/13 15:52:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"
#include <stdio.h>
#include <unistd.h>

static void	ft_print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(philo->core->m_print);
	printf("%ld %d %s\n", ft_time(philo->core->start), philo->position, state);
	pthread_mutex_unlock(philo->core->m_print);
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

static int	ft_take_fork(t_philo *p, int eat, struct timeval *s_eat, int hand)
{
	pthread_mutex_t	*fork;

	if (hand == 0)
		fork = p->l_fork;
	else
		fork = p->r_fork;
	while (fork->__data.__lock)
	{
		if (ft_isdead(p, eat, s_eat))
		{
			ft_print_state(p, "died");
			if (hand == 1)
				pthread_mutex_unlock(p->l_fork);
			return (0);
		}
	}
	pthread_mutex_lock(fork);
	ft_print_state(p, "has taken a fork");
	return (1);
}

static void	ft_philo_life(t_philo *philo)
{
	ft_print_state(philo, "is eating");
	usleep(philo->core->t_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_print_state(philo, "is sleeping");
	usleep(philo->core->t_sleep * 1000);
	ft_print_state(philo, "is thinking");
}

void	*ft_routine(void *args)
{
	t_philo			*philo;
	int				eat;
	struct timeval	start_eat;

	philo = (t_philo *) args;
	eat = 0;
	while (!philo->core->ready)
	{
	}
	if (philo->position % 2 == 0 || philo->position == philo->core->n_philo)
		usleep(5000);
	while (eat < philo->core->n_eat)
	{
		if (!ft_take_fork(philo, eat, &start_eat, 0))
			return (NULL);
		if (!ft_take_fork(philo, eat, &start_eat, 1))
			return (NULL);
		gettimeofday(&start_eat, NULL);
		ft_philo_life(philo);
		eat++;
	}
	return (NULL);
}
