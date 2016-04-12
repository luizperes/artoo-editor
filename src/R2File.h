/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef _R2File_H
#define _R2File_H

#include "include.h"

typedef struct _R2File
{
  FILE *file;
  char *fileName;
  char *swpFileName;
} R2File;

R2File* R2File_new(char *filename);
void R2File_release(R2File* this);

bool R2File_loadFile(R2File* this);
void R2File_saveFile(R2File* this);

#endif
