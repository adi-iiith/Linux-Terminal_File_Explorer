#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include<iostream>
#include <limits.h>
using namespace std;
struct passwd *pw = getpwuid(getuid());

const char *homedir = pw->pw_dir;

int main()
{
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	cout<<cwd<<"\n";
	cout<<homedir<<"\n";
	return 0;
}