/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:17:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/07 16:24:55 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_H
# define CLEAR_H

# include "struct.h"

/**
 *
 */
void	ft_clear_forks(pthread_mutex_t **forks, int n_mtx_init);

/**
 *
 */
void	ft_clear_core(t_core *core);

#endif
