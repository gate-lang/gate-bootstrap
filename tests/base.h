/*
 * file: tests/base.h
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

#ifndef __GATE_TESTS_BASE_H__
#define __GATE_TESTS_BASE_H__

#include "../src/base.h"

extern int res;
extern int failed;
extern int cur_res;

#define G_TEST(_func)                                                          \
  failed = _func();                                                            \
  if (failed) {                                                                \
    log_error("TEST -- " #_func " failed");                                    \
  }                                                                            \
  res = (res) ? res : failed;

inline static void g_general_expect(bool _check, char *_ex_msg, char *_msg) {
  if (!_check) {
    return;
  }

  log_error(_ex_msg);
  log_error(_msg);
  cur_res = 1;
}

#define G_EXPECT(_value, _expect, _msg, _ret)                                  \
  g_general_expect(_value != _expect,                                          \
                   "TEST -- expected " #_expect ", but got " #_value,          \
                   "TEST -- " _msg);                                           \
  if (_ret) {                                                                  \
    return cur_res;                                                            \
  }

#define G_NEXPECT(_value, _nexpect, _msg, _ret)                                \
  g_general_expect(_value == _nexpect,                                         \
                   "TEST -- wasn't expecting " #_value " to be " #_nexpect,    \
                   "TEST -- " _msg);                                           \
  if (_ret) {                                                                  \
    return cur_res;                                                            \
  }

#endif // __GATE_TESTS_BASE_H__
