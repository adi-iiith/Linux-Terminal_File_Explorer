#include "ls.h"
#include "global_def.h"

void copy_filedir(string spath , string dpath)
{
	// cout<<" "<<spath<<" "<<dpath<<" ";
	struct stat my;
	stat(spath.c_str(),&my);
	if(S_ISDIR(my.st_mode))
	{
		// stat(dpath.c_str(),&mystat);
		struct stat st = {0};
			if (stat(dpath.c_str(), &st) == -1) 
				  int t =  mkdir(dpath.c_str(), PERMISSION);
		// cout<<"Directory Detetcted";
		struct dirent **name;
		struct stat mystat;
		unsigned int x = scandir(spath.c_str(), &name,NULL,alphasort);
		unsigned int i=2;
		while(i<x)
		{
			string str = name[i]->d_name;
			string temp = dpath+"/"+str;
			str = spath+"/"+str;
			// cout<<" "<<str<<" "<<temp<<" ";
			// stat(str.c_str(),&mystat);
			copy_filedir(str,temp);
			++i;
		}
	}
	else 
	{
		FILE *src,*de;
		// cout<<"Its a file";
		// cout<<" "<<spath<<" "<<dpath<<" ";
		src = fopen(spath.c_str(),"r+");
			 
		de = fopen(dpath.c_str(),"w+");
		int c;
		while((c = fgetc(src))!= EOF)			   
		fputc(c,de);
		fclose(src);
	    fclose(de);
	}

}