void typeline()
{
  int n=0,i,x,opt;
  char txt[100][1000],op[50];
  
  sscanf(cmd,"%s %s %s",inst,op,fn):
  fp=fopen(fn,"r");
  if(fp==NULL)
  {
    printf("File does not exist\n");
  }
  else
  {
    while(!feof(fp))
    {
      fgets(txt[n],90,fp);
      n++;
    }
    fclose(fp);
    if(op[0]=='a')
    {
      printf("\n All lines in the file are : ");
      for(i=0;i<n;i++)
      {
        printf("\n %s",txt[i]);
      }
    }
    else
    {
      opt=atoi(op);
      if(opt>0)
        x=0;
      else
      {
        x=n+opt-1;
        opt=n;
      }
      for(i=x;i<opt;i++)
        puts(txt[i]);
    }
  }
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
		if (strcmp(tok,"typeline")==0)
				typeline();
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
