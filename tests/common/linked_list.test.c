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
#include "../base.h"

int res, failed, cur_res = 0;

int g_test_alloc_dsll();
int g_test_insert_dsll_node() { return 0; }
int g_test_insert_dsll_node_by_last() { return 0; }
int g_test_free_dsll() { return 0; }
int g_test_is_dsll_full() { return 0; }

int main(void) {
  G_TEST(g_test_alloc_dsll);
  G_TEST(g_test_insert_dsll_node);
  G_TEST(g_test_insert_dsll_node_by_last);
  G_TEST(g_test_free_dsll);
  G_TEST(g_test_is_dsll_full);

  return res;
}

int g_test_alloc_dsll() {
  struct g_dsll *empty_dsll = g_alloc_dsll(10, false);
  G_NEXPECT(empty_dsll, NULL, "empty_dsll wasn't initialized", true);
  G_EXPECT(empty_dsll->capacity, 10, "dsll capacity wasn't initialized", false);
  G_EXPECT(empty_dsll->length, 0, "dsll length wasn't initialized", false);
  if (empty_dsll)
    g_free_dsll(empty_dsll, false);

  // TODO(J0sueTM): Add tests for full dsll
  // struct g_dsll *full_dsll = g_alloc_dsll(10, true);
  // if (!empty_dsll) {
  //   return 1;
  // }

  return cur_res;
}
