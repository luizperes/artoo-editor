/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2File.h"
#include "R2Util.h"

static bool R2File_isThereValidDirectory(R2File *this);
static bool R2File_copyFile(char* file, char* cpFile);
static bool R2File_fileExists(char* file);

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
  fclose(this->file);
  if (R2File_fileExists(this->swpFileName))
  {
    remove(this->swpFileName);
  }
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
 
  bool fileExists = R2File_fileExists(this->fileName);
  bool swpFileExists = R2File_fileExists(this->swpFileName);
  
  if (fileExists && swpFileExists)
  {
    // ask the user if he wants to work with the previous swap or 
    // delete the swap file.
    if (R2Util_confirmationDialog("A swap file already exists. Do you want to delete it?"))
    {
      remove(this->swpFileName);
    }
  }
  else if (!fileExists && swpFileExists)
  {
    // delete swap and create a new one.
    remove(this->swpFileName); 
  }
  else if (fileExists && !swpFileExists)
  {
    // copy the file to the swap one
    if (!R2File_copyFile(this->fileName, this->swpFileName))
    {
      return false;
    }
  }

  char *swpMode = R2File_fileExists(this->swpFileName) ? "r+" : "w+"; 
  f = fopen(this->swpFileName, swpMode);
  this->file = f;
  return f;
}

void R2File_saveFile(R2File* this, bool isQuitting)
{
  if (isQuitting)
  {
    if(R2File_fileExists(this->fileName))
    {
      remove(this->fileName);
    }
    
    rename(this->swpFileName, this->fileName);
  }
  else
  {
    R2File_copyFile(this->swpFileName, this->fileName);
  }
}

static bool R2File_fileExists(char* file)
{
  return access(file, F_OK) != -1;
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

static bool R2File_copyFile(char* file, char* cpFile)
{
  FILE *f = fopen(file, "r");
  if (f == NULL)
  {
    printf("There was an error trying to read '%s' file.", file);
    return false;
  }

  FILE *fWrite = fopen(cpFile, "w");
  int c = fgetc(f);
  while(c != EOF)
  {
    fputc(c, fWrite);
    c = fgetc(f);
  }

  fclose(f);
  fclose(fWrite);

  return true;
}
