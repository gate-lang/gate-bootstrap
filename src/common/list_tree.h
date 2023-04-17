/*
 * file: src/common/list_tree.h
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

#ifndef __GATE_LIST_TREE_H__
#define __GATE_LIST_TREE_H__

#include "../base.h"
#include "linked_list.h"

struct g_dslt_node {
  void *data;
  struct g_dsll *children;
};

struct g_dslt {
  struct g_dslt_node head;
  unsigned short node_count;
};

/*
 * Creates an empty list tree and returns it.
 */
struct g_dslt *g_alloc_dslt();

/*
 * Frees given _dslt.
 * Recurses itself, by freeing the last child each recursion.
 */
void g_free_dslt(struct g_dslt *_dslt, bool _should_free_data);

/*
 * Inserts a new dslt node based on _parent.
 */
struct g_dslt_node *g_insert_dslt_node_by_parent(struct g_dslt *_dslt,
                                                 struct g_dslt_node *_parent,
                                                 void *_data,
                                                 unsigned short _capacity);

#endif // __GATE_LIST_TREE_H__
