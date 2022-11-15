#include"execute.h"
char *strpl(char *str, char *old, char *news)
{
	char *p = NULL;
	int len = 0;
	char newstr[64] = {0};

	p = strstr(str,old);
	len =  p - str;
	strncpy(newstr, str, len);
	strcat(newstr, news);
	strcat(newstr,p+strlen(old));
	strcpy(str,newstr);

	return str;
}
void execute()
{
     findDir("./input");
}
void command(char allpath[500],char path[500],char  name[500])
{
    char path1[500];
    strcpy(path1,path);
    char h[50];
    strcpy(h,name);
    strpl(h, ".cpp",".out");
    cout << name<<"        " << h<<endl;
    char cmd[500]="g++ ";
    strcat(cmd,path);
    strcat(cmd,"/");
    strcat(cmd,name);
    strcat(cmd," -o ");
    strcat(cmd,path);
    strcat(cmd,"/");
    strcat (cmd,h);
    cout << cmd<<endl;
    system(cmd);

    char cmd1[500]="\n";
     strcat(cmd1,path);
    strcat(cmd1,"/");
    strcat(cmd1,h);
    strcat(cmd1," <");
    strcat(cmd1,path);
    strcat(cmd1,"/");
    strcat(cmd1,"input1.txt >");
    strcat(cmd1,path);
     strcat(cmd1,"/");
    strcat(cmd1,"output1.txt");
    cout <<endl;
    cout<< cmd1<<endl;
    //std::string cmd_(cmd1);
    system(cmd1);

    char cmd2[500]="\n";
     strcat(cmd2,path);
    strcat(cmd2,"/");
    strcat(cmd2,h);
     strcat(cmd2," <");
    strcat(cmd2,path);
    strcat(cmd2,"/");
    strcat(cmd2,"input2.txt >");
    strcat(cmd2,path);
     strcat(cmd2,"/");
    strcat(cmd2,"output2.txt");
    cout<< cmd2<<endl;
    //std::string cmd_2(cmd2);
     system(cmd2);

    char cmd3[500]="\n";
     strcat(cmd3,path);
    strcat(cmd3,"/");
    strcat(cmd3,h);
     strcat(cmd3," <");
    strcat(cmd3,path);
    strcat(cmd3,"/");
  strcat(cmd3,"input3.txt >");
    strcat(cmd3,path);
     strcat(cmd3,"/");
    strcat(cmd3,"output3.txt");
    cout<< cmd3<<endl;
    //std::string cmd_3(cmd3);
     system(cmd3);

    char cmd4[500]="\n";
     strcat(cmd4,path);
    strcat(cmd4,"/");
    strcat(cmd4,h);
     strcat(cmd4," <");
    strcat(cmd4,path);
    strcat(cmd4,"/");
    strcat(cmd4,"input4.txt >");
    strcat(cmd4,path);
     strcat(cmd4,"/");
    strcat(cmd4,"output4.txt");
    cout<< cmd4<<endl;
    //std::string cmd_4(cmd4);
     system(cmd4);

    char cmd5[500]="\n";
     strcat(cmd5,path);
    strcat(cmd5,"/");
    strcat(cmd5,h);
     strcat(cmd5," <");
    strcat(cmd5,path);
    strcat(cmd5,"/");
    strcat(cmd5,"input5.txt >");
    strcat(cmd5,path);
     strcat(cmd5,"/");
    strcat(cmd5,"output5.txt");
    cout<< cmd5<<endl;
    //std::string cmd_5(cmd5);
     system(cmd5);
    
    char nameOut[500]="\n";
    sprintf(nameOut,"%s/%s",path,"output.txt");
    ofstream out_file(nameOut,ofstream::app);
    string outContent[100];
    string outLine;
    int num=0;
    //while(!getline(out_file,outLine))
   // {
   //     outContent[num]=outLine;
   //     cout <<"-----------------------"<<outContent[num];
   //     ++num;
    //}
    //for(int i=0;i<num;++i)
    //{
    //        out_file<<outContent[i];
   // }
        char out1[500]="\n";
        char out2[500]="\n";
        char out3[500]="\n";
        char out4[500]="\n";
        char out5[500]="\n";
        strcpy(out1,path);
        strcat(out1,"/");
        strcat(out1,"output1.txt");
        cout <<"!"<<out1<<endl;
        strcat(out2,path);
        strcat(out2,"/");
        strcat(out2,"output2.txt");
        strcat(out3,path);
        strcat(out3,"/");
        strcat(out3,"output3.txt");
        strcat(out4,path);
        strcat(out4,"/");
        strcat(out4,"output4.txt");
        strcat(out5,path);
        strcat(out5,"/");
        strcat(out5,"output5.txt");
        ifstream out_file1(out1);
        ifstream out_file2(out2);
        ifstream out_file3(out3);
        ifstream out_file4(out4);
        ifstream out_file5(out5);
        string line;
        out_file << name<<endl;
        getline(out_file1, line);
        out_file << line<<" ";
        getline(out_file2, line);
        out_file << line<<" ";
        getline(out_file3, line);
        out_file << line<<" ";
        getline(out_file4, line);
        out_file << line<<" ";
        getline(out_file5, line);
        out_file << line<<" "<<endl;
        //getline(in_file, line);

}
void findDir(char *path)
{
        DIR              *pDir ;
        struct dirent    *ent  ;
        int               i=0  ;
        char              childpath[512];

        pDir=opendir(path);
        memset(childpath,0,sizeof(childpath));

        while((ent=readdir(pDir))!=NULL)
        {
                if(ent->d_type & DT_DIR)
                {
                 	if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)
                                continue;
                        sprintf(childpath,"%s/%s",path,ent->d_name);
                        cout <<childpath<<endl;
                        findDir(childpath);
                }
				else
				{
					cout<<ent->d_name<<endl;
                                        if(strcmp(ent->d_name,"stdin_format.txt")!=0&&strcmp(ent->d_name,"input1.txt")!=0&&strcmp(ent->d_name,"input2.txt")!=0&&strcmp(ent->d_name,"input3.txt")!=0&&strcmp(ent->d_name,"input4.txt")!=0&&strcmp(ent->d_name,"input5.txt")!=0)
                                        {
                                                if(strstr(ent->d_name,".cpp")!=NULL)
                                                {
                                                        char formatpath[512];
                                                        sprintf(formatpath,"%s/%s",path,ent->d_name);
                                                        command(formatpath,path,ent->d_name);
                                                }
                                        }
				}
        }
}