#include "ls.h"
#include "global_def.h"
void snapshot(string path,string filep)
{
	char buf[PATH_MAX + 1];
	char *temp = realpath(path.c_str(),buf);
	unsigned int i=2;
	struct dirent **name;
	unsigned int f,x;
	f = chdir(buf);
	x = scandir(".", &name,NULL,alphasort);
	FILE *fp = fopen(filep.c_str(),"w+");
	struct stat mystat;
	while(i<x)
	{
		stat(name[i]->d_name,&mystat);
		if(S_ISDIR(mystat.st_mode))
		{
			string pass=path+"/"+name[i]->d_name;
			sshot.push(pass);
			fputs(name[i]->d_name,fp);
			fputs("\n",fp);
		}
		else
		{
			fputs(name[i]->d_name,fp);
			fputs("\t",fp);
		}
		++i;
	}
	
	while (!sshot.empty())
	  {
	  	string pa=sshot.front();
	  	sshot.pop();
	  	snapshot(pa,filep);
	    // std::cout << ' ' << myqueue.front();
	    
	  }
	  fclose(fp);
}