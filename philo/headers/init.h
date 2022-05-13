/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:13:10 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/13 15:01:34 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

/**
 *
 */
int	ft_create_forks(pthread_mutex_t **forks, int n_fork, t_core *core);

/**
 *
 */
int	ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core);

/**
 *
 */
int	ft_init_core(t_core *core);

#endif
