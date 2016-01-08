/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include <stdio.h>
#include "include.h" 
#include "artoo.h"
#include "R2Window.h"

void init();
void run();
void kill();
void init_colors();
void handleKey(int c, R2Point* p);

int main(int argc, char** argv)
{
  //init();
 // run();
 // kill();
  initscr();
  cbreak();
  noecho();
  
  R2Window* mywin = R2Window_new(0,0,0,0,BT_SOLID);
  
  wgetch(mywin->window);
  endwin();
  return 0;
}

void init()
{
  initscr();
  cbreak();
  noecho();
  scrollok(stdscr, TRUE);
  keypad(stdscr, TRUE);
  refresh();
  init_colors();
}

void init_colors()
{
  if (has_colors() && !R2_SHOULD_NOT_USE_COLORS)
  {
    start_color();
  }
}

void run()
{
  while(1)
  {
    refresh();
    int c = getch();

    if (!R2_SHOULD_NOT_USE_COLORS)
      attrset(COLOR_PAIR(rand() % 2));
    
    R2Point point;
    getyx(stdscr, point.y, point.x);
 
    if (has_key(c))  	
    {
      handleKey(c, &point);
      move(point.y, point.x);
      continue;
    }
    else if (c == R2_BACKSPACE)
    {
      mvdelch(point.y, point.x - 1);
      continue;
    }
     
     addch(c);
  }
}

void handleKey(int c, R2Point* p)
{
  switch(c)
  {
    case KEY_LEFT:
    {
      p->x -= p->x > 0 ? 1 : 0;
      break;
    } 
    case KEY_RIGHT:
    {
      p->x += p->x < COLS ? 1 : 0;
      break;
    }
    case KEY_UP:
    {
      p->y -= p->y > 0 ? 1 : 0;
      break;
    }
    case KEY_DOWN:
    {
      p->y += p->y < LINES ? 1 : 0;
      break;
    }
  }
}

void kill()
{
  endwin();
}
