/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:11:57 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/17 16:45:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear.h"
#include "error.h"
#include <stdlib.h>

void	ft_clear_forks(pthread_mutex_t **forks, int n_mtx_init)
{
	int	i;

	i = 0;
	while (i < n_mtx_init)
	{
		if (pthread_mutex_destroy(*forks + i) != 0)
			ft_puterror("Failed to destroy mutex forks\n", 0);
		i++;
	}
	free(*forks);
	*forks = NULL;
}

void	ft_clear_core(t_core *core)
{
	if (pthread_mutex_destroy(core->m_died) != 0)
		ft_puterror("Failed to destoy mutex died\n", 0);
	free(core->m_died);
	if (pthread_mutex_destroy(core->m_print) != 0)
		ft_puterror("Failed to destoy mutex died\n", 0);
	free(core->m_print);
	free(core->start);
}
