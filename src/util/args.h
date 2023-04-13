/*
 * file: src/util/args.h
 * author: Josue Teodoro Moreira (J0sueTM) <teodoro.josue@pm.me>
 * date: 12 Apr, 2023
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

#ifndef __GATE_ARGS_H__
#define __GATE_ARGS_H__

#include "../base.h"
#include <argp.h>

enum g_arg_type { G_ARGT_HELP, G_ARGT_VERSION, G_ARGT_RUN, G_ARGT_BUILD };

struct g_args {
  enum g_arg_type type;
  char *proj_folder;
  char *bin_folder;
};

/*
 * Parses given args, checks them and returns the parsed data.
 */
struct g_args *g_parse_args(int _argc, char **_argv);

/*
 * Checks and returns whether parsed _args are valid or not.
 */
bool g_is_args_valid(struct g_args *_args);

#endif // __GATE_ARGS_H__
