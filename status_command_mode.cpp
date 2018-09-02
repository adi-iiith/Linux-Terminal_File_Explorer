#include "ls.h"
#include "global_def.h"

#define MAX 1024



void status_command_mode(char  path[])
{
	char kstroke;
	vector<char> abc;
	vector<string> dcopy;
	char buf[PATH_MAX + 1];
	char *temp = realpath(path,buf);
	struct termios initial_settings, new_settings;
	tcgetattr(0,&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	tcsetattr(0,TCSANOW,&new_settings);
	cout<<cdown;
	cout<<":::COMMAND MODE:::Press ESC to return to User Mode:::\n";
	// cout<<":::INPUT COMMAND:::";
	tcsetattr(0,TCSANOW,&initial_settings);
	initial_settings.c_lflag &= ICANON;
	initial_settings.c_lflag &= ECHO;
	initial_settings.c_lflag &= ISIG;
	string x,y,dpath,spath;
	FILE *src,*de;
	// stringstream uip;
	vector<string> pass;
	int flag;
	while(1)
	{
		
		kstroke=getchar();
		if(kstroke == ESC)												//ESC working
		 {	
		 	// char temp;
			// 	scanf("%c",&temp);
			// 	scanf("%c",&temp);
			// temp=getchar();
			mode_bit = 0;
			ls(buf);
			tcsetattr(0,TCSANOW,&initial_settings);
			initial_settings.c_lflag &= ICANON;
			initial_settings.c_lflag &= ECHO;
			initial_settings.c_lflag &= ISIG;
	 	 	break;
		}
		else if(kstroke == ENTER)
		{
			   //logic for enter still pending, tired today! 
			stringstream st(string(abc.begin(),abc.end()));
			st>>x;
			// cout<<"ENTER DETECTED";
			// for(int i=0;i<abc.size();i++)
			// 	cout<<abc[i]<<".";
			// cout<<x<<" ";
			if(!(x.compare("create_dir")))
			{
				st>>y;
			    st>>dpath; 
			    dpath=root+dpath;
			    dpath+="/"+y;
				struct stat st = {0};
				if (stat(dpath.c_str(), &st) == -1) 
					  int t =  mkdir(dpath.c_str(), PERMISSION);
				// abc.erase (abc.begin(),abc.end());
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("create_file")))
			{
				FILE *fp;
				st>>y;
			    st>>dpath; 
			    dpath=root+dpath;
			    dpath+="/"+y;
			    fp = fopen(dpath.c_str(),"w+");
			    fclose(fp);
			    // abc.erase (abc.begin(),abc.end());
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("copy")))
			{
				string ho;
				ho=path;
				string tre;
				while(st>>tre)
				{
					pass.push_back(tre);
				}
				int kk=pass.size();
				int l=kk-1;
				int i=0;
				dpath=root+pass[l];
				kk--;
			    while(i<kk)
			    	{
			    		string tee=ho+"/"+pass[i];
			    		string teee=dpath+"/"+pass[i];
			    		// cout<<spath<<" "<<dpath<<" ";
			   
				    	copy_filedir(tee,teee);
				    	tee="";
				    	teee="";
			    		i++;
			    	}
			    pass.erase(pass.begin(),pass.end());


				// st>>spath;
			 //    st>>dpath;
				// spath=root+spath;
				// dpath=root+dpath;
    		    
    // 		    copy_filedir(spath,dpath);
				
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("remove")))
			{
				
				st>>dpath;
				dpath=root+dpath;
				remove_filedir(dpath);
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("goto")))
			{
				mode_bit=0;
				st>>dpath;
				dpath=root+dpath;
				char buf[PATH_MAX + 1];
				char *temp = realpath(dpath.c_str(),buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("move")))
			{

				// st>>spath;
				// st>>dpath;
				// x=path;
				// spath=root+spath;
				// dpath=root+dpath;
				string ho;
				ho=path;
				string tre;
				while(st>>tre)
				{
					pass.push_back(tre);
				}
				int kk=pass.size();
				int l=kk-1;
				int i=0;
				dpath=root+pass[l];
				kk--;
				while(i<kk)
			    {
			    	string tee=ho+"/"+pass[i];
			    	string teee=dpath+"/"+pass[i];
			    	// cout<<spath<<" "<<dpath<<" ";
			   
				   	copy_filedir(tee,teee);
				   	
				   	int loop=100000000;
					while(loop--);
					remove_filedir(tee);
					tee="";
				   	teee="";

			    	i++;
			    }

				// copy_filedir(spath,dpath);
				// int loop=100000000;
				// while(loop--);
				// remove_filedir(spath);
				
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("rename")))
			{
				st>>spath;
				st>>dpath;
				x=path;
				spath=x+"/"+spath;
				// spath=root+spath;
				dpath=x+"/"+dpath;
				int pa = rename(spath.c_str(),dpath.c_str());
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}
			else if(!(x.compare("search")))
			{
				st>>spath;
				// vector<string> search;
				string passs="-----------------"+spath+"-----------------";
				searchs.push_back(passs);
				// passs="/home/adi";
				passs=path;
				searchs.push_back(passs);
				
				search_filedir(spath,root1);
				searchs.push_back("END OF RESULT");
				search_print();
				searchs.erase(searchs.begin(),searchs.end());
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;

			}

			else if(!(x.compare("snapshot")))
			{
				st>>spath;
				st>>dpath;
				spath=root+spath;
				x=path;
				x=spath+"/"+dpath;
				FILE *fp = fopen(x.c_str(),"w+");	
				fclose(fp);
				snapshot(spath,x);
				// cout<<spath<<" "<<x;
				char buf[PATH_MAX + 1];
				char *temp = realpath(path,buf);
				ls(buf);
				tcsetattr(0,TCSANOW,&initial_settings);
				cout<<clear;
				tcsetattr(0,TCSANOW,&initial_settings);
				// cout<<clear;
				// tcsetattr(0,&initial_settings);
				initial_settings.c_lflag &= ICANON;
				initial_settings.c_lflag &= ECHO;
				initial_settings.c_lflag &= ISIG;
		 		break;
			}

			cout<<"\033[40;f";
			cout<<"\033[K";
			cout<<"\033[40;f";
			
			
			abc.erase(abc.begin(),abc.end());
			dcopy.erase(dcopy.begin(),dcopy.end());
		}
		else if((int)kstroke == BSPACE)
		{
			// cout<<"Yes";
			cout<<"\033[40;f";
			cout<<"\033[K";
			cout<<"\033[40;f";
			abc.erase(abc.begin(),abc.end());
			dcopy.erase(dcopy.begin(),dcopy.end());

		}
		else 
		{
			abc.push_back(kstroke);
			cout<<kstroke;   //checlk if command mode is displaying according to master
			

		}
		
	}

}
