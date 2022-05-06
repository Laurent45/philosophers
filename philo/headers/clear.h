/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:17:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:18:09 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_H
# define CLEAR_H

# include "struct.h"

/**
 *
 */
int		ft_destroy_forks(pthread_mutex_t *forks, int n_fork);

/**
 *
 */
void	ft_clear_core(t_core *core);

#endif
