#include"compare.h"
int maxnum=100;
void compare()
{
     ofstream out_file1("./output/equal.csv",ofstream::app);
     ofstream out_file2("./output/inequal.csv",ofstream::app);
     out_file1<<"file1"<<","<<"file2"<<endl;
     out_file2<<"file1"<<","<<"file2"<<endl;
     out_file1.close();
     out_file2.close();
     findOutput("./input");
}
void writeIn(char path1[500],char name[500])
{
    char path[500];
    strcpy(path,path1);
    char allname[500];
    sprintf(allname,"%s/%s",path,name);
    ifstream output(allname);
    string line;
    allcpp cpp[maxnum];
    while(getline(output,line))
    {
        cpp[cpp->get_cnt()].set_name(line);
        getline(output,line);
        cpp[cpp->get_cnt()].set_res(line);
        cpp->add_cnt();
    }
    ofstream out_file1("./output/equal.csv",ofstream::app);
    ofstream out_file2("./output/inequal.csv",ofstream::app);
    string path2=path;
    path2.erase(0,2);
    for(int i=0;i<cpp->get_cnt();++i)
    {
            for(int j=i+1;j<cpp->get_cnt();++j)
            {
                    if(cpp[i].get_res()==cpp[j].get_res())
                    {
                        //char name1[500],iname[500],jname[500];
                        string name1,iname,jname;
                        
                        name1=path2;
                        iname=name1+"/"+cpp[i].get_name();
                        jname=name1+"/"+cpp[j].get_name();
                        out_file1<<iname<<","<<jname<<endl;
                    }
                    else
                    {
                        string name1,iname,jname;
                        name1=path2;
                        iname=name1+"/"+cpp[i].get_name();
                        jname=name1+"/"+cpp[j].get_name();
                        out_file2<<iname<<","<<jname<<endl;
                    }
            }
    }
}
void findOutput(char *path)
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
                        cout <<"compare ------ chilepath"<<childpath<<endl;
                        findOutput(childpath);
                }
				else
				{
                                        if(strcmp(ent->d_name,"output.txt")==0)
                                        {
                                                char formatpath[512];
                                                sprintf(formatpath,"%s/%s",path,ent->d_name);
                                                writeIn(path,ent->d_name);
                                        }
				}
        }
}