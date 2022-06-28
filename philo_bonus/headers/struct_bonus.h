/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:17:00 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:49:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include <semaphore.h>

typedef struct s_core
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				id;
	struct timeval	start;
	sem_t			*sem_forks;
	sem_t			*sem_sync;
	sem_t			*sem_died;
	sem_t			*sem_print;
}	t_core;

#endif
