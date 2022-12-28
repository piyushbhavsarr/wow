#include<stdio.h>
int main()
{
	int nof,nop,frames[10],pages[30],temp[10],flag1,flag2,flag3,i,j,k,pos,max,faults;
	
	printf("Enter Number of Frames : ");
	scanf("%d",&nof);
	
	printf("Enter Number of Pages : ");
	scanf("%d",&nop);
	
	printf("Enter Reference String : \n");
	
	for (i=0;i<nop;i++)
		scanf("%d",&pages[i]);
		
	for (i=0;i<nop;i++)
	{
		flag1=flag2=0;
		for (j=0;j<nof;++j)
		{
			if(frames[j]==pages[i])
			{
				flag1=flag2=1;
				break;
			}
		}
		
		if(flag1==0)
		{
			for(j=0;j<nof;++j)
			{
				if(frames[j]==-1)
				{
					faults++;
					frames[j]=pages[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			flag3=0;
			for (j=0;j<nof;++j)
			{
				temp[j]=-1;
				for(k=i+1;k<nop;++k)
				{
					if(frames[j]==pages[k])
					{
						temp[j]=k;
						break;
					}
				}	
			}
			for(j=0;j<nof;++j)
			{
				if(temp[j]==-1)
				{
					pos=j;
					flag3=1;
					break;
				}
			}
			if(flag3==0)
			{
				max=temp[0];
				pos=0;
				for(j=1;j<nof;++j)
				{
					if(temp[j]>max)
					{
						max=temp[j];
						pos=j;
					}
				}
			}
			frames[pos]=pages[i];
			faults++;
		}
		printf("\n");
		
		for(j=0;j<nof;++j)
			printf("%d\t",frames[j]);		
	}
	printf("\n\n Total Page Faults : %d ",faults);
	return 0;
}
