#include "ls.h"

void status_user_mode()
{
	struct termios initial_settings, new_settings;
	tcgetattr(0,&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	tcsetattr(0,TCSANOW,&new_settings);
	cout<<cdown;
	cout<<":::USER MODE:::\n";
	cout<<"Press : to Enter Command Mode";
	tcsetattr(0,TCSANOW,&initial_settings);
	initial_settings.c_lflag &= ICANON;
	initial_settings.c_lflag &= ECHO;
	initial_settings.c_lflag &= ISIG;
}