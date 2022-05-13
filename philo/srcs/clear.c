/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:11:57 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/13 15:41:58 by lfrederi         ###   ########.fr       */
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
	free(core->start);
	if (pthread_mutex_destroy(core->m_print) != 0)
		ft_puterror("Failed to destoy mutex print\n", 0);
	free(core->m_print);
}
