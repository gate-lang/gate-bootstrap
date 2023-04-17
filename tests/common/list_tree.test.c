/*
 * file: tests/common/list_tree.test.c
 * author: Josue Teodoro Moreira (J0sueTM) <teodoro.josue@pm.me>
 * date: 16 Apr, 2023
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

#include "../../src/common/list_tree.h"
#include "../base.h"

int res, failed, cur_res = 0;

int g_test_alloc_dslt() { return 0; }
int g_test_free_dslt() { return 0; }
int g_test_insert_dslt_node_by_parent() { return 0; }

int main(void) {
  G_TEST(g_test_alloc_dslt);
  G_TEST(g_test_free_dslt);
  G_TEST(g_test_insert_dslt_node_by_parent);

  return res;
}
