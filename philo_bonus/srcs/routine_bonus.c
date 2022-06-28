/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:02:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 10:23:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine_bonus.h"
#include "time_bonus.h"
#include <stdio.h>

static int	ft_print_state(t_core *core, const char *state, int died)
{
	long	time;

	sem_wait(core->sem_print);
	time = ft_time(&core->start);
	if (core->sem_died->__align != 0)
	{
		sem_post(core->sem_print);
		return (DIED);
	}
	if (died == DIED)
		sem_post(core->sem_died);
	printf("%ld %d %s\n", time, core->id, state);
	sem_post(core->sem_print);
	return (ALIVE);
}

static int	ft_isdead(t_core *core, int eat, struct timeval *s_eat)
{
	struct timeval	*t;

	t = s_eat;
	if (eat == 0)
		t = &core->start;
	if (ft_time(t) >= core->t_die)
		return (DIED);
	return (ALIVE);
}

int	ft_fork(t_core *core, int eat, struct timeval *s_eat, int has_fork)
{
	while (core->sem_forks->__align == 0)
	{
		if (ft_isdead(core, eat, s_eat) == DIED || core->sem_died->__align != 0)
		{
			if (has_fork)
				sem_post(core->sem_forks);
			ft_print_state(core, "died", DIED);
			return (DIED);
		}
	}
	sem_wait(core->sem_forks);
	if (ft_print_state(core, "has taken a fork", ALIVE) == DIED)
	{
		if (has_fork)
			sem_post(core->sem_forks);
		sem_post(core->sem_forks);
		return (DIED);
	}
	return (ALIVE);
}

int	ft_eating(t_core *core, int eat, struct timeval *s_eat)
{
	gettimeofday(s_eat, NULL);
	if (ft_print_state(core, "is eating", ALIVE) == DIED)
		return (DIED);
	while (ft_time(s_eat) < core->t_eat)
	{
		if (ft_isdead(core, eat, s_eat) == DIED || core->sem_died->__align != 0)
		{
			ft_print_state(core, "died", DIED);
			return (DIED);
		}
	}
	sem_post(core->sem_forks);
	sem_post(core->sem_forks);
	return (ALIVE);
}

int	ft_sleeping(t_core *core, int eat, struct timeval *s_eat)
{
	if (ft_print_state(core, "is sleeping", ALIVE) == DIED)
		return (DIED);
	while (ft_time(s_eat) < (core->t_eat + core->t_sleep))
	{
		if (ft_isdead(core, eat, s_eat) == DIED || core->sem_died->__align != 0)
		{
			ft_print_state(core, "died", DIED);
			return (DIED);
		}
	}
	if (ft_print_state(core, "is thinking", ALIVE) == DIED)
		return (DIED);
	return (ALIVE);
}
