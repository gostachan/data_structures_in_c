/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisaki <hmisaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:02:08 by hmisaki           #+#    #+#             */
/*   Updated: 2025/03/20 12:02:08 by hmisaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_H
# define HASH_SET_H

# include <stdbool.h>
# include <stdlib.h>
# define TABLE_SIZE 1024

typedef struct NodeHS
{
	int				value;
	struct NodeHS	*next;
	struct NodeHS	*prev;
}					t_NodeHS;

typedef struct t_HashSet
{
	t_NodeHS		*table[TABLE_SIZE];
}					t_HashSet;

void				init_hs(t_HashSet *set);
t_NodeHS			*new_node_hs(t_NodeHS *next, t_NodeHS *prev, int value);
bool				contains_hs(t_HashSet *set, int value);
bool				add_hs(t_HashSet *set, int value);
void				remove_hs(t_HashSet *set, int value);
void				free_hs(t_HashSet *set);

#endif // HASH_SET_H
