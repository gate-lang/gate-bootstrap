/*
 * file: src/util/args.c
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

#include "args.h"
#include <argp.h>

const char *argp_program_version = "gate 0.1-beta";
const char *argp_program_bug_address = "<teodoro.josue@pm.me>";

/*
 * Checks and returns whether current arg type conflicts with
 * probable _other or not.
 */
inline static bool has_opposing_arg_type(enum g_arg_type _cur,
                                         enum g_arg_type _other) {
  bool is_conflict = (_cur == _other);
  if (is_conflict) {
    log_error("both -r (RUN) and -b (BUILD) flags were passed.");
  }

  return is_conflict;
}

static error_t argp_parser(int _key, char *_argv, struct argp_state *_state) {
  struct g_args *args = (struct g_args *)_state->input;

  switch (_key) {
  case 'r':
    if (has_opposing_arg_type(args->type, G_ARGT_BUILD)) {
      return 0;
    }
    args->type = G_ARGT_RUN;

    break;
  case 'b':
    if (has_opposing_arg_type(args->type, G_ARGT_RUN)) {
      return 0;
    }
    args->type = G_ARGT_BUILD;
    args->bin_folder = _argv;

    break;
  case ARGP_KEY_ARG:
    if (_state->arg_num > 0) {
      argp_usage(_state);
    }

    args->proj_folder = _argv;

    break;
  default:
    return ARGP_ERR_UNKNOWN;

    break;
  }

  return 0;
}

const static struct argp_option argp_options[] = {
    {"run", 'r', 0, 0, "Run project"},
    {"build", 'b', "BINFOLDER", 0, "Build project"},
    {0}};
const static char argp_args_doc[] = "PROJFOLDER";
const static char argp_doc[] = "gate -- Bootstrap compiler for the gate lang";
const static struct argp argp_settings = {argp_options, argp_parser,
                                          argp_args_doc, argp_doc};

struct g_args *g_parse_args(int _argc, char **_argv) {
  if (_argc < 2) {
    log_warn("not enough arguments. use `%s --help or --usage`.", _argv[0]);

    return NULL;
  }

  struct g_args *parsed_args = malloc(sizeof(struct g_args));
  if (!parsed_args) {
    log_error("failed to allocate memory for g_args");

    return NULL;
  }

  parsed_args->type = 0;
  error_t err = argp_parse(&argp_settings, _argc, _argv, 0, 0, parsed_args);
  if (err != 0) {
    log_error("could not parse arguments -- %d", err);

    free(parsed_args);
    return NULL;
  }

  return parsed_args;
}
