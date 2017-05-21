#include <stdio.h>
#include <cs50.h>

void makeTriangle(int n);

int main(void)
{
  printf("Number of lines: ");
  makeTriangle(get_int());
}

void makeTriangle(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("X");
    }
    printf("\n");
  }
}