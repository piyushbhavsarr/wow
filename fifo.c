#include<stdio.h>
int main()
{
    int frame[10];
    int i,j,k,p,nframe,mp=0,page[50];
    int flag=0, pfault=0, pos=0;
    printf("no of frames :");
    scanf("%d",&nframe);
    for(i=0;i<nframe;i++)
        frame[i]=-1;
    printf("Enter no of pages :");
    scanf("%d",&p);
    printf("enter the strng :");
    for(i=0;i<p;i++)
        scanf("%d",&page[i]);
    for(i=0;i<p;i++)
    {
        flag=0;
        for(j=0;j<nframe;j++)
        {
            if(frame[j]==page[i])
            {
                printf("\nHit: \t");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[pos]=page[i];
            pos++;
            printf("\nFault:  ");
            pfault++;
            if(pos>=nframe)
                pos=0;
        }
        for(k=0;k<nframe;k++)
            printf("%d\t",frame[k]);
    }
    printf("\nNumber of page faults is : %d ",pfault);
    return 0;
}
