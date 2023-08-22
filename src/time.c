/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:30:30 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 10:06:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Avoir le temps du programme en ms.
*/
int	get_time(struct timeval start_time)
{
	int				time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		return (printf("Error when getting time\n"), -1);
	time = (tv.tv_sec - start_time.tv_sec) * 1000 + (tv.tv_usec - start_time.tv_usec) / 1000;
	return (time);
}
