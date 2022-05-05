/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:17:00 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/04 16:00:23 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct	s_core
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int t_sleep;
	int	n_eat;
}	t_core;

typedef struct	s_philo
{
	int				position;
	struct s_core	*core;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

#endif
