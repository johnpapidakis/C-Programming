#include <stdio.h>
#include <string.h>

// This program takes a string, breaks it into tokens and then prints
// the tokens.
int main () 
{
  char str[] = "This is a simple string.";
  char *ptr;
  
  printf ("Splitting the string \"%s\" into tokens:\n", str);

  // Calling strtok() to start 'breaking' the string 'str' into tokens (or
  // substrings) around the delimiter characters '.' and ' '.
  // This will return a pointer to the current token, i.e. "This" here.
  // The function also saves internally a pointer to the next character
  // after the end of the found token.     
  ptr = strtok(str, ". ");

  while (ptr != NULL) 
  {
    printf("\n%s", ptr);      
    // Print the token value pointed to by 'ptr'.

    ptr = strtok(NULL, ". "); 
    // Get the next token in the original string;                       
    // the NULL argument indicates that the call to
    // strtok() should continue tokenising from the
    // location in 'str' saved by the last call to
    // strtok().
  }

  return 0;
}