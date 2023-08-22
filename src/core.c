/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:29:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 16:38:11 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	exit_all(t_data *data, t_philo *philo)
// {
	
// }

void	print_action(t_philo *philo, t_data *data, char *str)
{
	int	time;
	
	time = get_time(data->time_start);
	// pthread_mutex_lock(&(data->writing));
	if (data->death_printed)
	{
		pthread_mutex_unlock(&(data->writing));
		return ;
	}
	if (ft_strncmp(str, "fork", 4) == 0)
		printf("%d\t%d\thas taken a %s\n", time, philo->id, str);
	else if (ft_strncmp(str, "died", 4) == 0)
	{
		printf("%d\t%d\t%s\n", time, philo->id, str);
		data->death_printed = 1;
	}
	else
		printf("%d\t%d\tis %s\n", time, philo->id, str);
	// pthread_mutex_unlock(&(data->writing));
}

/*
-1 pour left fork
1 pour right fork
*/
void	take_fork(t_philo *philo, int fork)
{
	if (fork == 1)
	{
		// pthread_mutex_lock(&(philo->mutex_right_fork));
		philo->right_fork = 0;
	}
	else if (fork == -1)
	{
		// pthread_mutex_lock(philo->mutex_left_fork);
		*(philo->left_fork) = 0;
	}
	philo->nb_fork += 1;
	print_action(philo, philo->data, "fork");
}

void	release_forks(t_philo *philo)
{
	philo->right_fork = 1;
	*(philo->left_fork) = 1;
	philo->nb_fork = 0;
	// pthread_mutex_unlock(&(philo->mutex_right_fork));
	// pthread_mutex_unlock(philo->mutex_left_fork);
}

/*
Check tous les philos pour verifier s'ils ont deja mange suffisamment ou pas.
Retourne -1 s'ils ont encore faim et 0 sinon.
*/
int	still_hungry(t_philo *philo, t_data *data)
{
	int	i;

	if (data->hungriness < 0)
		return (-1);
	i = -1;
	while (++i < data->nb_philo)
	{
		if ((philo - philo->id)[i].nb_meal < data->hungriness)
			return (-1);
	}
	return (0);
}

int	check_death(t_philo *philo, t_data *data)
{
	if (get_time(data->time_start) - philo->last_meal > data->time_to_die)
	{
			data->someone_died = 1;
			print_action(philo, data, "died");
	}
	if (data->someone_died)
		return (-1);
	return (0);
}

void	philo_eat(t_philo *philo, t_data *data)
{
	philo->start_eat = get_time(data->time_start);
	print_action(philo, data, "eating");
	while (get_time(data->time_start) - philo->start_eat < data->time_to_eat)
	{
		if (check_death(philo, data))
			break ; //exit_all
	}
	philo->nb_meal += 1;
	philo->last_meal = get_time(data->time_start);
}

void	philo_sleep(t_philo *philo, t_data *data)
{
	philo->start_sleep = get_time(data->time_start);
	print_action(philo, data, "sleeping");
	while (get_time(data->time_start) - philo->start_sleep < data->time_to_sleep)
	{
		if (check_death(philo, data))
			break ; // exit_all
	}
}

void	philo_think(t_philo *philo, t_data *data)
{
	print_action(philo, data, "thinking");
}

/*
If they have to think at the beginning, add a var state, init to -1 and if this var is = -1 just think.
*/
int	routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->launcher));
	pthread_mutex_unlock(&(philo->data->launcher));
	philo_think(philo, philo->data);
	if ((philo->id) % 2 == 0)
		usleep(20000);
	while (1 && still_hungry(philo, philo->data))
	{
		if (philo->right_fork)
		{
			// printf("right\n");
			take_fork(philo, 1);
		}
		if (*(philo->left_fork))
		{
			// printf("left\n");
			take_fork(philo, -1);
		}
		// if (check_death(philo, philo->data))
		// 	break ;
		if (philo->nb_fork == 2)
		{
			philo_eat(philo, philo->data);
			release_forks(philo);
			philo_sleep(philo, philo->data);
			philo_think(philo, philo->data);
		}
	}
	return (0);
}
