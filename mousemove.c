
#include <windows.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 3) return 0;

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    SetCursorPos(x, y);

    return 0;
}
