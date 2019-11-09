#include <pthread.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

char buffer[10];
int empty = 10, mutex = 1, full = 0, controller = 0,produced=0,consumed=0;

int wait(int controller){
	if(controller>0){
		return (controller-1);	
	}return controller;
}

int signal(int controller){
	return (controller+1);
}


void producer(){
	
	if ((mutex==1)&&(empty!=0)){
	controller++;
	empty = wait(empty);
	mutex = wait(mutex);
	
	buffer[controller]=controller;
	
	mutex = signal(mutex);
	full = signal(full);
	printf("%s","Produce product #");
	printf("%d\n",buffer[controller]);
	produced++;
}else{
	printf("FULL\n");
	
}
printf("BUFFER SIZE:%d\n",controller);

	
}

void consumer(){
	if ((mutex==1)&&(full!=0)){
	mutex = wait(mutex);
	full = wait(full);


	printf("%s","Consume product #");
	printf("%d\n",buffer[controller]);
	controller--;
	mutex = signal(mutex);
	empty = signal(empty);
	
	consumed++;
}else{
	printf("EMPTY\n");
}
	printf("BUFFER SIZE:%d\n",controller);

	
}

int main(){

	int n;
	while(true){
		
		printf("Options :-\n1. Produce item.\n2. Consume item.\n3. Exit.\n\nChoice : ");
		
		int choice;
		scanf("%d",&choice);
		printf("\n\n");

		switch(choice){
			case 1:
				producer();
				printf("\n\n");
			break;
			case 2:
				consumer();
				printf("\n\n");
			break;
			case 3:
			printf("Current BUFFER SIZE: %d\nProduced %d items\nConsumed %d items\n", controller,produced,consumed);
				exit(0);
			break;
		}
		// printf("%d\n", n);
	}

	return 0;
}