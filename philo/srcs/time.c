/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 17:53:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

long	ft_get_time_ms(struct timeval *start, struct timeval *end)
{
	long	s;
	long	us;

	s = end->tv_sec - start->tv_sec;
	us = end->tv_usec - start->tv_usec;
	return ((s * 100) + (us / 100));
}
