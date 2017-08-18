/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016~2017.
 */

#include "R2Util.h"

bool R2Util_confirmationDialog(char *msg)
{
  char answer;

  do
  {
    printf("%s [Y/n] ", msg);
    scanf("%c", &answer);
    
    answer = tolower(answer);
    if(answer == 'y' || answer == 'n')
    {
      break;
    }
    
    printf("\n");
  }while(true);

  return answer == 'y';
}
