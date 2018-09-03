#include "ls.h"
#include "global_def.h"

void ls(char path[])
{
	long long int hsize;																				
	unsigned int i=0;
	// char rp[500];
	// strcpy(b,path);
	cout<<clear;								//Clear the terminal for Output :::after 1M + hit and tries, Finally Successfull	
	char buf[PATH_MAX + 1];
	char *res = realpath(path,buf);
	// vector<string> paths;
	// DIR *directory;								//Directory pointer *directory , because WHY NOT?	
	struct dirent **name;
	unsigned int f,x;
    struct stat mystat;
    time_t t;
    struct tm* timer;
    time(&t);
    struct group *grp;
    struct passwd *pwd;
    // timer = localtime(&t);
    // directory = opendir(buf);				//Open directory
	f = chdir(buf);
	x = scandir(".", &name,NULL,alphasort);
	cout<<"DIRECTORY    :::     "<<buf;
	cout<<"\n";
	cout<<"\n";
	string y;
	if(x>34)
		x=34;
	while (i<x) {
        
        // cout<<setw(20)<<left<<name[i]->d_name;
		
        string x = name[i]->d_name;
        if(x.length() > 16)
        	 y = x.substr(0,16)+"..";
        else y=x;
        cout<<setw(20)<<left<<y;

        stat(name[i]->d_name,&mystat);
        hsize=mystat.st_size;
        if(hsize<1000)									
		  	  cout<<setw(20)<<left<<to_string(hsize)+"B";
		  else if(hsize<1000000)
		  	cout<<setw(20)<<left<<to_string(hsize/1000)+"KB";
		  else if(hsize<1000000000)
		  	cout<<setw(20)<<left<<to_string((hsize/1000000))+"MB";
		   cout<<((S_ISDIR(mystat.st_mode)) ? "d" : "-")<<
		  ((mystat.st_mode & S_IRUSR) ? "r" : "-")<<
		  ((mystat.st_mode & S_IWUSR) ? "w" : "-")<<
		  ((mystat.st_mode & S_IXUSR) ? "x" : "-")<<
		  ((mystat.st_mode & S_IRGRP) ? "r" : "-")<<
		  ((mystat.st_mode & S_IWGRP) ? "w" : "-")<<
		  ((mystat.st_mode & S_IXGRP) ? "x" : "-")<<
		  ((mystat.st_mode & S_IROTH) ? "r" : "-")<<
		  ((mystat.st_mode & S_IWOTH) ? "w" : "-")<<setw(20)<<left<<((mystat.st_mode & S_IXOTH) ? "x" : "-");   
		  
		  grp=getgrgid(mystat.st_gid);
		  cout<<setw(15)<<left<<grp->gr_name;
		  
		  pwd=getpwuid(mystat.st_uid);
		  cout<<setw(15)<<left<<pwd->pw_name;

		  t = mystat.st_mtime;
		  timer = localtime(&t);
		  cout<<setw(20)<<left<<asctime(timer);
         ++i;
      }
      free(name);
      if(mode_bit==0)
      {
      	status_user_mode();
      	cursor(path);
      }
      else if(mode_bit == 1)
      {
      	// struct termios initial_settings, new_settings;
		// tcgetattr(0,&initial_settings);
		// new_settings = initial_settings;
		// new_settings.c_lflag &= ICANON;
		// new_settings.c_lflag &= ECHO;
		// tcsetattr(0,TCSANOW,&new_settings);
      	status_command_mode(path);

      }
}

//     while((file = readdir(directory)) != NULL)	  	//Store the file names in a vector "paths"
//     {
//     	  paths.push_back(file->d_name);
// 	}
// 	closedir(directory);
// 	directory = opendir(buf);
// 	sort(paths.begin(),paths.end());
// 	for(;i<paths.size();i++)	
// 	{					
// 		  string temp=paths[i];	
		 
// 		  strcpy(rp,temp.c_str());
// 		  char *r = realpath(rp,buf);	
		  
											
		  
// 		  strcat(a,"/");
// 		  strcat(a,temp.c_str());
// 		   cout<<setw(20)<<left<<paths[i];
// 		  // cout<<temp<<"\n\n";
// 		  stat(buf,&mystat);
		  
// 		  strcpy(a,b);
// 		  hsize=mystat.st_size;
// 		  // cout<<setw(20)<<left<<to_string(hsize);

// 		  // if((paths[i].compare("."))==0)					//Print Size in form of B,Kb,Mb etc...
// 		  // 	cout<<setw(20)<<left<<"4KB";
		  
// 		  if(hsize<1000)									
// 		  	  cout<<setw(20)<<left<<to_string(hsize)+"B";
// 		  else if(hsize<1000000)
// 		  	cout<<setw(20)<<left<<to_string(hsize/1000)+"KB";
// 		  else if(hsize<1000000000)
// 		  	cout<<setw(20)<<left<<to_string((hsize/1000000))+"MB";
		  
// 		  cout<<((S_ISDIR(mystat.st_mode)) ? "d" : "-")<<
// 		  ((mystat.st_mode & S_IRUSR) ? "r" : "-")<<
// 		  ((mystat.st_mode & S_IWUSR) ? "w" : "-")<<
// 		  ((mystat.st_mode & S_IXUSR) ? "x" : "-")<<
// 		  ((mystat.st_mode & S_IRGRP) ? "r" : "-")<<
// 		  ((mystat.st_mode & S_IWGRP) ? "w" : "-")<<
// 		  ((mystat.st_mode & S_IXGRP) ? "x" : "-")<<
// 		  ((mystat.st_mode & S_IROTH) ? "r" : "-")<<
// 		  ((mystat.st_mode & S_IWOTH) ? "w" : "-")<<setw(20)<<left<<((mystat.st_mode & S_IXOTH) ? "x" : "-");   


// 		  t = mystat.st_mtime;
// 		  timer = localtime(&t);

// 		  cout<<setw(20)<<left<<asctime(timer);
// //		  cout<<setw(5)<<left<<mystat.st_mode;                                                    //Permission Mode in Decimal
// 		  		  //cout<<"\n";
// 	}
	// closedir(directory);
