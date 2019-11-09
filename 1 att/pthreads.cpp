#include <pthread.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
bool isPalindrome=true; /* общие данные для потоков */


void *runner(void *p);

int main(int argc, char *argv[]){
  pthread_t tid; /* идентификатор потока */
  pthread_attr_t attr; /* атрибуты потока */




  /* получаем дефолтные значения атрибутов */
  pthread_attr_init(&attr);

  /* создаем новый поток */
  pthread_create(&tid,&attr,runner,argv[1]);

  /* ждем завершения исполнения потока */
  pthread_join(tid,NULL);
  if(isPalindrome){
  	printf("%s\n","YES" );
  }else{
  	printf("%s\n","NO" );
  }


}

  /* Контроль переходит потоковой функции */
void *runner(void *p){
  char* pChar = (char*)p;
  int left = 0,right = strlen(pChar)-1;
  while(left != strlen(pChar)/2){
  	if(pChar[left] != pChar[right]){
  		isPalindrome = false;
  		break;
  	}
  	left++;
  	right--;
  }

  pthread_exit(0);
}