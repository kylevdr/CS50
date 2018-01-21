#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string encrypt(string, string);
char rotate_char(char, int);

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Provide exactly one keyword as an argument\n");
    return 1;
  }
  string keyword = argv[1];
  for (int i = 0, n = strlen(keyword); i < n; i++)
  {
    if (!isalpha(keyword[i]))
    {
      printf("Keyword must contain only letters");
      return 1;
    }
  }
  printf("plaintext: ");
  string plaintext = get_string();
  string ciphertext = encrypt(plaintext, keyword);
  printf("ciphertext: %s\n", ciphertext);
  return 0;
}

// Encrypt a string using keyword
string encrypt(string text, string keyword)
{
  int keyword_length = strlen(keyword);
  int position = 0;
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    char current_char = text[i];
    if (!isalpha(current_char))
    {
      continue;
    }
    char key_char = tolower(keyword[position]);
    int key = key_char - 'a';
    text[i] = rotate_char(current_char, key);
    position = (position + 1) % keyword_length;
  }
  return text;
}

// Rotate letter by 'key' places, preserving case
char rotate_char(char c, int key)
{
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