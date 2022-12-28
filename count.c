#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

FILE *fp;
char cmd[],fn[50],inst[50];

void count()
{
    char inst[50],opt[10],ch,ch1;
    int c=0,ln=0,wc=0;
    sscanf(cmd,"%s %s %s",inst,opt,fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("\n FILE DOESN'T EXIST");
        exit(0);
    }
    else
    {
        while(!feof(fp))
        {
            ch=fgetc(fp);
            c++;
            if(ch==' ' || ch=='\n' || ch=='\t')
            {
                if(ch1!=ch)
                    wc++;
            }
            if(ch=='\n')
                ln++;
        }
        ch1=ch;
    }
    fclose(fp);

    if(strcmp(opt,"l")==0)
        printf("\n No. of Lines in the file are :%d\n",ln);
    else if(strcmp(opt,"w")==0)
        printf("\n No. of words in the file are :%d\n",wc);
    else if(strcmp(opt,"c")==0)
        printf("\n No. of characters in the file are :%d\n",(c-1));
    else
        printf("\n Syntax is count <l/w/c><file name>\n");
}

int main()
{
    int i, j,status;
    char op[50],tor[50];
    pid_t pid;
    while(strcmp(tor,"exit")!=0)
    {
        printf("\n MYSHELL$ ");
        i=-1;
        do
        {
            i++;
            cmd[i]=getchar();
        } while(cmd[i]!='\n');
        cmd[i++]='\0';
        sscanf(cmd,"%s",tor);
        if(strcmp(tor,"count")==0)
        {
            count();
        }   
        else
        {
            pid=fork();
            if(pid==0)
            {
                system(cmd);
                exit(0);
            }
            pid=waitpid(pid,&status,0);
        }
    }
    return 0;
}
