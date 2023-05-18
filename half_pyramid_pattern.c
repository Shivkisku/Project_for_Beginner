#include <stdio.h>

void pattern(int);

int main()
{
  int rows;
  printf("Enter the number of rows: ");
  scanf("%i", &rows);
  printf("\n");
  pattern(rows);
  return 0;
}

void pattern(int rows)
{
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= i; j++)
      printf("%c\t", (j % 2 == 0) ? 'O' : 'X');
    printf("\n");
  }
}
