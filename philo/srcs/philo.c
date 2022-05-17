/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:45:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/17 16:24:04 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"
#include "routine.h"
#include <unistd.h>

void	*ft_routine(void *args)
{
	t_philo			*p;
	int				eat;
	struct timeval	s_eat;

	p = (t_philo *) args;
	eat = 0;
	while (!p->core->ready)
	{
	}
	if (p->id % 2 == 0 || p->id == p->core->n_philo)
		usleep(5000);
	while (p->core->died == 0)
	{
		if ((eat == p->core->n_eat) || (!ft_fork(p, eat, &s_eat, p->l_fork)))
			return (NULL);
		if (!ft_fork(p, eat, &s_eat, p->r_fork))
		{
			pthread_mutex_unlock(p->l_fork);
			return (NULL);
		}
		eat++;
		if (!ft_eating(p, eat, &s_eat) || !ft_sleeping(p, eat, &s_eat))
			return (NULL);
	}
	return (NULL);
}
