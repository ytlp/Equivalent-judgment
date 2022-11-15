#include<iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include<stdlib.h>
#include"createInput.h"
#include"execute.h"
#include"compare.h"
int main(int argc,char *argv[])
{
   createInput();
   execute();
   compare();
   // char command[50];
   // strcpy( command, "g++ 1.cpp -o 1.out" );
   // system(command);
   // std::string cmd2("./1.out <input.txt >ouput.txt");
   // FILE *fp2=nullptr;
   // if((fp2=popen(cmd2.c_str(),"r"))==nullptr)
   // {
   //    return 0;
   // }
   // char read_str[512]="";
   // while(fgets(read_str,sizeof(read_str),fp2))
   // {
   //    std::cout<<"GetCommdResult:   "<<read_str<<std::endl;
   // }
   // pclose(fp2);
 
   return(0);
}
// void GetCommdResult(const std::string &cmd)
// {
//     FILE *fp=nullptr;
//     if((fp=popen(cmd.c_str(),"r"))==nullptr)
//     {
//         return;
//     }
//     char read_str[512]="";
//     while(fgets(read_str,sizeof(read_str),fp))
//     {
//         std::cout<<"GetCommdResult:   "<<read_str<<std::endl;
//     }
//     pclose(fp);
// }

// int main(int argc, char *argv[])
// {
//     std::string cmd1("gcc 1.cpp -o 1.o");
//     FILE *fp1=nullptr;
//      if((fp1=popen(cmd1.c_str(),"r"))==nullptr)
//     {
//         return 0;
//     }
//     std::string cmd2("1.o <input.txt> ouput.txt");
//    FILE *fp2=nullptr;
//     if((fp2=popen(cmd2.c_str(),"r"))==nullptr)
//     {
//         return 0;
//     }
//     char read_str[512]="";
//     while(fgets(read_str,sizeof(read_str),fp2))
//     {
//         std::cout<<"GetCommdResult:   "<<read_str<<std::endl;
//     }
//     pclose(fp1);
//     //pclose(fp2);
    
    
//    // GetCommdResult(cmd);
//    return 0;
// }
