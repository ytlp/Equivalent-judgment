#include<iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <sstream>
#include<fstream>
void findDir(char *path);
void command(char* allpath,char*path,char* name);
char *strpl(char *str, char *old, char *news);
void execute();