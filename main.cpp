#include <Windows.h>
#include <stdio.h>

int windowWidth = 120;
int windowHeight = 40;

int main() {

  FreeConsole();
  AllocConsole();

  // Create buffer for console text
  char *screen = new char[windowWidth * windowHeight];
  // Create console handle
  HANDLE console = CreateConsoleScreenBuffer(
      GENERIC_READ | GENERIC_WRITE, false, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  // Set active buffer to our created console
  SetConsoleActiveScreenBuffer(console);

  SMALL_RECT consoleSize = {0, 0, 159, 59};
  SetConsoleWindowInfo(console, true, &consoleSize);

  DWORD bytesWritten = 0;
  while (1) {
    for (int i = 0; i < windowWidth - 1; i++) {
      for (int j = 0; j < windowHeight - 1; j++) {
        screen[i * j] = '#';
      }
    }
    screen[windowWidth * windowHeight - 1] = '\0';
    WriteConsoleOutputCharacter(console, screen, windowWidth * windowHeight,
                                {0, 0}, &bytesWritten);
  }

  FreeConsole();

  return 0;
}
