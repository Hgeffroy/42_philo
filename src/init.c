/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:18:30 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 14:01:06 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_onephilo(t_philo *philo, t_philo *l_philo, t_data *data, int i);

// left philo = NULL si on est sur le premier philo au premier passage.
static int	init_onephilo(t_philo *philo, t_philo *l_philo, t_data *data, int i)
{
	philo->id = i;
	philo->last_meal = 0;
	philo->nb_meal = 0;
	if (pthread_mutex_init(&(philo->mutex_right_fork), NULL) != 0)
		return (printf("Failed to init a mutex\n"), -1);
	philo->right_fork = 1;
	if (l_philo)
	{
		philo->mutex_left_fork = &(l_philo->mutex_right_fork);
		philo->left_fork = &(l_philo->right_fork);
	}
	philo->data = data;
	philo->nb_fork = 0;
	return (0);
}

t_philo	*init_allphilo(t_data *data)
{
	int		i;
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (free(data), NULL);
	if (init_onephilo(&philo[0], NULL, data, 0) != 0)
		return (free(data), /*free_mutex(philo, 1), */free(philo), NULL);
	i = 0;
	while (++i < data->nb_philo)
	{
		if (init_onephilo(&philo[i], &philo[i - 1], data, i) != 0)
			return (free(data), /*free_mutex(philo, i), */free(philo), NULL);
	}
	philo[0].mutex_left_fork = &(philo[i - 1].mutex_right_fork);
	philo[0].left_fork = &(philo[i - 1].right_fork);
	return (philo);
}
