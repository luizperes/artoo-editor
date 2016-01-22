/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2Settings.h"

#define R2Settings_VERSION "Artoo version 0.9"
#define R2Settings_HELP_OPTION "Use the identifier '--help' for getting information about the settings"
#define R2Settings_PATTERN "Please execute Artoo with the command: artoo filename"

#define R2Settings_HELP_ENABLE_COLORS "--enable-colors\t\tEnable the use of colors by the terminal\n"
#define R2Settings_HELP_DISABLE_COLORS "--disable-colors\tDisable the use of colors by the terminal\n"

#define R2Settings_FULL_HELP R2Settings_HELP_ENABLE_COLORS  R2Settings_HELP_DISABLE_COLORS 

static char* R2Settings_getVersion();
static char* R2Settings_getHelpOption();
static char* R2Settings_getHintAboutInitFile();
static char* R2Settings_getFullHelp();
static bool  R2Settings_handleArgs(int argc, char **argv);

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
  // "R2Settings.h"
  const bool R2_SHOULD_NOT_USE_COLORS = false;
 
  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "--help") == 0)
    {
      printf("\n%s\n", R2Settings_getFullHelp());
      return false;
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
