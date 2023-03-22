/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:53:38 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/23 10:48:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	struct sigaction	s_act;

	ft_printf("Server PID : %d\n", getpid());
	s_act.sa_sigaction = &sig_handler;
	sigemptyset(&s_act.sa_mask);
	s_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_act, NULL) == -1 \
		|| sigaction(SIGUSR2, &s_act, NULL) == -1)
	{
		ft_printf("Sigaction Error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		;
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		cnt = 0;
	static int		result = 0;
	static pid_t	client_pid = -1;

	(void)ucontext;
	if (client_pid == -1)
		client_pid = info->si_pid;
	if (client_pid == info->si_pid)
	{
		if (cnt++ < 8)
			bitwise_oper(sig, &result);
		if (cnt == 8)
		{
			if (result == 0)
				last_signal(info, &client_pid);
			else
				ft_printf("%c", result);
			cnt = 0;
			result = 0;
		}
	}
	else
		ctrl_interrupt(info);
}

void	bitwise_oper(int sig, int *result)
{
	if (sig == SIGUSR1)
		*result <<= 1;
	else if (sig == SIGUSR2)
		*result = (*result << 1) + 1;
}

void	last_signal(siginfo_t *info, pid_t *client_pid)
{
	ft_printf("\n");
	usleep(USLEEP_TIME);
	if (kill(info->si_pid, SIGUSR2) == -1)
	{
		ft_printf("Fail to receive a signal\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Success to receive a message from client(PID : %d)\n", \
			*client_pid);
	*client_pid = -1;
}

void	ctrl_interrupt(siginfo_t *info)
{
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("Fail to send a signal to client(PID : %d)\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
}
