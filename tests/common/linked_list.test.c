/*
 * file: tests/common/linked_list.test.c
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

#include "../../src/common/linked_list.h"

static int res = 0;

static void g_test(int (*_func)()) {
  int new_res = _func();
  res = (res) ? res : new_res;
}

int g_test_alloc_dsll() { return 0; }
int g_test_insert_dsll_node() { return 0; }
int g_test_insert_dsll_node_by_last() { return 0; }
int g_test_free_dsll() { return 0; }
int g_test_is_dsll_full() { return 0; }

int main(void) {
  g_test(g_test_alloc_dsll);
  g_test(g_test_insert_dsll_node);
  g_test(g_test_insert_dsll_node_by_last);
  g_test(g_test_free_dsll);
  g_test(g_test_is_dsll_full);

  return res;
}
