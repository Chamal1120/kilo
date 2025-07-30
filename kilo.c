#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Store the original terminal attribute in a
// global variable
struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);

  // atexit comes from stdlib.h
  // This allows to register disableRawMode function to
  // be called automatically when the program exits
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  // Turn off ECHO makes each typed printed to the terminal
  raw.c_lflag &= ~(ECHO);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
  enableRawMode();

  char c;
  // Put the terminal to canonical mode
  // reads until user presses the key 'q'
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}
