/*
 * file: src/common/linked_list.h
 * author: Josue Teodoro Moreira (J0sueTM) <teodoro.josue@pm.me>
 * date: 15 Apr, 2023
 *
 * Copyright (C) Josue Teodoro Moreira
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GATE_LINKED_LIST_H__
#define __GATE_LINKED_LIST_H__

#include "../base.h"

struct g_dsll_node {
  void *data;
  struct g_dsll_node *next;
};

struct g_dsll {
  struct g_dsll_node head;
  unsigned short capacity, length;
};

/*
 * Creates and returns an empty linked list.
 */
struct g_dsll *g_alloc_dsll(unsigned short _capacity, bool _fill);

/*
 * Creates and inserts a new linked list node based on _index.
 */
struct g_dsll_node *g_insert_dsll_node(struct g_dsll *_dsll, void *_data,
                                       unsigned short _index);

/*
 * Creates and inserts a new linked list node based on brother
 * node _last.
 */
struct g_dsll_node *g_insert_dsll_node_by_last(struct g_dsll *_dsll,
                                               struct g_dsll_node *_last_node,
                                               void *_data);

/*
 * Frees _dsll's nodes, and its data if enabled.
 */
void g_free_dsll(struct g_dsll *_dsll, bool _should_free_data);

/*
 * Returns how many nodes remain based on _dssl's capacity.
 */
unsigned short g_is_dsll_full(struct g_dsll *_dsll, bool _verbose);

#endif // __GATE_LINKED_LIST_H__
