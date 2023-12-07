
#include <windows.h>
#include <string.h>

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
        case '0':
            return 0x30;
        case '1':
            return 0x31;
        case '2':
            return 0x32;
        case '3':
            return 0x33;
        case '4':
            return 0x34;
        case '5':
            return 0x35;
        case '6':
            return 0x36;
        case '7':
            return 0x37;
        case '8':
            return 0x38;
        case '9':
            return 0x39;
    }
    return -1;
}

int string_to_key(char *s) {
    if (strcmp("BACK", s) == 0) {
        return 0x08;
    } else if (strcmp("TAB", s) == 0) {
        return 0x09;
    } else if (strcmp("RETURN", s) == 0) {
        return 0x0D;
    } else if (strcmp("PAUSE", s) == 0) {
        return 0x13;
    } else if (strcmp("CAPITAL", s) == 0) {
        return 0x14;
    } else if (strcmp("ESCAPE", s) == 0) {
        return 0x1B;
    } else if (strcmp("SPACE", s) == 0) {
        return 0x20;
    } else if (strcmp("PRIOR", s) == 0) {
        return 0x21;
    } else if (strcmp("NEXT", s) == 0) {
        return 0x22;
    } else if (strcmp("END", s) == 0) {
        return 0x23;
    } else if (strcmp("HOME", s) == 0) {
        return 0x24;
    } else if (strcmp("LEFT", s) == 0) {
        return 0x25;
    } else if (strcmp("UP", s) == 0) {
        return 0x26;
    } else if (strcmp("RIGHT", s) == 0) {
        return 0x27;
    } else if (strcmp("DOWN", s) == 0) {
        return 0x28;
    } else if (strcmp("SNAPSHOT", s) == 0) {
        return 0x2C;
    } else if (strcmp("INSERT", s) == 0) {
        return 0x2D;
    } else if (strcmp("DELETE", s) == 0) {
        return 0x2E;
    } else if (strcmp("LWIN", s) == 0) {
        return 0x5B;
    } else if (strcmp("RWIN", s) == 0) {
        return 0x5C;
    } else if (strcmp("F1", s) == 0) {
        return 0x70;
    } else if (strcmp("F2", s) == 0) {
        return 0x71;
    } else if (strcmp("F3", s) == 0) {
        return 0x72;
    } else if (strcmp("F4", s) == 0) {
        return 0x73;
    } else if (strcmp("F5", s) == 0) {
        return 0x74;
    } else if (strcmp("F6", s) == 0) {
        return 0x75;
    } else if (strcmp("F7", s) == 0) {
        return 0x76;
    } else if (strcmp("F8", s) == 0) {
        return 0x77;
    } else if (strcmp("F9", s) == 0) {
        return 0x78;
    } else if (strcmp("F10", s) == 0) {
        return 0x79;
    } else if (strcmp("F11", s) == 0) {
        return 0x7A;
    } else if (strcmp("F12", s) == 0) {
        return 0x7B;
    } else if (strcmp("NUMLOCK", s) == 0) {
        return 0x90;
    } else if (strcmp("SCROLL", s) == 0) {
        return 0x91;
    } else if (strcmp("LSHIFT", s) == 0) {
        return 0xA0;
    } else if (strcmp("RSHIFT", s) == 0) {
        return 0xA1;
    } else if (strcmp("LCONTROL", s) == 0) {
        return 0xA2;
    } else if (strcmp("RCONTROL", s) == 0) {
        return 0xA3;
    } else if (strcmp("LMENU", s) == 0) {
        return 0xA4;
    } else if (strcmp("RMENU", s) == 0) {
        return 0xA5;
    }
    return -1;
}

int main(int argc, char **argv) {

    if (argc < 3) {
        return 0;
    }
    int key = -1;
    int flag = -1;
    if (argv[1][1] == '\0') {
        key = char_to_key(argv[1][0]);
    } else {
        key = string_to_key(argv[1]);
    }
    if (argv[2][0] == 'd') {
        flag = 0;
    } else if (argv[2][0] == 'u') {
        flag = 0x02;
    }
    if (key == -1 || flag == -1) {
        return 0;
    }
    keybd_event(key, 5, flag, 0);

    return 0;
}
