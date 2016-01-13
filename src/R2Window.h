/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef _R2Window_H
#define _R2Window_H

#include "include.h"

#define R2Window_getBegYX(_this, _y, _x) getbegyx(_this->window, _y, _x)
#define R2Window_getCursorYX(_this, _y, _x) getyx(_this->window, _y, _x)
#define R2Window_getMaxYX(_this, _y, _x) getmaxyx(_this->window, _y, _x)
#define R2Window_keypad(_this, _enabled) keypad(_this->window, _enabled)
#define R2Window_refresh(_this) wrefresh(_this->window)
#define R2Window_gotoYXAndPrint(_this, _y, _x, _str) mvwprintw(_this->window, _y, _x, _str) 
#define R2Window_clear(_this) wclear(_this)

typedef enum _R2Border_Type
{
  BT_NONE,
  BT_DASHED,
  BT_SOLID,
}R2Border_Type;

typedef struct _R2Window
{
  WINDOW *window;
  R2Border_Type borderType;
} R2Window;

R2Window* R2Window_new(int nlines, int ncols, int begin_y, int begin_x, R2Border_Type borderType);
void R2Window_release(R2Window *this);

#endif
