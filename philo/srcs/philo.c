/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:45:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:48:57 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"
#include "struct.h"
#include <stdio.h>

void	*ft_routine(void *args)
{
	t_philo			*philo;
	struct timeval	t;

	philo = (t_philo *) args;
	while (!philo->core->ready);
	gettimeofday(&t, NULL);
	pthread_mutex_lock(philo->core->m_print);
	printf("This is the thread of philo %d\n", philo->position);
	printf("This thread start at %ld\n", ft_get_time_ms(philo->core->start, &t));
	pthread_mutex_unlock(philo->core->m_print);
	return (NULL);
}
