/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:40:27 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:37:57 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_BONUS_H
# define ROUTINE_BONUS_H

# include "struct_bonus.h"

# define DIED	0
# define ALIVE	1

/**
 * It resumes when a philo try to take a fork.
 * Return 0 or 1 based on philo is died or not.
 */
int	ft_fork(t_core *core, int eat, struct timeval *s_eat, int has_fork);

/**
 * It resumes when a philo is eating.
 * Return 0 or 1 based on philo is died or not.
 */
int	ft_eating(t_core *core, int eat, struct timeval *start_eat);

/**
 * It resumes when a philo is sleeping.
 * Return 0 or 1 based on philo is died or not.
 */
int	ft_sleeping(t_core *core, int eat, struct timeval *start_eat);

#endif
