/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:21:59 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/08 11:31:17 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**data;

	data = parse_arguments(av, ac);
	if (ft_check_data(data))
		push_swap(data);
	ft_free_data(data);
	return (0);
}
