/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2Window.h"

static void R2Window_drawBorders(R2Window *this, bool refresh);
static void R2Window_drawDashedBorders(R2Window *this);

R2Window* R2Window_new(int nlines, int ncols, int begin_y, int begin_x, R2Border_Type borderType)
{
  R2Window *this = (R2Window*) malloc(sizeof(R2Window));
  this->borderType = borderType;
  this->window = newwin(nlines, ncols, begin_y, begin_x);
  R2Window_drawBorders(this, true);
  return this;
}

static void R2Window_drawBorders(R2Window *this, bool refresh)
{
  if (this->borderType == BT_SOLID)
      box(this->window, 0, 0);
  else if (this->borderType == BT_DASHED)
      R2Window_drawDashedBorders(this); 

  if (refresh)
    R2Window_refresh(this);
}

static void R2Window_drawDashedBorders(R2Window *this)
{
  int x, y, i;

  R2Window_getMaxYX(this, y, x);

  // 4 corners
  R2Window_gotoYXAndPrint(this, 0, 0, "+");
  R2Window_gotoYXAndPrint(this, y - 1, 0, "+");
  R2Window_gotoYXAndPrint(this, 0, x - 1, "+");
  R2Window_gotoYXAndPrint(this, y - 1, x - 1, "+");

  // sides
  for (i = 1; i < (y - 1); i++)
  {
    R2Window_gotoYXAndPrint(this, i, 0, "|");
    R2Window_gotoYXAndPrint(this, i, x - 1, "|");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++)
  {
    R2Window_gotoYXAndPrint(this, 0, i, "-");
    R2Window_gotoYXAndPrint(this, y - 1, i, "-");
  }
}

void R2Window_resizeAndGotoYX(R2Window *this, int nlines, int ncols, int y, int x)
{
  wresize(this->window, y, x);
  R2Window_move(this, y, x);
  R2Window_clear(this);
  R2Window_drawBorders(this, false);
  wnoutrefresh(this->window);  
}

void R2Window_release(R2Window *this)
{
  delwin(this->window);
  free(this);
}

