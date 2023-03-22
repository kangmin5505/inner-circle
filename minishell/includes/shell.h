/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/10 11:48:10 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "structure.h"

/* set_shell.c */
void	un_register_signal(void);
void	register_signal(void);
void	sig_handler(int signo);
void	exit_shell(int status);

/* set_shell_tcattr.c */
void	set_tcattr(void);
void	unset_tcattr(void);

/* read_shell.c */
void	get_shell_name(char *shell_name);
char	*readline_shell(void);
void	add_history_shell(const char *line);

#endif
