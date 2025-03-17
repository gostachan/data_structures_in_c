/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisaki <hmisaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:16:31 by hmisaki           #+#    #+#             */
/*   Updated: 2025/03/17 16:16:31 by hmisaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET
# define HASH_SET

# include <stdbool.h>
# include <stdlib.h>
# define TABLE_SIZE 1024

typedef struct NodeHS
{
	int				value;
	struct NodeHS	*next;
	struct NodeHS	*prev;
}					NodeHS;

typedef struct
{
	NodeHS			*table[TABLE_SIZE];
}					HashSet;

void				init_hs(HashSet *set);
NodeHS				*new_node_hs(NodeHS *next, NodeHS *prev, int value);
bool				contains_hs(HashSet *set, int value);
bool				add_hs(HashSet *set, int value);
void				remove_hs(HashSet *set, int value);
void				free_hs(HashSet *set);

#endif
