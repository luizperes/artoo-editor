/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2Settings.h"
#include "R2File.h"
#include "R2WindowManager.h"
#include "R2Window.h"

#define PARENT stdscr
#define R2WindowManager_getParentWindowMaxYX(_y, _x) getmaxyx(PARENT, _y, _x)
#define R2WindowManager_updateAllWindows() doupdate()
#define SIZE_ROWS_TERMINAL 3
#define EDITOR_WIN_TYPE_BORDER BT_NONE
#define TERMINAL_WIN_TYPE_BORDER BT_NONE 

// This global variables exist because it is necessary when
// we refresh the window through SIGWINCH
R2Window *R2WindowManager_editorWin;
R2Window *R2WindowManager_terminalWin;
R2File   *R2WindowManager_mainFile;

static void R2WindowManager_init();
static void R2WindowManager_reinit();
static void R2WindowManager_deinit();
static void R2WindowManager_resizeHandler(int sig);
static void R2WindowManager_setWindows();

char *R2_FILE_NAME;

void R2WindowManager_run()
{
  R2WindowManager_mainFile = R2File_new(R2_FILE_NAME);
  if (!R2File_loadFile(R2WindowManager_mainFile))
  {
    R2Settings_fileCouldNotLoad(R2_FILE_NAME);
    return;
  }

  R2WindowManager_init();
  R2WindowManager_setWindows();

  while(1)  
  {
  }  

  R2WindowManager_deinit();
}

static void R2WindowManager_setWindows()
{
  R2WindowManager_getParentWindowMaxYX(LINES, COLS);
  
  if (R2WindowManager_editorWin == NULL || R2WindowManager_terminalWin == NULL)
  {
    R2WindowManager_editorWin = R2Window_new(LINES - SIZE_ROWS_TERMINAL, COLS, 0, 0, EDITOR_WIN_TYPE_BORDER);
    R2WindowManager_terminalWin = R2Window_new(SIZE_ROWS_TERMINAL, COLS, LINES - SIZE_ROWS_TERMINAL, 0, TERMINAL_WIN_TYPE_BORDER);
  }
  else
  {
    R2Window_resize(R2WindowManager_editorWin, LINES - SIZE_ROWS_TERMINAL, COLS);
    R2Window_resizeAndGotoYX(R2WindowManager_terminalWin, SIZE_ROWS_TERMINAL, COLS, LINES - SIZE_ROWS_TERMINAL, 0);
  }

  R2WindowManager_updateAllWindows();
}

static void R2WindowManager_init()
{
  initscr();
  cbreak();
  noecho();
  signal(SIGWINCH, R2WindowManager_resizeHandler);

  R2WindowManager_editorWin = NULL;
  R2WindowManager_terminalWin = NULL;
}

// Reinitilize LINES and COLS variables.
static void R2WindowManager_reinit()
{
  endwin();
  initscr();
  clear();
  R2Window_clear(R2WindowManager_editorWin);
  R2Window_clear(R2WindowManager_terminalWin);
  R2Window_refresh(R2WindowManager_editorWin);
  R2Window_refresh(R2WindowManager_terminalWin);
}

static void R2WindowManager_resizeHandler(int sig)
{
  R2WindowManager_reinit();
  R2WindowManager_setWindows();
}

static void R2WindowManager_deinit()
{
  R2Window_release(R2WindowManager_editorWin);
  R2Window_release(R2WindowManager_terminalWin);
  R2File_release(R2WindowManager_mainFile);
  endwin();
}

