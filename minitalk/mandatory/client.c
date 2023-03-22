/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:52:11 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/23 10:31:02 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	struct sigaction	s_act;

	if (argc != 3)
	{
		ft_printf("usage: %s [server PID] [string]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	s_act.sa_sigaction = &sig_handler;
	sigemptyset(&s_act.sa_mask);
	s_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_act, NULL) == -1 || \
			sigaction(SIGUSR2, &s_act, NULL) == -1)
	{
		ft_printf("Sigaction Error\n");
		exit(EXIT_FAILURE);
	}
	if (send_str((pid_t)ft_atoi(argv[1]), argv[2]) == false)
	{
		ft_printf("Fail to send signal to a process\n");
		exit(EXIT_FAILURE);
	}
	pause();
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	pid_t	server_pid;

	(void)ucontext;
	server_pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		ft_printf("Fail to send a message to server(PID : %d)\n", server_pid);
		ft_printf("After a few seconds, retry again\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGUSR2)
		ft_printf("Success to send a message to server(PID : %d)\n", server_pid);
}

bool	send_str(pid_t pid, char *s)
{
	int	c;

	while (*s)
	{
		c = (int)*s;
		if (send_signal(pid, c) == false)
			return (false);
		s++;
	}
	if (send_signal(pid, '\0') == false)
		return (false);
	return (true);
}

bool	send_signal(pid_t pid, int c)
{
	int	bit_cnt;
	int	bit_mask;

	bit_cnt = 0;
	bit_mask = 128;
	while (bit_cnt < 8)
	{
		if ((c & bit_mask) != 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (false);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (false);
		}
		bit_mask >>= 1;
		bit_cnt++;
		usleep(USLEEP_TIME);
	}
	return (true);
}
