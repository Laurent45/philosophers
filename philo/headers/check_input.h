/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/06 18:07:39 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

# include "struct.h"

# define MAX_DIGIT_INT	10
# define INT_MAX		2147483647

/**
 *
 */
int	ft_check_input(char *args[], t_core *core);

#endif
