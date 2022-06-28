/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 10:39:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input.h"
#include "philo.h"
#include "init.h"
#include "error.h"
#include "clear.h"
#include <stdlib.h>

static void	ft_running(t_core *core, t_philo *phs)
{
	int	i;

	i = 0;
	while (i < core->n_philo)
	{
		if (pthread_create(&phs[i].thread, NULL, &ft_philo_life, phs + i) != 0)
		{
			ft_puterror("Failed created thread\n", 0);
			return ;
		}
		i++;
	}
	core->ready = 1;
	i = 0;
	while (i < core->n_philo)
	{
		if (pthread_join(phs[i].thread, NULL) != 0)
		{
			ft_puterror("Failed join thread\n", 0);
			return ;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_core			core;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (argc != 6 && argc != 5)
		return (ft_puterror("Usage: you should put 4 or 5 args\n", -1));
	if (!ft_check_input(argv + 1, argc - 1, &core))
		return (ft_puterror("Args must be interger positive value\n", -1));
	if (!ft_init_core(&core))
		return (ft_puterror("Failed while creating core\n", -1));
	if (!ft_create_forks(&forks, core.n_philo, &core))
		return (ft_puterror("Failed while creting forks\n", -1));
	if (!ft_create_philos(&philos, &forks, &core))
		return (ft_puterror("Failed while creating philo\n", -1));
	gettimeofday(&core.start, NULL);
	ft_running(&core, philos);
	ft_clear_forks(&forks, core.n_philo);
	ft_clear_core(&core);
	free(philos);
	return (0);
}
