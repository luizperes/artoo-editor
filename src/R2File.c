/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2File.h"

static bool isThereValidDirectory(char *filename);

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

  if (!isThereValidDirectory(this->fileName))
  {
    return false;
  } 
 
  bool fileExists = access(this->fileName, F_OK) != -1;
  bool swpFileExists = access(this->swpFileName, F_OK) != -1;

  // check if file exists
  if (fileExists)
  {
    printf("file exists");
  }
  else
  {
    printf("File does not exist");
  }

  return f;
}

static bool isThereValidDirectory(char *filename)
{
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

  return true;
}
