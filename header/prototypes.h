/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:10:45 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/25 09:23:13 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "philo.h"
# include "struct.h"

//Parsing
int		parsing(int argc, char **args, t_data *data);
t_philo	*init_allphilo(t_data *data);
// void	free_mutex(t_philo *philo, int nb);
int		get_time(struct timeval start_time);
int		routine(t_philo *philo);
int		exec(t_philo *philo, t_data *data);

//Libft
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isstrdigit(char *str);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif