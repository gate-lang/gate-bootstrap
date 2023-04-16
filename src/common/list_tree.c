/*
 * file: src/common/list_tree.c
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

#include "list_tree.h"

struct g_dslt *g_alloc_dslt(unsigned short _capacity) {
  struct g_dslt *new_dslt = calloc(1, sizeof(struct g_dslt *));
  if (!new_dslt) {
    log_error("CORE -- failed to allocate memory for new dslt");

    return NULL;
  }

  new_dslt->head.data = NULL;
  new_dslt->head.capacity = _capacity;
  new_dslt->head.length = 0;
  new_dslt->node_count = 1;

  return new_dslt;
}

struct g_dslt_node *g_insert_dslt_node(struct g_dslt *_dslt,
                                       struct g_dslt_node *_parent_node,
                                       void *_data, unsigned short _capacity) {
  if (!_dslt || !_parent_node || _data) {
    log_error("CORE -- given params weren't initialized");

    return NULL;
  }

  // TODO(JosueTM): Finish implementation
  struct g_dslt_node *new_node = (_parent_node + 1);
  new_node->children = calloc(_capacity, sizeof(struct g_dlst_node *));
  if (!new_node->children) {
  }

  return new_node;
}
