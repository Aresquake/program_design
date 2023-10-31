#include <stdio.h>
#define ROWS 8
#define COLS 8
#define IN_BOUND(nx,ny) (nx>=0 && nx<=7 && ny>=0 && ny<=7)


int main(){
  int i, j;
  int x, y;
  int dx,dy;
  int color;
  int s[ROWS][COLS];

  for(i = 0; i < ROWS; i++)
    for(j = 0; j < COLS; j++)
      scanf("%d", &s[i][j]);

  scanf("%d%d", &x, &y);
  scanf("%d", &color);
  
  s[x][y] = color;
  
  switch(s[x][y]){
    case 0:
      printf("empty\n");
      break;
    case 1:
      printf("black\n");
      break;
    case 2:
      printf("white\n");
      break;
  }

  int nx = x+dx;
  int ny = y+dy;

  for(dx=-1; dx<=1; dx++){
    for(dy=-1; dy<=1; dy++){
      
      nx = x+dx;
      ny = y+dy;
      /*if(!(dx == 0 && dy == 0)){
        printf("(%d,%d)", nx, ny);
      }*/

      int move = 1;

      if(s[x][y] != s[nx][ny] && s[nx][ny] != 0)
      {
        for(;;)
        {
          nx = nx+dx;
          ny = ny+dy;
          move++;
          if(s[nx][ny] == s[x][y])
          {
            printf("0");
            break;
          }else if(s[nx][ny] == 0){
            printf("%d", move);
            printf("location=(%d,%d)", nx, ny);
            break;
          }
        }
      }  
    }
  }
  
   for(i = 0; i < ROWS; i++)
    for(j = 0; j < COLS; j++){
      printf("%d", &s[i][j]);
      if(j == ROWS ){
        printf("\n");
      }
    }
  
}