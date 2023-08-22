/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:11:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 14:00:44 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_philo t_philo;

typedef struct s_data
{
	t_philo			*philo;
	struct timeval	time_start;
	int 			nb_philo;
	int				time_to_eat;
	int 			time_to_sleep;
	int				time_to_die;
	int				hungriness;
	int				someone_died;
	int				death_printed;
	pthread_mutex_t writing;
	pthread_mutex_t	launcher;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				start_eat;
	int				start_sleep;
	int				nb_meal;
	pthread_t		thread;
	int				*left_fork; // 0 si pas dispo 1 si dispo
	pthread_mutex_t *mutex_left_fork;
	int				right_fork; // 0 si pas dispo 1 sinon
	pthread_mutex_t	mutex_right_fork;
	int				nb_fork;
	t_data			*data;
}	t_philo; //Faut-il redonner les times ?

#endif