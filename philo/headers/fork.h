/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:30:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 14:59:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

/**
 *
 */
int		ft_create_forks(pthread_mutex_t **forks, int n_fork);

/**
 *
 */
int		ft_destroy_forks(pthread_mutex_t *forks, int n_fork);

/**
 *
 */
void	ft_clear_forks(pthread_mutex_t **forks, int n_fork);

/**
 *
 */
pthread_mutex_t	*ft_left_fork(pthread_mutex_t *forks, int n_fork, int position);

/**
 *
 */
pthread_mutex_t	*ft_right_fork(pthread_mutex_t *forks, int n_fork, int position);

#endif
