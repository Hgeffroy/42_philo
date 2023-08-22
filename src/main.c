/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:33:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 09:52:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int argc, char **argv)
// {
// 	t_data	*data;
// 	t_philo	*philo;
	
// 	data = (t_data *)malloc(sizeof(t_data));
// 	if (parsing(argc, argv, data) < 0)
// 		return (-1);
// 	printf("Nb philo : %d\n", data->nb_philo);
// 	printf("Time to die : %d\n", data->time_to_die);
// 	printf("Time to eat : %d\n", data->time_to_eat);
// 	printf("Time to sleep : %d\n", data->time_to_sleep);
// 	printf("Hungriness : %d\n", data->hungriness);
// 	philo = init_allphilo(data);
// 	data->philo = philo;
// 	printf("Hungriness via philo : %d\n", philo[1].data->hungriness);
// 	exec(philo, data);
// 	return(0);
// }

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (parsing(argc, argv, data) < 0) // Mieux de retourner data avec le parsing ?
		return (-1);
	philo = init_allphilo(data);
	if (!philo)
		return (-1);
	data->philo = philo;
	exec(philo, data);
}

// Tester l'init des philos avec un main !!