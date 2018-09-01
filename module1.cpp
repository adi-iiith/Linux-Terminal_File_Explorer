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
char s[] ="/home/adi/Downloads";
string root = "/home/adi/";
string root1 = "/home/adi/Downloads";
queue<string>sshot;
vector<string> searchs;

int main()
{	
	ls(s);
	return 1;
}
