/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#include "R2Synchronizer.h"
#include "R2Util.h"

void R2Synchronizer_mirror(R2Window *windowObj, R2File *fileObj)
{
  if (fileObj)
  {
    int ch = 0;
    // don't open nor close file
    while ((ch = getc(fileObj->file)) != EOF)
    {
      int y, x;
      R2Window_getCursorYX(windowObj, y, x);
      R2Window_gotoYXAndPutChar(windowObj, y, x, ch);
    }
  }
}

