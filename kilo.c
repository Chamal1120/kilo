#include <unistd.h>

int main() {
  char c;

  // Put the terminal to canonical mode 
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}
