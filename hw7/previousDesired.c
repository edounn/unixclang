/*
NAME: Eddie Dounn   CS 4350 – Unix Systems Programming
Assignment Number: hw7 Which will replace my Lowest Programming Assignment’s Grade.
Due Date: 4 / 30 / 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>   //required header for thread, gcc -lpthread
#include <sys/wait.h>
#include <unistd.h>


void err_sys(char* message) {
  perror(message);
  exit(EXIT_FAILURE);
}
void getOdd(int x) {
  printf("\nAll odd numbers between 1 and %d:\n\n", x);
  int i;
  for (i = 1; i <= x; i += 2) {
    printf("Function1: %d:\n", i);
   }
   printf("\n");
}

void getEven(int x) {
  printf("All Even numbers between 1 and %d:\n\n", x);
  int i;
  for (i = 2; i < x; i += 2) {
    printf("Function2: %d:\n", i);
  }
  printf("\n");
}

void getSpecial(int x) {
  printf("Function3 – Sequenced Process Started\n");
  printf("Input Number %d\n\n", x);
  while (x != 1) {
    printf("%d ", x);
    if (x % 2 == 0) {
      x = x / 2;
    } else x = 3 * x + 1;
  }
  printf("%d", x);
  printf("\n\n");
}

void getArmstrong(int x){
  int orig = x;
  printf("Function4 - Armstrong Process Started \n");
  int ans = 0, t = x, r;
  while (x != 0) {
    r = x % 10;
    ans = ans + r * r * r;
    x = x / 10;
  }
  //debuging getting Armstrong number
  //
  if (t == ans) {
    printf("%d is an Armstrong number.\n" , orig);
  } else printf("%d is not an Armstrong number.\n", orig);
}

void myName(){
  printf("\nProgram by Eddie Dounn");
  printf("\n4 – 30 -21 \n");
}

void *signature(){
  printf("\nProgram by Eddie Dounn");
  printf("\n4 – 30 -21 \n");
  return NULL;
}


/* program assignment header moved to make main easier to deal with */
void getHeader(){
  printf("\nWelcome to Eddie Dounn's Thread App\n");    //class question: sample runs say "Process App", "App", "Thread App"  unsure which?
  printf("\nThis program will do the following:");
  printf("\n");
  printf("\nAccepts an integer number X from the user and then uses 4 \nchild processes in order to do the following:\n\n");
  printf("1.The first process prints all odd numbers between 1 and X.\n");
  printf("2.The second process prints all the even numbers between 1 and X.\n");
  printf("3.The third process print the special sequence for the number X.\n");
  printf("4.The last process determines whether or not X is an Armstrong number.\n");
}

//assignment note use fork with wait and signal for sync.
int main(int argc, char* argv[]){
  int x, i;
  pid_t child_pid;
  //pthread_t t1;
  getHeader();
  printf("\nEnter an Integer > 4 --->  ");
  scanf("%d", & x);

  if(x < 4){
    printf("\n**** Number must be grantor than 4 ***\n");
    myName();
    return 0;
  }

  getOdd(x);
  getEven(x);
  getSpecial(x);
  getArmstrong(x);


  myName();

  //myName with thread
  //pthread_create(&t1, NULL, &signature, NULL);
  //pthread_join(t1, NULL);

  return 0;


}
