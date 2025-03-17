/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisaki <hmisaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:16:31 by hmisaki           #+#    #+#             */
/*   Updated: 2025/03/17 16:16:31 by hmisaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_set.h"

void	init_hs(HashSet *set)
{
	int	index;

	index = 0;
	while (index < TABLE_SIZE)
		set->table[index++] = NULL;
}

NodeHS	*new_node_hs(NodeHS *next, NodeHS *prev, int value)
{
	NodeHS	*new;

	new = malloc(sizeof(NodeHS));
	new->next = next;
	new->prev = prev;
	new->value = value;
	return (new);
}

bool	contains_hs(HashSet *set, int value)
{
	NodeHS	*target;

	target = set->table[value % TABLE_SIZE];
	while (target && target->value <= value)
	{
		if (target->value == value)
			return (true);
		target = target->next;
	}
	return (false);
}

bool	add_hs(HashSet *set, int value)
{
	NodeHS	*target;
	NodeHS	*prev;
	NodeHS	*new;

	if (contains_hs(set, value))
		return (false);
	new = new_node_hs(NULL, NULL, value);
	if (new == NULL)
		return (false);
	target = set->table[value % TABLE_SIZE];
	prev = NULL;
	while (target && target->value < value)
	{
		prev = target;
		target = target->next;
	}
	if (prev)
	{
		new->prev = prev;
		new->next = prev->next;
		if (new->next)
			new->next->prev = new;
		prev->next = new;
	}
	else
	{
		new->next = set->table[value % TABLE_SIZE];
		set->table[value % TABLE_SIZE] = new;
	}
	return (true);
}

void	remove_hs(HashSet *set, int value)
{
	NodeHS	*target;

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

void	free_hs(HashSet *set)
{
	int		index;
	NodeHS	*target;

	index = 0;
	while (index < TABLE_SIZE)
	{
		while (set->table[index])
			remove_hs(set, set->table[index]->value);
		index++;
	}
}
