/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:13:10 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/18 16:51:47 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

/**
 * It creates "n_fork" forks (mutexs). If an allocated or mutex init failed
 * then core is clear and return 0. Otherwise return 1. 
 */
int	ft_create_forks(pthread_mutex_t **forks, int n_fork, t_core *core);

/**
 * It creates n philos structure and return 1.
 * Otherwise return 0 if a issue is detected while the process running.
 */
int	ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core);

/**
 * It init the core structure and return 1.
 * Otherwise return 0 if a issue is detected while the process running.
 */
int	ft_init_core(t_core *core);

#endif
