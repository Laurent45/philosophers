/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:03:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 14:58:34 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"

/**
 *
 */
int		ft_create_philos(t_philo **philos, pthread_mutex_t **forks, t_core *core);

/**
 *
 */
void	ft_clear_philo(t_philo **philos, pthread_mutex_t **forks, int n_philo);

#endif
