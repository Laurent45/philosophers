/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:42:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input.h"
#include "philo.h"
#include "init.h"
#include "error.h"
#include "clear.h"
#include <stdlib.h>
#include <sys/time.h>

#include <stdio.h>

// TODO: If n_philo = 1, if n_philo = 0
int	main(int argc, char *argv[])
{
	t_core			core;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (argc != 6)
		return (ft_puterror("Usage: ./philo philo t_die t_eat t_sleep n_eat\n", -1));
	if (!ft_check_input(argv + 1, &core))
		return (ft_puterror("Args must be interger positive value\n", -1));
	if (!ft_init_core(&core))
		return (ft_puterror("Failed while creating core\n", -1));
	if (!ft_create_forks(&forks, core.n_philo))
		return (ft_puterror("Failed while creting forks\n", -1));
	if (!ft_create_philos(&philos, &forks, &core))
		return (ft_puterror("Failed while creating philo\n", -1));

	gettimeofday(core.start, NULL);
	//TEST
	pthread_t	*ths;
	ths = (pthread_t *) malloc(sizeof(pthread_t) * core.n_philo);
	for (int i = 0; i < core.n_philo; i++)
	{
		if (pthread_create(ths + i, NULL, &ft_routine, philos + i) != 0)
			return (ft_puterror("Failed created thread\n", -1));
	}
	core.ready = 1;
	for (int i = 0; i < core.n_philo; i++)
	{
		if (pthread_join(ths[i], NULL) != 0)
			return (ft_puterror("Failed join thread\n", -1));
	}
	// END TEST
	ft_destroy_forks(forks, core.n_philo);
	ft_clear_core(&core);	
	free(forks);
	free(philos);
	free(ths);
	return (0);
}
