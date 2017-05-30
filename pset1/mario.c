#include <stdio.h>
#include <cs50.h>

void makePyramid(int n);
void printCharNTimes(int n, char c);
int getHeight(void);

int main(void)
{
  makePyramid(getHeight());
}

int getHeight(void)
{
  printf("Height: ");
  int h = get_int();
  if (h >= 0 && h <= 23)
  {
    return h;
  }
  else
  {
    return getHeight();
  }
}

void printCharNTimes(int n, char c)
{
  for(int i = 0; i < n; i++)
  {
    printf("%c", c);
  }
}

void makePyramid(int n)
{
  for (int i = 1; i <= n; i++)
  {
    printCharNTimes(n - i, ' ');
    printCharNTimes(i, '#');
    printf("  ");
    printCharNTimes(i, '#');
    printf("\n");
  }
}