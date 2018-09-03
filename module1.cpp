#include<stdio.h>
#include<iostream>
#include <sys/stat.h>
#include<algorithm>
#include<vector>
#include<dirent.h>
#include <iomanip> 

#include "ls.h"
#include "global_def.h"
// using namespace std;
stack<string> l_arrow;
stack<string> r_arrow;
int mode_bit=0;
char s[PATH_MAX+1];
string root; 
string root1; 

// char s[] ="/home/adi/Downloads";
// string root = "/home/adi/";
// string root1 = "/home/adi/Downloads";

queue<string>sshot;
vector<string> searchs;

int main()
{	
	freopen("stderr.log","w",stderr);
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;                       //get home path 

	char cwd[PATH_MAX+1];										// for CWD	
	getcwd(cwd, sizeof(cwd));

	strcpy(s,cwd);
	root = homedir;
	root1=cwd;
	root += +"/";
	// root1 = "/home/adi";
	// root1=cwd;
	// root1=cwd;
	// root1=cwd;



	ls(s);
	return 1;
}
