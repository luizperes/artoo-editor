/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "include.h" 
#include "R2Settings.h"
#include "R2WindowManager.h"

int main(int argc, char **argv)
{
  if(R2Settings_init(argc, argv))
    R2WindowManager_run();

  return 0;
}
