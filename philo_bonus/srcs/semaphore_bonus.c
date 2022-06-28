/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:27:27 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 10:07:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include "semaphore_bonus.h"

int	ft_close_sems(t_core *core, int ret)
{
	if (core->sem_forks != NULL && core->sem_forks != SEM_FAILED)
		sem_close(core->sem_forks);
	if (core->sem_sync != NULL && core->sem_sync != SEM_FAILED)
		sem_close(core->sem_sync);
	if (core->sem_died != NULL && core->sem_died != SEM_FAILED)
		sem_close(core->sem_died);
	if (core->sem_print != NULL && core->sem_print != SEM_FAILED)
		sem_close(core->sem_print);
	return (ret);
}

int	ft_init_sems(t_core *core)
{
	core->sem_forks = NULL;
	core->sem_sync = NULL;
	core->sem_died = NULL;
	core->sem_print = NULL;
	sem_unlink("sem_forks");
	core->sem_forks = sem_open("sem_forks", O_CREAT, 0644, core->n_philo);
	if (core->sem_forks == SEM_FAILED)
		return (ft_close_sems(core, 0));
	sem_unlink("sem_sync");
	core->sem_sync = sem_open("sem_sync", O_CREAT, 0644, 0);
	if (core->sem_sync == SEM_FAILED)
		return (ft_close_sems(core, 0));
	sem_unlink("sem_died");
	core->sem_died = sem_open("sem_died", O_CREAT, 0644, 0);
	if (core->sem_died == SEM_FAILED)
		return (ft_close_sems(core, 0));
	sem_unlink("sem_print");
	core->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	if (core->sem_print == SEM_FAILED)
		return (ft_close_sems(core, 0));
	return (1);
}
