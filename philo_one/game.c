/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:51:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/16 11:00:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	game_start(void)
{
	game_intro();
	return ;
}

void	game_intro(void)
{
	printf("\nGame starts: 3 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b2 ");
	fflush(stdout);
	sleep(1);
	printf("\b\b1 ");
	fflush(stdout);
	sleep(1);
	printf("\b\bnow! ");
	fflush(stdout);
	sleep(1);
	return ;
}
