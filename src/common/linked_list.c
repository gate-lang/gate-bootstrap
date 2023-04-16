/*
 * file: src/common/linked_list.c
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

#include "linked_list.h"

struct g_dsll *g_alloc_dsll(unsigned short _capacity, bool _fill) {
  struct g_dsll *new_dsll = (struct g_dsll *)calloc(1, sizeof(struct g_dsll *));
  if (!new_dsll) {
    log_error("CORE -- failed to allocate memory for new dsll");

    return NULL;
  }

  new_dsll->capacity = _capacity;
  new_dsll->length = 0;

  if (!_fill) {
    goto not_filling;
  }

  struct g_dsll_node *current_node = new_dsll->head.next;
  for (unsigned short i = 0; i < _capacity; ++i) {
    if (!current_node) {
      log_warn("CORE -- failed to fill new dsll. Stopped at %d", i);

      break;
    }

    struct g_dsll_node *new_inserted_node =
        g_insert_dsll_node_by_last(new_dsll, current_node, NULL);

    current_node = current_node->next;
  }

not_filling:
  return new_dsll;
}

struct g_dsll_node *g_insert_dsll_node(struct g_dsll *_dsll, void *_data,
                                       unsigned short _index) {
  if (!_dsll || !_data) {
    log_error("CORE -- given params were'n initialized");

    return NULL;
  } else if (g_is_dsll_full(_dsll, true)) {
    return NULL;
  }

  _index = (_index > _dsll->capacity) ? _index : _dsll->capacity;
  struct g_dsll_node *last_node = &_dsll->head;
  for (unsigned short i = 0; i <= _index; ++i) {
    if (!last_node) {
      log_warn("CORE -- failed to iterate dsll for insertion, at node %d", i);

      break;
    }

    last_node = last_node->next;
  }

  struct g_dsll_node *new_node =
      g_insert_dsll_node_by_last(_dsll, last_node, _data);
  if (!new_node) {
    return NULL;
  }

  return new_node;
}

struct g_dsll_node *g_insert_dsll_node_by_last(struct g_dsll *_dsll,
                                               struct g_dsll_node *_last_node,
                                               void *_data) {
  if (!_dsll || !_last_node || !_data) {
    log_error("CORE -- given params were'n initialized");

    return NULL;
  } else if (g_is_dsll_full(_dsll, true)) {
    return NULL;
  }

  struct g_dsll_node *new_node =
      (struct g_dsll_node *)malloc(sizeof(struct g_dsll_node *));
  if (!new_node) {
    log_error("CORE -- failed to allocate memory for new dsll node");

    return NULL;
  }
  new_node->data = _data;

  if (_last_node->next) {
    new_node->next = _last_node->next;
  }
  _last_node->next = new_node;

  ++_dsll->length;

  return new_node;
}

void g_free_dsll(struct g_dsll *_dsll, bool _should_free_data) {
  if (!_dsll) {
    log_error("CORE -- given params weren't initialized");

    return;
  }

  struct g_dsll_node *current_node = _dsll->head.next, *next_node;
  while (current_node) {
    next_node = current_node->next;

    if (_should_free_data) {
      free(current_node->data);
    }
    free(current_node);

    current_node = next_node;
  }

  free(_dsll);
}

unsigned short g_is_dsll_full(struct g_dsll *_dsll, bool _verbose) {
  if (!_dsll) {
    log_error("CORE -- given params were'n initialized");

    return 0;
  }

  unsigned short remaining_nodes = _dsll->capacity - _dsll->length;
  if (_verbose && remaining_nodes == 0) {
    log_warn("CORE -- dsll overflow");
  }

  return remaining_nodes;
}
