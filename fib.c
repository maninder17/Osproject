#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int fibo[100];

void *fibos(void *term)
{	
	int next=(intptr_t)term;
	int i, k;
	printf("\nFibbonacci Series:\n ");
	fibo[0]=0;
	fibo[1]=1;
	for(k=2;k<next;k++)
	{
		fibo[k]=fibo[k-1]+fibo[k-2];
	}
	for(i=0; i<next; i++)
	{
		printf("\t%d", fibo[i]);
	}
}

int main()
{
	pthread_t t;
	printf("\nEnter a no: ");
	int inp;
	scanf("%d",&inp);
	pthread_create(&t,NULL,fibos,(void*)(intptr_t)inp);
	pthread_join(t,NULL);
	
}


