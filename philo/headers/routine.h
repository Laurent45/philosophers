/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:40:27 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/17 10:56:44 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "struct.h"

/**
 *
 */
int	ft_fork(t_philo *p, int eat, struct timeval *s_eat, pthread_mutex_t *fork);

/**
 *
 */
int	ft_eating(t_philo *philo, int eat, struct timeval *start_eat);

/**
 *
 */
int	ft_sleeping(t_philo	*philo, int eat, struct timeval *start_eat);

#endif
