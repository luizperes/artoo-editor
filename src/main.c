#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "main.h"

void init();
void run();
void kill();
void init_colors();
void handleKey(int c, R2Point* p);

int main(int argc, char** argv)
{
  init();
  run();
  kill();

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
