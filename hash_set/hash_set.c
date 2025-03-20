/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisaki <hmisaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:02:08 by hmisaki           #+#    #+#             */
/*   Updated: 2025/03/20 12:02:08 by hmisaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_set.h"

void	init_hs(t_HashSet *set)
{
	int	index;

	index = 0;
	while (index < TABLE_SIZE)
		set->table[index++] = NULL;
}

bool	contains_hs(t_HashSet *set, int value)
{
	t_NodeHS	*target;

	target = set->table[value % TABLE_SIZE];
	while (target && target->value <= value)
	{
		if (target->value == value)
			return (true);
		target = target->next;
	}
	return (false);
}

bool	add_hs(t_HashSet *set, int value)
{
	t_NodeHS	*new;
	t_NodeHS	*target;

	if (contains_hs(set, value))
		return (false);
	new = new_node_hs(NULL, NULL, value);
	if (!new)
		return (false);
	target = set->table[value % TABLE_SIZE];
	if (!target)
	{
		set->table[value % TABLE_SIZE] = new;
		return (true);
	}
	while (target && target->value < value)
		target = target->next;
	new->next = target;
	new->prev = target->prev;
	if (target)
	{
		target->prev->next = new;
		target->prev = new;
	}
	return (true);
}

void	remove_hs(t_HashSet *set, int value)
{
	t_NodeHS	*target;

	target = set->table[value % TABLE_SIZE];
	while (target && target->value != value)
	{
		target = target->next;
	}
	if (!target)
		return ;
	if (target->prev)
		target->prev->next = target->next;
	else
		set->table[value % TABLE_SIZE] = target->next;
	if (target->next)
		target->next->prev = target->prev;
	free(target);
}

void	free_hs(t_HashSet *set)
{
	int	index;

	index = 0;
	while (index < TABLE_SIZE)
	{
		while (set->table[index])
			remove_hs(set, set->table[index]->value);
		index++;
	}
}
