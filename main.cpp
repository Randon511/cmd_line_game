#include <Windows.h>
#include <stdio.h>

short windowWidth = 120;
short windowHeight = 40;

int main()
{

    FreeConsole();
    AllocConsole();

    // Create buffer for console text
    wchar_t *screen = new wchar_t[(windowWidth * windowHeight) + 1];
    // Create console handle
    HANDLE console = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE,
        false,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);
    // Set active buffer to our created console
    SetConsoleActiveScreenBuffer(console);

    COORD coord = {windowWidth, windowHeight};
    SetConsoleScreenBufferSize(console, coord);
    SMALL_RECT consoleSize = {0};
    consoleSize.Right = coord.X - 1;
    consoleSize.Bottom = coord.Y - 1;
    SetConsoleWindowInfo(console, true, &consoleSize);

    DWORD bytesWritten = 0;
    while (1)
    {
        for (int i = 0; i < (windowWidth * windowHeight); i++)
        {
            screen[i] = '#';
        }
        screen[windowWidth * windowHeight] = '\0';
        WriteConsoleOutputCharacterW(
            console, screen, windowWidth * windowHeight, {0, 0}, &bytesWritten);
    }

    FreeConsole();

    return 0;
}
