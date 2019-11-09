

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int number=0;//Our parameter via command line
    pid_t pid; //our process identifier
    while(number<=0){ //Our parameter should be positive
        if(number<=0){ //Alert if it is not positive or 0
            printf("(TRY AGAIN: Number should be positive)\n");
        }
        printf("Enter the number: "); 
        scanf("%d", &number); 
    }   
    pid = fork(); //create child process
    if (pid == 0){//child process
        printf("\n<<CHILD PROCESS EXECUTING>>\n");
        printf("Our number: %d\n Sequence: %d ",number,number);
            while (number!=1)//wait the end of sequence
            {
                if(number%2 == 0)//even
                {
                    number = number/2;
                }
                else if (number%2 == 1)//odd
                {
                    number = 3 * number + 1;
                }   
            
                printf("%d ",number); //print element of the sequence
            }
        
            printf("\n<<CHILD EXECUTION ENDS>>\n");//child ends execution
        }
        else//parent process
        {
            printf("\n<<WAITING FOR CHILD COMPLETION>>\n");
            wait(NULL);//waiting for child completion
            printf("\nMY CHILD IS DONE! I AM DONE TOO!\n<<PARENT EXECUTION ENDS>>\n");
        }
    return 0; 
}