/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:56:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 10:04:46 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"
#include "error.h"

int	ft_init_forks(pthread_mutex_t *forks, int n_fork)
{
	int	i;

	i = 0;
	while (i < n_fork)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
			return (ft_puterror("Failed init muitex\n", 0));
		i++;
	}
	return (1);
}
