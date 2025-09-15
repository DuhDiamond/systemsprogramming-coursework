#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  size_t size = 0;

  printf("Please enter some text: ");

  // getline() allocates buffer, and we must free it.
  if (getline(&buff, &size, stdin) != -1L) {
    // Tokenize the string:
    char *input_str = buff;
    char *delim = " \t\n\r";
    char *token = NULL;
    char *saveptr = NULL;

    /* input_str must contain the real string on the first call, but be NULL
     * later. saveptr must be null the first time, and is set later (stores
     * status so call is reentrant */

    while ((token = strtok_r(input_str, delim, &saveptr))) {
      printf("Token: '%s'\n", token);

      input_str = NULL;
    }
  } else {
    printf("Getline failure.\n");
  }
  free(buff);

  return 0;
}
