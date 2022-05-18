/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/05/18 16:29:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

# include "struct.h"

# define MAX_DIGIT_INT	10
# define INT_MAX		2147483647

/**
 * It checks if all args are positif integer.
 * If true each args are parse to integer in attributes of core and return 1.
 * Otherwise return 0.
 */
int	ft_check_input(char *args[], int n_args, t_core *core);

#endif
