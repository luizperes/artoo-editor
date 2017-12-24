/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#ifndef _R2Window_H
#define _R2Window_H

#include "include.h"

typedef enum _R2Border_Type
{
  BT_NONE,
  BT_DASHED,
  BT_SOLID,
}R2Border_Type;

typedef struct _R2Window
{
  WINDOW       *window;
  R2Border_Type borderType;
} R2Window;

#define R2Window_getBegYX(_this, _y, _x) getbegyx(_this->window, _y, _x)
#define R2Window_getCursorYX(_this, _y, _x) getyx(_this->window, _y, _x)
#define R2Window_getMaxYX(_this, _y, _x) getmaxyx(_this->window, _y, _x)
#define R2Window_keypad(_this, _enabled) keypad(_this->window, _enabled)
#define R2Window_refresh(_this) wrefresh(_this->window)
#define R2Window_gotoYX(_this, _y, _x) wmove(_this->window, _y, _x)
#define R2Window_gotoYXAndPrint(_this, _y, _x, _str) mvwprintw(_this->window, _y, _x, _str) 
#define R2Window_gotoYXAndPutChar(_this, _y, _x, _ch) mvwaddch(_this->window, _y, _x, _ch)
#define R2Window_move(_this, _y, _x) mvwin(_this->window, _y, _x)
#define R2Window_resize(_this, _nlines, _ncols) R2Window_resizeAndGotoYX(_this, _nlines, _ncols, 0, 0) 
#define R2Window_clear(_this) wclear(_this->window)
#define R2Window_deleteChar(_this) wdelch(_this->window)
#define R2Window_gotoYXAndDeleteChar(_this, _y, _x) mvwdelch(_this->window, _y, _x)

R2Window* R2Window_new(int nlines, int ncols, int begin_y, int begin_x, R2Border_Type borderType);

// After calling the resize function, you should call the function doupdate()
// that belongs to ncurses library, since the method 'wnoutrefresh' is being called 
// other than 'wrefresh'
void R2Window_resizeAndGotoYX(R2Window *this, int nlines, int ncols, int y, int x);

void R2Window_release(R2Window *this);

#endif
