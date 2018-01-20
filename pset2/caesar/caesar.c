#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string, int);
char rotate_char(char, int);

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Provide exactly one integer as an argument\n");
    return 1;
  }
  int key = atoi(argv[1]);
  printf("plaintext: ");
  string plaintext = get_string();
  string ciphertext = encrypt(plaintext, key);
  printf("ciphertext: %s\n", ciphertext);
  return 0;
}

// Encrypt a string by rotating each character 'key' places
string encrypt(string text, int key)
{
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    text[i] = rotate_char(text[i], key);
  }
  return text;
}

// Rotate letter by 'key' places, preserving case
char rotate_char(char c, int key)
{
  // Do not change non-alpha characters
  if (!isalpha(c))
  {
    return c;
  }
  // Remember whether the character should be uppercase
  bool is_upper = isupper(c);
  // Base characters at 0
  int alpha_index = tolower(c) - 'a';
  // Rotate by key and wrap if necessary
  int rotated_index = (alpha_index + key) % 26;
  // Convert back to ASCII
  char result = rotated_index + 'a';
  if (is_upper)
  {
    result = toupper(result);
  }
  return result;
}