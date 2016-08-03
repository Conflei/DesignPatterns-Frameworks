#include <stdio.h>
#define bool int
#define true 1
#define false 0

void Init();
void Queens();
bool Verizontal(int i, int j);
bool Diagonal(int i, int j);
bool DiagonalSI(int i, int j);
bool DiagonalSD(int i, int j);
bool DiagonalII(int i, int j);
bool DiagonalID(int i, int j);

bool Slots[8][8];
bool ENC;

int main(void) {
	Init();
	Queens(1);
	PrintSolution();
	return 0;
}

void PrintSolution()
{
	printf("- - - - - - - -\n");
	for(int i = 0; i < 8 ; i++)
	{
			for(int j = 0; j< 8; j++)
			{
				printf("%d ", Slots[i][j]);
			}
			printf("\n");
	}
	printf("- - - - - - - -\n");
}

void Init()
{
	for(int i = 0; i< 8; i++)
		for(int j = 0; j<8; j++)
			Slots[i][j] = false;

	ENC = false;
}

void Queens(int Q)
{
	int i = 0, j = -1;

			do
			{
						if(j == 7)
						{
									i += 1; j = 0;
						}
						else
						{
									j += 1;
						}

						if(!Vertizontal(i,j) && !Diagonal(i,j))
						{
									Slots[i][j] = true;

									switch(Q)
									{
										case 8:
											ENC = true;
										break;

										default:
											Queens(Q+1);
										break;
									}

									if(!ENC) Slots[i][j] = false;
						}

			}while(i < 8 && j < 8 && !ENC);
}

bool Vertizontal(int i, int j)
{
	int it = 0;
	while(it < 8)
	{
		if(Slots[it][j] || Slots[i][it])
			return true;

		it++;
	}
	return false;
}

bool Diagonal(int i, int j)
{
	return (DiagonalSI(i, j) || DiagonalSD(i, j) || DiagonalII(i, j) || DiagonalID(i, j));
}

bool DiagonalSI(int i, int j)
{
	while(j < 8 && i >= 0)
	{
		if(Slots[i][j])
			return true;
		i--;j++;
	}
	return false;
}

bool DiagonalSD(int i, int j)
{
	while(j < 8 && i < 8)
	{
		if(Slots[i][j])
			return true;
		i++;j++;
	}
	return false;
}

bool DiagonalII(int i, int j)
{
	while(j >= 0 && i >= 0)
	{
		if(Slots[i][j])
			return true;
		i--;j--;
	}
	return false;
}

bool DiagonalID(int i, int j)
{
	while(j >= 0 && i < 8)
	{
		if(Slots[i][j])
			return true;
		i++;j--;
	}
	return false;
}
