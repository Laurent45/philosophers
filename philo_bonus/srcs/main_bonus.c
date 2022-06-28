/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:42 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 10:08:47 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input_bonus.h"
#include "philo_bonus.h"
#include "error_bonus.h"
#include "semaphore_bonus.h"

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

static void	ft_child_process(t_core *core, int id)
{
	pthread_t	th;
	int			ret;

	core->id = id;
	ret = 0;
	if (pthread_create(&th, NULL, ft_philo_life, (void *) core) != 0)
		ret = ft_puterror("Failed created thread\n", 1);
	if (pthread_join(th, NULL) != 0)
		ret = ft_puterror("Failed join thread\n", 1);
	exit(ft_close_sems(core, ret));
}

static void	ft_create_philo(t_core *core)
{
	int	i;
	int	id;

	i = 0;
	while (i < core->n_philo)
	{
		id = fork();
		if (id == -1)
		{
			ft_close_sems(core, 0);
			ft_puterror("Fork failed\n", 1);
			kill(0, SIGTERM);
		}
		if (id == 0)
			ft_child_process(core, i + 1);
		i++;
	}
	i = 0;
	while (i < core->n_philo)
	{
		sem_post(core->sem_sync);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_core	core;
	int		i;
	int		wstatus;

	if (argc != 6 && argc != 5)
		return (ft_puterror("Usage: you should put 4 or 5 args\n", -1));
	if (ft_check_input(argv + 1, argc - 1, &core) == 0)
		return (ft_puterror("Args must be interger positive value\n", -1));
	if (ft_init_sems(&core) == 0)
		return (ft_puterror("Init semaphore failed\n", -1));
	ft_create_philo(&core);
	i = 0;
	while (i < core.n_philo)
	{
		waitpid(-1, &wstatus, 0);
		if (WEXITSTATUS(wstatus) == 1)
		{
			ft_close_sems(&core, 0);
			ft_puterror("fork failed", 1);
			kill(0, SIGTERM);
		}
		i++;
	}
	ft_close_sems(&core, 0);
	return (0);
}
