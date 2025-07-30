#include <unistd.h>

int main() {
  char c;

  // Put the terminal to canonical mode
  // reads until user presses the key 'q'
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}
