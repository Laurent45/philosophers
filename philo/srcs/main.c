/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/04 15:09:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input.h"
#include "error.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_core core;

	if (argc != 6)
		return (ft_puterror("Usage: ./philo philo t_die t_eat t_sleep n_eat\n"));
	if (!ft_check_input(argv + 1, &core))
		return (ft_puterror("Args must be interger positive value\n"));
	printf("core => philo = %d / t_die = %d / t_eat = %d / t_sleep = %d / n_eat = %d\n", core.n_philo, core.t_die, core.t_eat, core.t_sleep, core.n_eat);
	return (0);
}

