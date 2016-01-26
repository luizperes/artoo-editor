/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef _R2Settings_H
#define _R2Settings_H

#include "include.h"

#define R2_CREATE_COLOR(A, B) init_pair(A, B, COLOR_BLACK)
#define R2_BACKSPACE 127

typedef struct
{
  int x;
  int y;
}R2Point;

extern const bool  R2_SHOULD_NOT_USE_COLORS;
extern const char* R2_FILE_NAME;

bool R2Settings_init(int argc, char **argv);

#endif
