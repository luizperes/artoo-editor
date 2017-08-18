/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#include "R2Settings.h"

#define R2Settings_VERSION "Artoo version 0.9"
#define R2Settings_HELP_OPTION "Use the identifier '--help' for getting information about the settings"
#define R2Settings_PATTERN "Please execute Artoo with the command: artoo filename"

#define R2Settings_WRONG_PARAM "Wrong parameter '%s'"
#define R2Settings_HELP_ENABLE_COLORS "--enable-colors\t\tEnable the use of colors by the terminal\n"
#define R2Settings_HELP_DISABLE_COLORS "--disable-colors\tDisable the use of colors by the terminal\n"

#define R2Settings_FULL_HELP R2Settings_HELP_ENABLE_COLORS  R2Settings_HELP_DISABLE_COLORS 

static char* R2Settings_getVersion();
static char* R2Settings_getHelpOption();
static char* R2Settings_getHintAboutInitFile();
static char* R2Settings_getFullHelp();
static char* R2Settings_getWrongParams(char *param);
static bool  R2Settings_handleArgs(int argc, char **argv);

// "R2Settings.h"
bool R2_SHOULD_NOT_USE_COLORS = false;
char *R2_FILE_NAME;

bool R2Settings_init(int argc, char **argv)
{
  if (argc == 1)
  {
    printf("%s. %s\n%s\n", R2Settings_getVersion(), R2Settings_getHintAboutInitFile(),  R2Settings_getHelpOption());
    return false;
  }
  else 
  {
    return R2Settings_handleArgs(argc, argv); 
  }

  return true;
}

static bool R2Settings_handleArgs(int argc, char **argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--help") == 0)
    {
      printf("\n%s\n", R2Settings_getFullHelp());
      return false;
    }
    else if (strcmp(argv[i], "--enable-colors") == 0)
    {
      R2_SHOULD_NOT_USE_COLORS = false; 
    }
    else if (strcmp(argv[i], "--disable-colors") == 0)
    {
      R2_SHOULD_NOT_USE_COLORS = true;
    }
    else  if ((strstr(argv[i], "-") != NULL || strstr(argv[i], "--") != NULL) && argv[i][0] != '/')
    { 
      char *formattedStr = R2Settings_getWrongParams(argv[i]);
      printf("%s\n%s\n", formattedStr, R2Settings_getHelpOption());
      free(formattedStr);
      return false;
    }
    else
    {
      R2_FILE_NAME = argv[i];
    }
  } 

  return true;
}

static char* R2Settings_getVersion()
{
  return R2Settings_VERSION;
}

static char* R2Settings_getHelpOption()
{
  return R2Settings_HELP_OPTION;
}

static char* R2Settings_getHintAboutInitFile()
{
  return R2Settings_PATTERN;
}

static char* R2Settings_getFullHelp()
{
  return R2Settings_FULL_HELP;
}

static char* R2Settings_getWrongParams(char *param)
{
  int length = strlen(R2Settings_WRONG_PARAM) -2 + strlen(param);
  char *finalStr = (char *) malloc(sizeof(char) * length);
  sprintf(finalStr, R2Settings_WRONG_PARAM, param);
  return finalStr;
}

void R2Settings_fileCouldNotLoad(char *filename)
{
  printf("File '%s' is unable to load or create\n%s\n", filename, R2Settings_getHelpOption());
}

