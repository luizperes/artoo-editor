/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#ifndef _R2Synchronizer_H
#define _R2Synchronizer_H

#include "include.h"
#include "R2File.h"
#include "R2Window.h"

typedef struct _R2Synchronizer
{
  R2File *fileObj;
  R2Window *windowObj;
} R2Synchronizer;

R2Synchronizer* R2Synchronizer_new(R2File *fileObj, R2Window *windowObj);
void R2Synchronizer_release(R2Synchronizer* this);

#endif
