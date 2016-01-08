#include <stdbool.h>

#define CREATE_COLOR(A, B) init_pair(A, B, COLOR_BLACK)
#define R2_BACKSPACE 127

typedef struct
{
  int x;
  int y;
}R2Point;


bool R2_SHOULD_NOT_USE_COLORS = true;
