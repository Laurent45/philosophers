/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:54:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:25:11 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_BONUS_H
# define TIME_BONUS_H

# include <sys/time.h>

/**
 * It returns the difference between start and current time on ms.
 */
long	ft_time(struct timeval *start);

#endif
