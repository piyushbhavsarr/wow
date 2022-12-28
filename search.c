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

void search() {
  int i, j, cnt = 0, lno = 0, p;
  char buff[100][80], temp[20], op[5], pattern[20];
  sscanf(cmd, "%s %s %s %s", inst, op, pattern, fn);
  fp = fopen(fn, "r");
  if (fp == NULL)
    printf("file not found");
  else {
    while (!feof(fp)) {
      fgets(buff[lno], 80, fp);
      for (i = 0; i < strlen(buff[lno]); i++) {
        if (buff[lno][i] == pattern[0]) {
          p = i;
          for (j = 0; j < strlen(pattern); j++, p++) {
            temp[j] = buff[lno][p];
          }
          temp[j] = '\0';
          if (strcmp(temp, pattern) == 0) {
            if (strcmp(op, "c") == 0) {
              cnt++;
            } else if (strcmp(op, "f") == 0) {
              printf("Match found != %s", buff[lno]);
              goto l2;
            } else if (strcmp(op, "a") == 0) {
              printf("Match found != %d %s", lno, buff[lno]);
              goto l1;
            } else {
              printf("Match not found ");
              goto l2;
            }
          }
        }
      }
    l1:
      lno++;
      if (lno > 99)
        break;
    }
  }
  if (strcmp(op, "c") == 0)
    printf("count : %d", cnt);
l2:
  fclose(fp);
}

int main()
{
	int i,status=0;
	char op[50],tok[50];
	pid_t pid;
	while (strcmp(tok,"exit")!=0)
	{
		printf("\n\nmyshell$");
		i=-1;
		do
		{
			i++;
			cmd[i]=getchar();
		}while (cmd[i]!='\n');
		cmd[i++]='\0';
		sscanf(cmd,"%s",tok);
		if (strcmp(tok,"search"==0)
				search();
		else
		{
			pid=fork();
			if (pid==0)
			{
				system(cmd);
				exit(0);
			}
			pid=waitpid(pid,&status,0);
		}
	}
	return;
}
