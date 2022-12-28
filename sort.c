#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void Bubble_sort(int arr[30],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void insertion_sort(int arr[30],int n)
{
	 int i ,j ,temp;
	for(i=0;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && temp<=arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
		
	}
}
void fork1()
{
	int arr[25],arr1[25],n,i,status;
	printf("Enter the number of values in array :");
	scanf("%d",&n);
	printf("Enter the array element :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int pid=fork();
	if(pid==0)
	{
		sleep(10);
		printf("Child process \n");
		printf("Child process id = %d\n",getpid());
		insertion_sort(arr,n);
      		printf("Element sorted using insertion sort :");
		printf("\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\b");
		printf("\n Parent Process id = %d\n",getppid());
		system("ps -x");
		printf("\n\n\n");
	}
	else
	{
		printf("Parent process \n");
		printf("parent process id = %d \n",getppid());
		Bubble_sort(arr,n);
		printf("Element sorted using bubble sort:\n");
		printf("\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
			
		}
		printf("\n\n\n");
	}
}
int main()

{
	fork1();
	return 0;
}
