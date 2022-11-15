#include <iostream>
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
#include <ctime>
using namespace std;
void listDir(char *path);
void createInput();
int ICSdis(char* str);
int ranInt(string str);
char ranChar(string str);
string ranString(string str);