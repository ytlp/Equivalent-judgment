#include "createInput.h"
#define N 100
int ICSdis(string str)
{
        if(str=="char")
                return 2;//char
        else
        {
                stringstream ss(str);
                string tmp;
                getline(ss, tmp, '(');
                if(tmp=="int")
                        return 1;//int
                else if(tmp=="string")
                        return 3;//string
        }
}
int ranInt(string str)
{
        stringstream ss(str);
        string tmp;
        int min;
        int max;
        getline(ss, tmp, '(');
        getline(ss, tmp, ',');
        std::istringstream s1(tmp);
        s1 >> min;
        getline(ss, tmp, ')');
        std::istringstream s2(tmp);
        s2 >>max;
        //srand((int)time(0));
        return min+rand()%(max-min);
}
char ranChar(string str)
{
        int min=65;
        int max=122;
        char c;
        // srand((int)time(0));
         if(rand()%2==0)
                        c = 'a' + rand()%26;
                else
                        c = 'A' + rand()%26;
        return c;
}
string ranString(string str)
{
        stringstream ss(str);
        string tmp;
        int min;
        int max;
        getline(ss, tmp, '(');
        getline(ss, tmp, ',');
        std::istringstream s1(tmp);
        s1 >> min;
        getline(ss, tmp, ')');
        std::istringstream s2(tmp);
        s2 >>max;
        //srand((int)time(0));
        int len=min+rand()%(max-min);
        string res;
        char c;                     /*声明字符c，用来保存随机生成的字符*/
        int idx;                    /*用来循环的变量*/
        /*循环向字符串中添加随机生成的字符*/
        for(idx = 0;idx < len;idx ++)
        {
                /*rand()%26是取余，余数为0~25加上'a',就是字母a~z,详见asc码表*/
                if(rand()%2==0)
                        c = 'a' + rand()%26;
                else
                        c = 'A' + rand()%26;
                res.push_back(c);       /*push_back()是string类尾插函数。这里插入随机字符c*/
        }
        return res;
}
void readAndCreate(char* name,char*path)
{
        ifstream in_file(name);
        char input1[20]="input1.txt";
        char input2[20]="input2.txt";
        char input3[20]="input3.txt";
        char input4[20]="input4.txt";
        char input5[20]="input5.txt";
        char name1[20];
        char name2[20];
        char name3[20];
        char name4[20];
        char name5[20];
        sprintf(name1,"%s/%s",path,input1);
        sprintf(name2,"%s/%s",path,input2);
        sprintf(name3,"%s/%s",path,input3);
        sprintf(name4,"%s/%s",path,input4);
        sprintf(name5,"%s/%s",path,input5);
        ofstream out_file1(name1);
        ofstream out_file2(name2);
        ofstream out_file3(name3);
        ofstream out_file4(name4);
        ofstream out_file5(name5);
        string line;
        while( getline(in_file, line) ) 
        {
                stringstream ss(line);
                string tmp;
                while (getline(ss, tmp, ' ')) 
                {      
                        if(ICSdis(tmp)==1)//int
                        {
                                out_file1<< ranInt(tmp)<<" ";
                                out_file2<< ranInt(tmp)<<" ";
                                out_file3<< ranInt(tmp)<<" ";
                                out_file4<< ranInt(tmp)<<" ";
                                out_file5 << ranInt(tmp)<<" ";
                        }
                        else if(ICSdis(tmp)==2)//char
                        {
                                out_file1<< ranChar(tmp)<<" ";
                                out_file2<< ranChar(tmp)<<" ";
                                out_file3<< ranChar(tmp)<<" ";
                                out_file4<< ranChar(tmp)<<" ";
                                out_file5 << ranChar(tmp)<<" ";
                        }
                        else//string
                        {
                                out_file1<< ranString(tmp)<<" ";
                                out_file2<< ranString(tmp)<<" ";
                                out_file3<< ranString(tmp)<<" ";
                                out_file4<< ranString(tmp)<<" ";
                                out_file5 << ranString(tmp)<<" ";
                        }
                }
        }
}
void listDir(char *path)
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
                        listDir(childpath);
                }
				else
				{
					cout<<ent->d_name<<endl;
                                        if(strcmp(ent->d_name,"stdin_format.txt")==0)
                                        {
                                                char formatpath[512];
                                                sprintf(formatpath,"%s/%s",path,ent->d_name);
                                               readAndCreate(formatpath,path);
                                        }
				}
        }
}
void createInput()
{
     listDir("./input");
}