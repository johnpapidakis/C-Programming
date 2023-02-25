#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int score = 0; // Keep track of the user's score

// This function tests whether a word is a palindrome
void testPalindrome(int len) {
  char s[len];
  int i, j;
  printf("Enter a word of length %d:\n", len);
  fflush(stdin);
  gets(s);

  // Check if the word is a palindrome
  for (i = 0, j = len - 1; i < j; i++, j--) {
    if (s[i] != s[j]) {
      // If the word is not a palindrome, raise a SIGINT signal
      printf("\nNot a Palindrome\n");
      raise(SIGINT);
      break;
    }
  }

  // If the word is a palindrome, increment the score
  score++;

  printf("\nPalindrome\n");
}

// This function is called when the user gives an incorrect answer or the waiting time expires
void sigint_handler(int signo) {
  printf("\nTIME IS UP!!!\n");
  printf("Final score: %d\n", score);

  // Terminate the program
  exit(0);
}

int main() {
  int len = 3; // Initial length of the palindrome
   // Initial timeout in seconds

  // Set up a signal handler for SIGINT
  signal(SIGINT, sigint_handler);

  while (1) {
    // Set up an alarm to raise a SIGINT signal if the user doesn't answer in time
    alarm(len*10-10);

    // Ask the user to enter a palindrome of the current length
    testPalindrome(len);

    // Increase the length and timeout for the next iteration
    len++;
    //timeout += 10;
  }

  return 0;
}