/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:45:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:41:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "time_bonus.h"
#include "routine_bonus.h"
#include <unistd.h>

void	*ft_philo_life(void *args)
{
	t_core			*core;
	int				eat;
	struct timeval	start_eat;

	core = (t_core *) args;
	eat = 0;
	sem_wait(core->sem_sync);
	gettimeofday(&core->start, NULL);
	if (core->id % 2 == 0 || core->id == core->n_philo)
		usleep(5000);
	while (core->sem_died->__align == 0)
	{
		if (eat == core->n_eat)
			return (NULL);
		if (ft_fork(core, eat, &start_eat, 0) == DIED)
			return (NULL);
		if (ft_fork(core, eat, &start_eat, 1) == DIED)
			return (NULL);
		eat++;
		if (ft_eating(core, eat, &start_eat) == DIED)
			return (NULL);
		if (ft_sleeping(core, eat, &start_eat) == DIED)
			return (NULL);
	}
	return (NULL);
}
