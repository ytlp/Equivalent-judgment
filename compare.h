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

class allcpp{
    private:
        string name;
        string res;
        int cnt=0;
    public:
        int get_cnt()
        {
            return cnt;
        }
        string get_res()
        {
            return res;
        }
        string get_name()
        {
            return name;
        }
        void set_name(string a)
        {
            name=a;
        }
         void set_res(string a)
        {
            res=a;
        }
        void add_cnt()
        {
            ++cnt;
        }

};
void findOutput(char *path);
void compare();
void writeIn(char path1[500],char name[500]);