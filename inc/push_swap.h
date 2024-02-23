/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:07:37 by nholbroo          #+#    #+#             */
/*   Updated: 2024/02/22 15:44:49 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pushcost;
	int				currpos;
	bool			abovemedian;
	struct s_list	*next;
	struct s_list	*previous;
	struct s_list	*target;
}	t_list;

// Input check:
int			ft_error_one_arg(char *str);
int			ft_error_more_args(char **arr, int argc);
int			ft_one_nbrcheck(char *str);
int			ft_more_nbrcheck(char **argv, int argc);
int			ft_one_dupcheck(char *str);
int			ft_more_dupcheck(char **argv, int argc);
int			ft_one_intrange_check(char **arr, int count);
int			ft_more_intrange_check(char **argv, int argc);

// Standard functions:
long long	ft_atol(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
int			ft_wordcount(char const *s, char c);
int			ft_strchr(char *str, char c);
void		ft_print_operation(char *str);

// Freeing allocated memory:
int			ft_freearray(char **arr, int max);
void		*ft_free(void *ptr);
int			ft_free_stack(t_list *a);

// List-functions:
t_list		*ft_initialize_a(t_list **a, char **argv, int argc, int start);
bool		ft_is_sorted(t_list *stack);
int			ft_stacklen(t_list *stack);
t_list		*ft_last_node(t_list *stack);
t_list		*ft_one_before_last_node(t_list *stack);
t_list		*ft_init_stack_one_arg(char *argv, t_list **a);
void		ft_index_check(t_list **a);

// Sorting-operations:
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a, bool rotate_both);
void		rb(t_list **b, bool rotate_both);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a, bool rotate_both);
void		rrb(t_list **b, bool rotate_both);
void		rrr(t_list **a, t_list **b);

// General sorting-functions:
void		ft_sort(t_list **a, t_list **b);
void		ft_finish_sort(t_list **a);

// Sorting-functions for two, three or four numbers:
void		ft_sort_two_numbers(t_list **a);
void		ft_sort_three_numbers(t_list **a, t_list **b);
void		ft_sort_four_numbers(t_list **a, t_list **b);

// Sorting-functions for five numbers:
void		ft_sort_five_numbers(t_list **a, t_list **b);
void		ft_lowest_is_two_three_or_four(t_list **a, t_list **b, int lowest);
void		ft_lowest_is_zero_or_one(t_list **a, t_list **b, int lowest);
void		ft_seclowest_zero_or_one(t_list **a, t_list **b, int seclowest);
void		ft_seclowest_two_or_three(t_list **a, t_list **b, int seclowest);
int			ft_find_lowest(t_list **a, int lowest);
int			ft_find_seclowest(t_list **a, int seclowest);

// Sorting-functions for larger amount of numbers:
void		ft_sort_x_numbers(t_list **a, t_list **b);
void		ft_init_push_to_b(t_list **a, t_list **b);
void		ft_above_median(t_list **x);
void		ft_node_current_position(t_list **x);
void		ft_median_and_currpos(t_list **a, t_list **b);
void		ft_find_smallest_value_in_a(t_list *b, t_list **a);
void		ft_find_greatest_value_in_b(t_list **b, t_list *a);
void		ft_pushcost_to_a(t_list **a, t_list **b);
void		ft_pushcost_to_b(t_list **a, t_list **b);
int			ft_what_is_lowest_cost(t_list **x);
t_list		*ft_where_is_lowest_cost(t_list **x, int lowestcost);
void		ft_target_node_in_a(t_list **a, t_list **b);
void		ft_target_node_in_b(t_list **a, t_list **b);
void		ft_reset_targets(t_list **x);
void		ft_reset_pushcost(t_list **x);
void		ft_rra_node_is_not_above_median(t_list **head_x, t_list **curr_x);
void		ft_rrb_node_is_not_above_median(t_list **head_x, t_list **curr_x);
void		ft_ra_node_is_above_median(t_list **head_x, t_list **curr_x);
void		ft_rb_node_is_above_median(t_list **head_x, t_list **curr_x);
void		to_a_rr(t_list **a, t_list **b, t_list **curr_x, t_list **target);
void		to_a_rrr(t_list **a, t_list **b, t_list **curr_x, t_list **target);
void		to_b_rr(t_list **a, t_list **b, t_list **curr_x, t_list **target);
void		to_b_rrr(t_list **a, t_list **b, t_list **curr_x, t_list **target);
void		ft_push_to_b(t_list **a, t_list **b, t_list *curr_a);
void		ft_push_to_a(t_list **a, t_list **b, t_list *curr_b);
void		ft_final_rotation(t_list **a);

#endif