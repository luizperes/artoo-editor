#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "main.h"

void init();
void run();
void kill();

void init_colors();

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
  noecho();
  scrollok(stdscr, TRUE);
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
    if (!R2_SHOULD_NOT_USE_COLORS)
      attrset(COLOR_PAIR(rand() % 2));
   
    int curY, curX; 
    getyx(stdscr, curY, curX);
    
    int c = getch();
    if (c == 10)
      addch('\n');
    else if (c == KEY_LEFT)
     return;	
    else if (c >= 32 && c <= 126)
      addch(c);
  }
}

void kill()
{
  endwin();
}
