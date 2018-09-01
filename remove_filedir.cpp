#include "ls.h"
#include "global_def.h"

void remove_filedir(string dpath)
{
	int status;
	struct stat my;
	stat(dpath.c_str(),&my);
	if(S_ISDIR(my.st_mode))
	{
		struct dirent **name;
		struct stat mystat;
		unsigned int x = scandir(dpath.c_str(), &name,NULL,alphasort);
		unsigned int i=2;
		while(i<x)
		{
			string str = name[i]->d_name;
			string temp = dpath+"/"+str;
			// cout<<" "<<str<<" "<<temp<<" ";
			// stat(str.c_str(),&mystat);
			remove_filedir(temp);
			++i;
		}
		status = rmdir(dpath.c_str());
	}
	else 
	{
		status = remove(dpath.c_str());
	}
}