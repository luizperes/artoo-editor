/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2File.h"

static bool R2File_isThereValidDirectory(R2File *this);

R2File* R2File_new(char *fileName)
{
  R2File *this = (R2File*) malloc(sizeof(R2File));
  this->fileName = fileName;

  this->swpFileName = (char *) malloc(sizeof(char) * strlen(fileName) + 4);
  this->swpFileName[0] = '.';
  strcat(this->swpFileName, fileName);
  strcat(this->swpFileName, "_r2");

  return this;
}

void R2File_release(R2File* this)
{
  free(this->swpFileName);
  free(this);
}

bool R2File_loadFile(R2File *this)
{
  FILE *f = NULL;

  if (!R2File_isThereValidDirectory(this))
  {
    return false;
  } 
 
  bool fileExists = access(this->fileName, F_OK) != -1;
  bool swpFileExists = access(this->swpFileName, F_OK) != -1;

  if (fileExists && swpFileExists)
  {
    // TODO: ask the user if he wants to work with the previous swap or 
    // delete the swap file.
  }
  else if (!fileExists && swpFileExists)
  {
    // TODO: delete swap and create a new one.
  }
  else if (fileExists && !swpFileExists)
  {
    // TODO: copy file and rename it to the swap one.
  }
  else
  {
    // TODO: create new swap file only.
  }

  this->file = f;
  return f;
}

static bool R2File_isThereValidDirectory(R2File *this)
{
  char *theFile;
  theFile = strrchr(this->fileName, '/');

  if (theFile)
  {
    int size = strlen(this->fileName) - strlen(theFile);
    if (size)
    {
      char *theDirectory = (char *)  malloc(sizeof(char) * size);
      memcpy(theDirectory, this->fileName, size);
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

  return true;
}
