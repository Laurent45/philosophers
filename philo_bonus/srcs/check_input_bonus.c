/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/06/28 09:16:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_input_bonus.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static int	ft_cmp_intmax(const char *s)
{
	long	atol;

	atol = ft_atol(s);
	if (atol > INT_MAX)
		return (0);
	return (1);
}

static int	ft_isinteger_pos(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s[0] || (s[0] == '-') || ((s[0] == '+') && !s[1]))
		return (0);
	if (s[0] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		len++;
		i++;
	}
	if (len > MAX_DIGIT_INT)
		return (0);
	if (len < MAX_DIGIT_INT)
		return (1);
	else
		return (ft_cmp_intmax(s));
}

int	ft_check_input(char *args[], int n_args, t_core *core)
{
	int	i;

	i = 0;
	if (n_args == 4)
		core->n_eat = -1;
	while (i < n_args)
	{
		if (!ft_isinteger_pos(args[i]))
			return (0);
		if (i == 0)
			core->n_philo = (int) ft_atol(args[i]);
		else if (i == 1)
			core->t_die = (int) ft_atol(args[i]);
		else if (i == 2)
			core->t_eat = (int) ft_atol(args[i]);
		else if (i == 3)
			core->t_sleep = (int) ft_atol(args[i]);
		else
			core->n_eat = (int) ft_atol(args[i]);
		i++;
	}
	return (1);
}
