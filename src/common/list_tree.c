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

struct g_dslt *g_alloc_dslt() {
  struct g_dslt *new_dslt = (struct g_dslt *)malloc(sizeof(struct g_dslt *));
  if (!new_dslt) {
    log_error("CORE -- failed to allocate memory for new dslt");

    return NULL;
  }
  new_dslt->node_count = 0;
  new_dslt->head.data = NULL;
  new_dslt->head.children = g_alloc_dsll(1, false);
  if (!new_dslt->head.children) {
    free(new_dslt);

    return NULL;
  }
  new_dslt->head.children->head.data = NULL;
  new_dslt->head.children->head.next = NULL;

  return new_dslt;
}

void g_free_dslt(struct g_dslt *_dslt, bool _should_free_data) {
  if (!_dslt) {
    log_error("CORE -- given params weren't initialized");

    return;
  }

  if (!_dslt->head.children) {
    goto skip_empty;
  } else if (!_dslt->head.children->head.next) {
    g_free_dsll(_dslt->head.children, false);

    goto skip_empty;
  }

  struct g_dslt_node *dslt_node;
  void *next_dslt_node = &_dslt->head;
  struct g_dsll_node *dsll_node, *next_dsll_node;
  while (next_dslt_node) {
    dslt_node = (struct g_dslt_node *)next_dslt_node;

    next_dsll_node = dslt_node->children->head.next;
    while (next_dsll_node) {
      dsll_node = next_dsll_node;
      next_dsll_node = next_dsll_node->next;
    }

    next_dslt_node = dsll_node->data;
  }

  if (dslt_node) {
    g_free_dsll(dslt_node->children, true);
  }
  if (_should_free_data && dslt_node->data) {
    free(dslt_node->data);
  }
  free(dslt_node);

skip_empty:
  free(_dslt);
}

struct g_dslt_node *g_insert_dslt_node_by_parent(struct g_dslt *_dslt,
                                                 struct g_dslt_node *_parent,
                                                 void *_data,
                                                 unsigned short _capacity) {
  if (!_dslt || !_parent || !_data) {
    log_error("CORE -- given params weren't initialized");

    return NULL;
  }

  struct g_dslt_node *new_node =
      (struct g_dslt_node *)malloc(sizeof(struct g_dslt_node *));
  if (!new_node) {
    log_error("CORE -- failed to allocate memory for new dslt node");

    return NULL;
  }
  new_node->data = _data;

  new_node->children = g_alloc_dsll(_capacity, false);
  if (!new_node->children) {
    free(new_node);

    return NULL;
  }

  struct g_dsll_node *inserted_dsll_node = g_insert_dsll_node(
      _parent->children, (void *)new_node, _parent->children->length);
  if (!inserted_dsll_node) {
    free(new_node->children);
    free(new_node);

    return NULL;
  }

  ++_dslt->node_count;
  return new_node;
}
