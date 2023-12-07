
#include <windows.h>
#include <stdio.h>

int main()
{
    POINT p;
    if (GetCursorPos(&p))
    {
        printf("%d %d", p.x, p.y);
    }
    return 0;
}
