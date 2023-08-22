/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:09:50 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 13:15:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc, char **args);
static int	convert_args(int argc, char **args, t_data *data);
static int	check_intoverflow(int time);

/*
Check int overflow
*/
static int	check_intoverflow(int time)
{
	if (time > INT_MAX)
	{
		printf("Yeah, that's too long of a time\n");
		return (-1);
	}
	return (0);
}

/*
Check les args
*/
static int	check_args(int argc, char **args)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("You should run this program with 4 to 5 args\n"), -1);
	i = 1;
	while (i < argc)
	{
		if (ft_isstrdigit(args[i]) < 0)
			return (printf("All parameters should be integers you monkey\n"), -1);
		if (ft_strlen(args[i]) > 11)
			return (printf("Yeah, that's too long of a time\n"), -1);
		if (check_intoverflow(ft_atoi(args[i])) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	convert_args(int argc, char **args, t_data *data)
{
	data->nb_philo = ft_atoi(args[1]);
	if (data->nb_philo < 1)
		return (printf("Not enough philosophers to run\n"), -1);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (printf("Can't run with negative arguments\n"), -1);
	if (data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
		printf("Warning : time is low, program might not work as intended\n");
	if (argc == 6)
	{
		data->hungriness = ft_atoi(args[5]);
		if (data->hungriness <= 0)
			return (printf("That's not a lot of meals...\n"), -1);
	}
	else
		data->hungriness = -1;
	data->someone_died = 0;
	data->death_printed = 0;
	if (pthread_mutex_init(&(data->writing), NULL) != 0)
		return (printf("Failed to init a mutex\n"), -1);
		if (pthread_mutex_init(&(data->launcher), NULL) != 0)
		return (printf("Failed to init a mutex\n"), -1);
	return (0);
}


int	parsing(int argc, char **args, t_data *data)
{
	if (check_args(argc, args) < 0)
		return (-1);
	if (convert_args(argc, args, data) < 0)
		return (-1);
	return (0);
}
