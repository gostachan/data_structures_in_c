/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisaki <hmisaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:02:57 by hmisaki           #+#    #+#             */
/*   Updated: 2025/03/20 12:02:57 by hmisaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_set.h"

t_NodeHS	*new_node_hs(t_NodeHS *next, t_NodeHS *prev, int value)
{
	t_NodeHS	*new;

	new = malloc(sizeof(t_NodeHS));
	new->next = next;
	new->prev = prev;
	new->value = value;
	return (new);
}
