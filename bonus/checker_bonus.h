/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:56:55 by alouriga          #+#    #+#             */
/*   Updated: 2024/05/10 14:54:07 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				cost;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_memslot
{
	void				*addr;
	struct s_memslot	*next;
}				t_slot;

typedef struct s_memslotlist
{
	t_slot	*head;
	t_slot	*last;
}				t_slotlist;

void		*ft_malloc(t_slotlist *slots, size_t size);
void		close_session(t_slotlist **slots);
t_slotlist	*start_session(void);
int			cheak(t_slotlist *slots, int argc, char *argv[], t_stack **stack_a);
int			sign(char **arr);
int			same_nb(char **arr1);
int			sort_nb(char **arr2);
char		*ft_strjoin(t_slotlist *slots, int argc, char *argv[]);
int			over_flow(char **arr3);
char		**ft_split(t_slotlist *slots, char *s, char c);
void		exiting(t_slotlist *slots);
long		ft_atoi(const char *str);
void		add_to_stacka(t_stack **stack_a, char **p, t_slotlist *slots);
t_stack		*ft_lstnew(int content, t_slotlist *slots);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
void		pb(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
int			nb_of_nodes(t_stack *stack);
void		sort_p_nm(t_stack **stack_a, t_stack **stack_b);
void		cost_stack(t_stack **stack);
void		get_position(t_stack *stack, int k);
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
int			ft_strchr(char *s, int c);
char		*ft_strjoinn(char *s1, char *s2);
void		*ft_free(char *reach);
int			ft_strcmp(char *s1, char *s2);
int			sort_stack(t_stack **a);

#endif