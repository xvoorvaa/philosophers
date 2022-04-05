/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/05 22:46:58 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct s_input {
	int	philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	amount_eat;
}	t_input;

typedef struct s_vars {
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}	t_vars;

typedef struct s_philos {
	int					philo_number;
	int					left_fork;
	int					right_fork;
	int					status;
	t_input				input;
	t_vars				*vars;
	unsigned long long	start_time;
	unsigned long long	end_time;
}	t_philos;

/*
	PHILO
*/

void				start_thread(t_philos *philos);

int					setup_mutex(t_philos *philos);

void				*start(void *arg);

unsigned long long	get_time(void);

/*
	PHASES PHILOS
*/

void				start_think(t_philos *philos);

void				start_sleep(t_philos *philos);

void				start_eat(t_philos *philos);

/*
	UTILS
*/

int					ft_atoi(const char *str);

#endif
