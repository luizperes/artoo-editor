/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#include "R2Synchronizer.h"
#include "R2Util.h"

R2Synchronizer* R2Synchronizer_new(R2File *fileObj, R2Window *windowObj, boolean weak)
{
  R2Synchronizer *this = (R2Synchronizer*) malloc(sizeof(R2Synchronizer));
  this->fileObj   = fileObj;
  this->windowObj = windowObj;
  this->weak      = weak;
  return this;
}

void R2Synchronizer_release(R2Synchronizer* this)
{
  if (!this->weak)
  {
    R2File_release(this->fileObj);
    R2Window_release(this->windowObj);
  }

  free(this);
}

