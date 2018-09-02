#include "ls.h"
#include "global_def.h"

void search_filedir(string pattern,string path)
{

		struct stat mystat;
		struct dirent **name;
		
		unsigned int x = scandir(path.c_str(), &name,NULL,alphasort);
		unsigned int i=2;
		string str,fpath;
		while(i<x)
		{
			 str = name[i]->d_name;
			 // fpath=path+str;
			 fpath=path+"/"+str;
			 string pass=path+"/"+str;
			 stat(pass.c_str(),&mystat);
			 if(S_ISDIR(mystat.st_mode))
			 {
			 	if(!pattern.compare(str))
			 	{
			 		searchs.push_back(fpath);
			 	}
			 	fpath=path+"/"+str;

			 	search_filedir(pattern,fpath);
			 }
			 else 
			 {
			 	
			 	if(!pattern.compare(str))
			 	{

			 		searchs.push_back(pass);
			 	}
			 }

			++i;
		}
}