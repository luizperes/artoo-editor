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

static char* R2Settings_getVersion();
static char* R2Settings_getHelpOption();
static char* R2Settings_getHintAboutInitFile();

bool R2Settings_init(int argc, char **argv)
{
  if (argc == 1)
  {
    printf("%s. %s\n%s\n", R2Settings_getVersion(), R2Settings_getHintAboutInitFile(),  R2Settings_getHelpOption());
    return false;
  }

  const bool R2_SHOULD_NOT_USE_COLORS = false;
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
