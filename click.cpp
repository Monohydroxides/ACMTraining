#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
 
int main() {
	while (1) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(100);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
    return 0;
}