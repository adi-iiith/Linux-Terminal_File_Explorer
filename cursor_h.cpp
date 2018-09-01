#include "ls.h"
#include "global_def.h"

void cursor(char path[])
{
	
	string home,pass_path,stk;
	
	int f,x;
	
	// home=s;
	DIR *directory;										//Directory pointer *directory , because WHY NOT?	
	struct dirent **name;
    struct stat mystat;
    // directory = opendir(s);	
	unsigned int cpos=2;
	char kstroke,uinput1,uinput2;
	struct termios initial_settings, new_settings;

	char buf[PATH_MAX + 1];
	char *res = realpath(path,buf);
	
	f = chdir(buf);
	x = scandir(".", &name,NULL,alphasort);

	// tcgetattr(0,&initial_settings);
	// new_settings = initial_settings;
	// new_settings.c_lflag &= ~ICANON;
	// new_settings.c_lflag &= ~ECHO;
	// tcsetattr(0, TCSANOW, &new_settings);
	//cout<<"\n"<<paths.size();
	// cout<<"\n"<<cpos;
	printf(ctop);
	
	tcgetattr(0,&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	tcsetattr(0,TCSANOW,&new_settings);
	fflush(stdout);

	while(1)
	{
		kstroke=getchar();
		if((int)kstroke == ESC)
		{
			uinput1 = getchar();
			uinput2 = getchar();
			if(uinput1 == BRAC && uinput2 == A && cpos>2)
			{

				cpos--;
				cout<<KEY_UP;
			}
			else if ( uinput1 == BRAC && uinput2 == B && cpos<=x)
			{
				cpos++;
				cout<<KEY_DOWN;
			}
			if(uinput1 == BRAC && uinput2 == C)
			{
				 if(!r_arrow.empty())
				{
					home=path;
					l_arrow.push(home);
					stk=r_arrow.top();
					r_arrow.pop();
					char *temp = realpath(stk.c_str(),buf);
					cout<<clear;
					ls(buf);
					// tcsetattr(0,&initial_settings);
					initial_settings.c_lflag &= ICANON;
					initial_settings.c_lflag &= ECHO;
					initial_settings.c_lflag &= ISIG;
 					break;
				}

			}
			if(uinput1 == BRAC && uinput2 == D)
			{
				 if(!l_arrow.empty())
				{
					home=path;
					r_arrow.push(home);
					stk = l_arrow.top();
					l_arrow.pop();
					char *temp = realpath(stk.c_str(),buf);
					cout<<clear;

					ls(buf);
					// tcsetattr(0,&initial_settings);
					initial_settings.c_lflag &= ICANON;
					initial_settings.c_lflag &= ECHO;
					initial_settings.c_lflag &= ISIG;
 					break;
				}
			}
		}
		else if(kstroke == q || kstroke == Q)
		{
			 tcsetattr(0,TCSANOW,&initial_settings);
			 cout<<clear;
			// tcsetattr(0,&initial_settings);
			 initial_settings.c_lflag &= ICANON;
			 initial_settings.c_lflag &= ECHO;
			 initial_settings.c_lflag &= ISIG;
			break;
		}
		else if(kstroke == ENTER && cpos!=0)
		{
			// char *temp = realpath(name[cpos-1]->d_name,buf);
			stat(name[cpos-2]->d_name,&mystat);
			if(S_ISDIR(mystat.st_mode))
			{
				r_arrow=stack<std::string>();
				home=path;
				l_arrow.push(home);
				//cout<<cpos;
				pass_path=name[cpos-2]->d_name;
				if(!(pass_path.compare(".")))
				{
					//do nothing
					;
				}
				else if(!(pass_path.compare("..")))
				{

					char *temp = realpath(name[cpos-2]->d_name,buf);
					if(strcmp(s,path))
					{
						ls(buf);
						tcsetattr(0,TCSANOW,&initial_settings);
						cout<<clear;
						// tcsetattr(0,&initial_settings);
						initial_settings.c_lflag &= ICANON;
						initial_settings.c_lflag &= ECHO;
						initial_settings.c_lflag &= ISIG;
		 				break;
	 				}
				}
				else{
						char *temp = realpath(name[cpos-2]->d_name,buf);
						// char pass[200];
						// strcpy(pass,pass_path.c_str());
	 					ls(buf);
			 			tcsetattr(0,TCSANOW,&initial_settings);
						cout<<clear;
						// tcsetattr(0,&initial_settings);
						initial_settings.c_lflag &= ICANON;
						initial_settings.c_lflag &= ECHO;
						initial_settings.c_lflag &= ISIG;
	 					break;
				}
			}
			else {	
						cpos--;
						// int temp = cpos;
						pid_t pid;
						pid=fork();
						if(pid==0)
						{
							execl("/usr/bin/xdg-open","xdg-open",name[cpos-1]->d_name, (char*)0 ) ;
						}
						home = path;
						ls(buf);
			 			tcsetattr(0,TCSANOW,&initial_settings);
						cout<<clear;
						// tcsetattr(0,&initial_settings);
						initial_settings.c_lflag &= ICANON;
						initial_settings.c_lflag &= ECHO;
						initial_settings.c_lflag &= ISIG;
	 					break;
						// cpos = temp;
						// cpos--;
				}
		}
		else if(kstroke == COLON)					//GOTO COMMAND MODE
		{
			mode_bit = 1;		
			stk=path;
			char *temp = realpath(stk.c_str(),buf);
			ls(buf);
			tcsetattr(0,TCSANOW,&initial_settings);
			initial_settings.c_lflag &= ICANON;
			initial_settings.c_lflag &= ECHO;
			initial_settings.c_lflag &= ISIG;
	 	 	break;

		}
		else if(kstroke == BSPACE)
		{
			char *temp = realpath(name[1]->d_name,buf);
			home=path;
			r_arrow.push(home);
			ls(buf);
			tcsetattr(0,TCSANOW,&initial_settings);
			cout<<clear;
			// tcsetattr(0,&initial_settings);
			initial_settings.c_lflag &= ICANON;
			initial_settings.c_lflag &= ECHO;
			initial_settings.c_lflag &= ISIG;
	 		break;


		}
		else if(kstroke == H)
		{
			r_arrow=stack<std::string>();
			home=path;
			l_arrow.push(home);
			ls(s);
			tcsetattr(0,TCSANOW,&initial_settings);
			cout<<clear;
			// tcsetattr(0,&initial_settings);
			initial_settings.c_lflag &= ICANON;
			initial_settings.c_lflag &= ECHO;
			initial_settings.c_lflag &= ISIG;
		 	break;
		}
	}
}
		
	
