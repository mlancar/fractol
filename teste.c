/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:01:41 by malancar          #+#    #+#             */
/*   Updated: 2023/03/22 20:41:20 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	calcul(int max, int inter)
{
	int	nb;
	
	nb = max / inter;
	while(nb <=  max)
	{
		printf("nb = %d\n", nb);
		nb = nb + (max / inter);
	}
}

int	find_color(int max, int inter, int color)
{	
	color = max / inter;
	color = color + (max / inter);
	return (color);
}

int	main(int ac, char ** av)
{
	if (ac == 3)
		calcul(atoi(av[1]), atoi(av[2]));
	else
		return(0);
}