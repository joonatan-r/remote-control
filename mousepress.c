
#include <windows.h>

int main(int argc, char** argv)
{
    if (argc < 3) return 0;

	int flag = -1;

	if (argv[1][0] == 'l' && argv[2][0] == 'd')
	{
		flag = 0x0002;
	}
	else if (argv[1][0] == 'l' && argv[2][0] == 'u')
	{
		flag = 0x0004;
	}
	else if (argv[1][0] == 'r' && argv[2][0] == 'd')
	{
		flag = 0x0008;
	}
	else if (argv[1][0] == 'r' && argv[2][0] == 'u')
	{
		flag = 0x0010;
	}

	if (flag == -1) return 0;

    mouse_event(flag, 0, 0, 0, 0);

	return 0;
}

/*

(Should only have values set when they change)

MOUSEEVENTF_ABSOLUTE
0x8000
    (If set, mouse pos absolute, else relative to last reported)

MOUSEEVENTF_LEFTDOWN
0x0002
	The left button is down.

MOUSEEVENTF_LEFTUP
0x0004
	The left button is up.

MOUSEEVENTF_MIDDLEDOWN
0x0020
	The middle button is down.

MOUSEEVENTF_MIDDLEUP
0x0040
	The middle button is up.

MOUSEEVENTF_MOVE
0x0001
	Movement occurred.

MOUSEEVENTF_RIGHTDOWN
0x0008
	The right button is down.

MOUSEEVENTF_RIGHTUP
0x0010
	The right button is up.

MOUSEEVENTF_WHEEL
0x0800
	The wheel has been moved, if the mouse has a wheel. The amount of movement is specified in dwData

MOUSEEVENTF_XDOWN
0x0080
	An X button was pressed.

MOUSEEVENTF_XUP
0x0100
	An X button was released.

MOUSEEVENTF_WHEEL
0x0800
	The wheel button is rotated.

MOUSEEVENTF_HWHEEL
0x01000
	The wheel button is tilted. 

*/
