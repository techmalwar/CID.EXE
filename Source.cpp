#include <Windows.h>
#include <iostream>
#include <windows.graphics.h>

using namespace std;



int main()

{
    ShellExecuteA(0, 0, "chrome.exe", "https://youtu.be/UcRtFYAz2Yo --incognito", 0, SW_SHOWMINIMIZED);
    
    INPUT ip;

    Sleep(8000);

    // ...
        // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = 0x7A; // virtual-key code for the "f11" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    // ...

    int num = 10;

    HDC hdc = GetDC(HWND_DESKTOP);

    int sw = GetSystemMetrics(SM_CXSCREEN);

    int sh = GetSystemMetrics(SM_CYSCREEN);

    HDC desk = GetDC(0);

    int y = GetSystemMetrics(1);

    int x = GetSystemMetrics(0);

    while (1)
    {
        BitBlt(hdc, rand() % 10 - 20, rand() % 20 - 10, y, x, hdc, 0, 0, SRCCOPY);

        BitBlt(hdc, rand() % 10 - 20, rand() % 20 - 10, sw, sh, hdc, 0, 0, SRCCOPY);


        if (rand() % 3 == 2)
        {
            HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            SelectObject(desk, brush);
            PatBlt(desk, 0, 0, x, y, PATINVERT);
            Sleep(rand() % 1000);

        }

        else if (rand() % 3 == 1)
        {
            HBRUSH brush = CreateSolidBrush(RGB(rand() % 75, rand() % 75, rand() % 75));
            SelectObject(desk, brush);
            PatBlt(desk, 0, 0, x, y, PATINVERT);
            Sleep(rand() % 500);

        }

         
        if (GetAsyncKeyState(VK_BACK) & (0x08 != 0))

        {   
            system("taskkill /im chrome.exe");
            Sleep(10);

            system("echo Happy CID! Childrens independence Day :) >>CID.txt");
            Sleep(500);

            system("CID.txt");
            Sleep(200);


            ExitProcess(0);
        }
    }
}