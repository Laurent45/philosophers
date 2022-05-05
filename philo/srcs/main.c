/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/05 15:17:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input.h"
#include "philo.h"
#include "fork.h"
#include "error.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_core			core;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (argc != 6)
		return (ft_puterror("Usage: ./philo philo t_die t_eat t_sleep n_eat\n", -1));
	if (!ft_check_input(argv + 1, &core))
		return (ft_puterror("Args must be interger positive value\n", -1));
	if (!ft_create_forks(&forks, core.n_philo))
		return (ft_puterror("Failed while creting forks\n", -1));
	if (!ft_create_philos(&philos, &forks, &core))
		return (ft_puterror("Failed while creating philo\n", -1));

	ft_destroy_forks(forks, core.n_philo);
	ft_clear_philo(&philos, &forks, core.n_philo);
	return (0);
}

