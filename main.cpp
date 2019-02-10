#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>


int bomb() {
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    int i = 0;

    printf("Number of bombs:");
    scanf("%d",&i);

    for (int k = 0; k < 5; k++) {
        printf("%d\n",5-k);
        Sleep(1000);
    }

    for (int j = 0; j < i; j++) {
        // Press "Ctrl"
        ip.ki.wVk = VK_CONTROL;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        // Press "V"
        ip.ki.wVk = 'V';
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        // Release "V"
        ip.ki.wVk = 'V';
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

        // Release "Ctrl"
        ip.ki.wVk = VK_CONTROL;
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));

        // Press "Enter"
        ip.ki.wVk = VK_RETURN;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        //Release "Enter"
        ip.ki.wVk = VK_RETURN;
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
    }
    printf("Complete.\n");
    return 0;
}

int main(){
    std::string re_bomb = "y";
    while (re_bomb != "n"){
        bomb();
        printf("Continue?(Y/n):");
        std::cin >> re_bomb;
    }
}