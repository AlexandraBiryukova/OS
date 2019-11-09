#include<stdio.h>
#include<stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

struct semaphore
{
	int mutex;
	int rcount;
	int rwait;
	bool wrt;
};

void addReader(struct semaphore *s)
{
	if (s->mutex == 0 && s->rcount == 0)
	{
		printf("\n<<<Writer is writing>>>.\n<<<Reader will wait>>>\n");
		s->rwait++;
	}else{
		printf("\n<<<New reader in system and he is reading>>>\n");
		s->rcount++;
		s->mutex--;
	}
}

void addWriter(struct semaphore *s)
{
	if(s->mutex==1)
	{
		s->mutex--;
		s->wrt=1;
		printf("\n<<<Writer is writing>>>\n");
	}else if(s->wrt){
		printf("\n<<<Writer already exists>>>\n");
	}
	else printf("\n<<<Readers are reading. Writer can not be added>>>\n");
}


void removeReader(struct semaphore *s){
	
	if(s->rcount == 0) printf("\n<<<No readers in the system>>>\n");
	else{
		printf("\n<<<Reader completes his reading>>>\n");

		s->rcount--;

		s->mutex++;

	}
}

void removeWriter(struct semaphore *s){

	if(s->wrt==0) printf("\n<<<Writer doesn't exist>>>");
	else{
		printf("\n<<<Writer completes his writing. It can be read>>>\n");

		s->mutex++;
		s->wrt=0;

		if(s->rwait!=0){
			s->mutex-=s->rwait;
			s->rcount=s->rwait;
			s->rwait=0;
			printf("<<<%d waiting readers can read now>>>",s->rcount);
		}

	}

}

int main()
{
	struct semaphore S={1,0,0};

	while(true){

		printf("CHOICE :\n1.Add new reader.\n2.Add writer.\n3.Remove reader.\n4.Remove writer.\n5.Exit.\n\n\tChoice : ");
		
		int n;
		scanf("%d",&n);

		switch(n){
			case 1: 
				addReader(&S); 
				break;
			case 2: 
				addWriter(&S); 
				break;
			case 3: 
				removeReader(&S); 
				break;
			case 4: 
				removeWriter(&S); 
				break;
			case 5: 
				return 0;
		}

		printf("\n---------------------------------\n-Mutex\t\t:\t%d\t-\n-Reading readers:\t%d\t-\n-Waiting readers:\t%d\t-\n-Writer Active\t:\t%s\t-\n---------------------------------\n\n", S.mutex, S.rcount, S.rwait, (S.mutex==0 && S.rcount==0) ? "YES" : "NO");


	}

}