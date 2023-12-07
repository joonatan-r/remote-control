
#include <windows.h>

int char_to_key(char c) {
    switch (c) {
        case 'a':
            return 0x41;
        case 'b':
            return 0x42;
        case 'c':
            return 0x43;
        case 'd':
            return 0x44;
        case 'e':
            return 0x45;
        case 'f':
            return 0x46;
        case 'g':
            return 0x47;
        case 'h':
            return 0x48;
        case 'i':
            return 0x49;
        case 'j':
            return 0x4A;
        case 'k':
            return 0x4B;
        case 'l':
            return 0x4C;
        case 'm':
            return 0x4D;
        case 'n':
            return 0x4E;
        case 'o':
            return 0x4F;
        case 'p':
            return 0x50;
        case 'q':
            return 0x51;
        case 'r':
            return 0x52;
        case 's':
            return 0x53;
        case 't':
            return 0x54;
        case 'u':
            return 0x55;
        case 'v':
            return 0x56;
        case 'w':
            return 0x57;
        case 'x':
            return 0x58;
        case 'y':
            return 0x59;
        case 'z':
            return 0x5A;
    }
    return -1;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        return 0;
    }
    int key = char_to_key(argv[1][0]);
    if (key == -1) {
        return 0;
    }
    Sleep(3000);
    keybd_event(key, 5, 0, 0);
    Sleep(100);
    keybd_event(key, 5, 0x02, 0);

    keybd_event(VK_MENU, 5, 0, 0);
    Sleep(100);
    keybd_event(VK_TAB, 5, 0, 0);
    Sleep(100);
    keybd_event(VK_TAB, 5, 0x02, 0);
    Sleep(100);
    keybd_event(VK_MENU, 5, 0x02, 0);

    return 0;
}
