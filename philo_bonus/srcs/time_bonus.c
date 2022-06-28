/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:40:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_bonus.h"
#include <stddef.h>

long	ft_time(struct timeval *start)
{
	struct timeval	end;
	long			s;
	long			us;
	int				r;

	gettimeofday(&end, NULL);
	r = 0;
	if (end.tv_usec < start->tv_usec)
	{
		us = (end.tv_usec + (1000000 - start->tv_usec)) / 1000;
		r = 1;
	}
	else
		us = (end.tv_usec - start->tv_usec) / 1000;
	s = ((end.tv_sec - start->tv_sec - r) * 1000);
	return (s + us);
}
