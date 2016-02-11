/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2File.h"

bool R2File_loadFile(char *filename)
{
  // check if file exists
  if (access(filename, F_OK) != -1)
  {
    printf("file exists");
  }
  else
  {
    printf("File does not exist");
  }

  return false;
}

