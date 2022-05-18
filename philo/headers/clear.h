/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:17:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/18 16:38:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_H
# define CLEAR_H

# include "struct.h"

/**
 * It destroys all mutex allocated in forks, free forks and pointed to NULL.
 * If a destroy mutex failed an error will display.
 */
void	ft_clear_forks(pthread_mutex_t **forks, int n_mtx_init);

/**
 * It destroy the print mutex and free this mutex and the start variable.
 * If the destroiy mutex failed an error will display.
 */
void	ft_clear_core(t_core *core);

#endif
