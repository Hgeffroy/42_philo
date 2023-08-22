/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:33:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/24 10:45:55 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isstrdigit(char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (-1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] != 0)
			i++;
		else
			return (-1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}
