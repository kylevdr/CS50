#include <stdio.h>
#include <cs50.h>

bool validate(long long);
string checkBrand(long long);
long long square(int, int);

int main(void)
{
  string result;
  printf("Card Number:\n");
  long long ccnum = get_long_long();
  if (validate(ccnum))
  {
    result = checkBrand(ccnum);
  }
  else
  {
    result = "INVALID\n";
  }
  printf("%s", result);
  return 0;
}

bool validate(long long ccnum)
{
  long long checksum = 0;
  for (long long i = 10; ccnum / i > 0; i *= 100)
  {
    int x = (ccnum / i) % 10 * 2;
    for (int j = 1; x / j > 0; j *= 10)
    {
      checksum += x / j % 10;
    }
  }
  for (long long i = 1; ccnum / i > 0; i *= 100)
  {
    checksum += ccnum / i % 10;
  }
  if (checksum % 10 == 0)
  {
    return true;  
  }
  else
  {
    return false;
  }
}

long long square(int base, int exp)
{
  long long result = 1;
  for (int i = 0; i < exp; i++)
  {
    result *= base;
  }
  return result;
}

string checkBrand(long long ccnum)
{
  int length = 0;
  for (long long i = 1; ccnum / i > 0; i *= 10)
  {
    length ++;
  }
  int firstTwo = ccnum / square(10, length - 2);
  if (length == 15 && (firstTwo == 34 || firstTwo == 37))
  {
    return "AMEX\n";
  }
  else if (length == 16 && (firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55))
  {
    return "MASTERCARD\n";
  }
  else if ((length == 13 || length == 16) && firstTwo / 10 == 4)
  {
    return "VISA\n";
  }
  else
  {
    return "INVALID\n";
  }
}