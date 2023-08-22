/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:13:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 15:40:13 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*A del*/
void	print_forks(t_philo *philo)
{
	int i;

	i = 0;
	while (++i < philo->data->nb_philo)
	{
		printf("Philo %d left fork : %d\n", philo[i].id, *(philo[i].left_fork));
		printf("Philo %d addresse left fork : %p\n", philo[i].id, philo[i].left_fork);
		printf("Philo %d addresse right fork : %p\n", philo[i - 1].id, &(philo[i - 1].right_fork));
	}
}


int	exec(t_philo *philo, t_data *data)
{
	int	i;
	
	i = -1;
	pthread_mutex_lock(&(data->launcher));
	if (gettimeofday(&(data->time_start), NULL) != 0)
		return (printf("Error when getting time\n"), -1);
	while (++i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, (void *)routine, &(philo[i])) != 0)
		{
			perror("Failed to create the thread");
			return (-1);
		}
	}
	pthread_mutex_unlock(&(data->launcher));
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0) 
		{
			perror("Failed to join threads");
            return (-1);
		}
	}
	return (0);
}
