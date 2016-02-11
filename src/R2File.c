/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2File.h"

bool R2File_loadFile(char *filename)
{
  FILE *f = NULL;

  char *theFile;
  theFile = strrchr(filename, '/');

  if (theFile)
  {
    int size = strlen(filename) - strlen(theFile);
    if (size)
    {
      char *theDirectory = (char *)  malloc(sizeof(char) * size);
      memcpy(theDirectory, filename, size);
      struct stat st = {0};
      if (stat(theDirectory, &st) == -1)
      {
        printf("The directory '%s' does not exist. Please create it\n", theDirectory);
        free(theDirectory);
        return false;
      }
      
      free(theDirectory);
    }
  }
  
  // check if file exists
  if (access(filename, F_OK) != -1)
  {
    printf("file exists");
  }
  else
  {
    printf("File does not exist");
  }

  return f;
}

