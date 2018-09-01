#include<stdio.h>
#include<iostream>
#include <sys/stat.h>
#include<algorithm>
#include<vector>
#include<dirent.h>
#include <iomanip> 
#include<time.h>
#include<termios.h>
#include<string>
#include<string.h>
#include<limits.h>
#include<grp.h>
#include<pwd.h>
#include<stdlib.h>
#include<stack>
#include<unistd.h>
#include<sstream>
#include<fcntl.h>

/* ################################################################################## 
##########################Define escape sequences ##################################*/

#define ctop "\033[3;f"
#define cdown "\033[39;f"
#define clear "\033[H\033[J"
#define Q 81
#define q 113
#define COLON 58
#define ESC 27
#define BRAC 91
#define A 65
#define B 66
#define C 67
#define D 68
#define KEY_ESCAPE  "0x001b"
#define KEY_ENTER   "0x000a"
#define KEY_UP      "\033[A"
#define KEY_DOWN    "\033[B"
#define KEY_LEFT    "\033[D"
#define KEY_RIGHT   "\033[C"
#define ENTER 10
#define PERMISSION 0777
#define H 104
#define BSPACE 127
/*##############################Define escape sequences####################################
########################## ###############################################################*/

using namespace std;

#ifndef INC_MODULE1_H
#define INC_MODULE1_H
void ls(char path[]);
void cursor(char  s[]);
void status_user_mode();
void status_command_mode(char path[]);
void copy_filedir(string spath , string dpath);
void remove_filedir(string dpath);
void search_filedir(string pattern,string path);
void search_print();

// void snapshot(string path,string fname);


// void create_dirfile(string y,string dpath,int flag);
#endif  /*INC_MODULE1_H*/
