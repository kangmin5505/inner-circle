/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:23:10 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/23 11:57:44 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define USLEEP_TIME 100

/* server */
void	sig_handler(int sig, siginfo_t *info, void *ucontext);
void	bitwise_oper(int sig, int *result);
void	last_signal(siginfo_t *info, pid_t *client_pid);
void	ctrl_interrupt(siginfo_t *info);

/* client */
void	sig_handler(int sig, siginfo_t *info, void *ucontext);
bool	send_str(pid_t pid, char *s);
bool	send_signal(pid_t pid, int c);

/* libftprintf */
int		ft_printf(const char *fmt, ...);
int		ft_atoi(const char *nptr);

#endif
