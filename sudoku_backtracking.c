#include <stdio.h>
#define bool int
#define true 1
#define false 0

void Init();
void Sudoku(int i, int j);
bool Cuad(int altNum, int i, int j);
bool Verizontal(int altNum, int i, int j);
void PrintSolution();

int slots[9][9];
bool ENC;

int main(int argc, char const *argv[]) {
  Init();
  printf("Initialized\n");
  Sudoku(0,0);
  PrintSolution();
  return 0;
}

void Init()
{
  for(int i = 0; i<9; i++)
    for(int j = 0; j<9; j++)
        slots[i][j] = -1;
  ENC = false;
}

void PrintSolution()
{
  printf("- - - - - - - - -\n");
  for(int i = 0; i<9; i++)
  {
    printf("| ");
    for(int j = 0; j<9; j++)
    {
      printf("%d ", slots[i][j]);
    }
    printf(" |");
  }
  printf("- - - - - - - - -\n");
}

void Sudoku(int i, int j)
{
  int altNum = 0;
  do {
    altNum += 1;
    if(!Verizontal(altNum,i,j) && !Cuad(altNum,i,j))
    {
      //printf("[%d][%d] = %d\n", i,j,altNum);
      slots[i][j] = altNum;
      switch (i+j) {
        case 16:
          ENC = true;
        break;
        default:
          i++;
          if( i == 8)
          {
            i = 0; j++;
          }
          Sudoku(i,j);
        break;
      }

      if(!ENC)
      {
        slots[i][j] = -1;
      }
    }
  } while(j != 8 && i != 8);
}

bool Verizontal(int altNum, int i, int j)
{
  for(int aux = 0; aux < 9; aux++)
  {
    if(slots[i][aux] == altNum || slots[aux][j] == altNum) return true;
  }
  return false;
}

bool Cuad(int altNum, int i, int j)
{
  int myCuadX =  i / 3;
  int myCuadY = j / 3;

  for(int aux = 3 * myCuadY; aux < (3 * myCuadY) + 3; aux++)
  {
    for(int aux2 = 3 * myCuadX; aux2 < (3 * myCuadX) + 3 ; aux2++)
    {
      if(slots[aux, aux2] == altNum) return true;
    }
  }
  return false;
}
