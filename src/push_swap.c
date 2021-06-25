/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:54:19 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/25 09:52:21 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_data_stack(t_vector *stack, char **data)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (data[i])
	{
		number = ft_atoi(data[i]);
		stack->vector_add(stack, &number);
		i++;
		number = 0;
	}
}

int	ft_check_data_is_sorted(t_vector stack)
{
	int	i;
	int	big_number;

	i = 0;
	big_number = 0;
	while (i < stack.used)
	{
		if (big_number > *(int *)stack.vector_get(&stack, i))
			return (1);
		big_number = *(int *)stack.vector_get(&stack, i);
		i++;
	}
	return (0);
}

int	ft_push_median_lowests(t_vector *stack_a, t_vector *stack_b,
		double median)
{
	int	i;
	int	half_stack;

	i = 0;
	half_stack = 0;
	half_stack = stack_a->used / 2;
	while (i < half_stack)
	{
		if ((*(int *)stack_a->vector_get(stack_a, 0) + 0.0) < median)
		{
			ft_push(stack_a, stack_b);
			i++;
		}
		else
			ft_rotate(stack_a);
	}
	return (0);
}

void	ft_sort_stack(t_vector *stack_a, t_vector *stack_b)
{
	double	median;

	median = finding_the_median(stack_a);
	printf("the median = %f \n", median);
	ft_push_median_lowests(stack_a, stack_b, median);

	//ft_sort_stack_a(stack_a);
	ft_check_stack_circular_sorted(stack_b);
	ft_check_stack_circular_sorted(stack_a);

	printf("stack b : ");
	for (int i = 0; i < stack_b->used; i++)
	{
		printf("%d ", *(int *)stack_b->vector_get(stack_b, i));
	}
	printf("stack a:  ");
	for (int i = 0; i < stack_a->used; i++)
	{
		printf("%d ", *(int *)stack_a->vector_get(stack_a, i));
	}
}

void	push_swap(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;

	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	//if (ft_check_data_is_sorted(stack_a))
	//{
	//	for (int i = 0; i < stack_a.used; i++)
	//	{
	//		printf("%d ",*(int *)stack_a.vector_get(&stack_a, i));
	//	}
	//	printf("\n sort: \n");
	//	ft_sort_stack(&stack_a, &stack_b);
	//}
	ft_check_stack_circular_sorted(&stack_a);
	stack_a.vector_free(&stack_a);
	stack_a.vector_free(&stack_b);
}
