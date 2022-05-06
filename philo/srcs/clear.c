/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:11:57 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:34:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear.h"
#include <stdlib.h>

int    ft_destroy_forks(pthread_mutex_t *forks, int n_fork)
{
       int     i;
       int     failed;

       i = 0;
       failed = 1;
       while (i < n_fork)
       {
               if (pthread_mutex_destroy(forks + i) != 0)
                       failed = 0;
			   i++;
       }
       return (failed);
}

void	ft_clear_core(t_core *core)
{
	free(core->start);
	pthread_mutex_destroy(core->m_print);
	free(core->m_print);
}
