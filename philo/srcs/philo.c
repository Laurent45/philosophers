/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:45:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/09 15:08:33 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"
#include "struct.h"
#include <stdio.h>
#include <unistd.h>

void	ft_print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(philo->core->m_print);
	printf("%ld %d %s\n", ft_time(philo->core->start), philo->position, state);
	pthread_mutex_unlock(philo->core->m_print);
}

void	*ft_routine(void *args)
{
	t_philo			*philo;
	int				eat;
	struct timeval	t;

	philo = (t_philo *) args;
	eat = 0;
	while (!philo->core->ready);
	gettimeofday(&t, NULL);
	if (philo->position % 2 == 0 || philo->position == philo->core->n_philo)
		usleep(5000);
	while (eat < philo->core->n_eat)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		ft_print_state(philo, "has taken a fork");
		ft_print_state(philo, "is eating");
		usleep(philo->core->t_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print_state(philo, "is sleeping");
		usleep(philo->core->t_sleep * 1000);
		ft_print_state(philo, "is thinking");
		eat++;
	}
	return (NULL);
}
