/*
 * NAME : Eddie Dounn
 * CS 4350 – 251 - Unix Systems Programming
 * Assignment Number: Homework 4
 * Due Date: 3 / 31 / 2021
 */

#include <stdio.h>
#include <stdlib.h>  // for rand(), srand()
#include <time.h>    // for time()
#include <unistd.h>

int randomGenerator(int now);
int countDesiredSumAttempts();
int counter = -1;


// One function to generate the random number
int randomGenerator(int now){
  int i, a, b, sum;
  time_t t;
  // Seed the random number generator with current time
  srand(time(0));   // need <cstdlib> and <ctime> header
  //srand((unsigned) time(&t));     //trying a different attemp hoping random numbers generate more quickly
  a = (rand() % 10) + 1;
  b = (rand() % 10) + 1;

  sum = a + b;

  printf("Generating First Number : %d\n", a);
  printf("Generating second Number : %d\n\n", b);
  printf("The sum of the generated numbers is : %d\n\n", sum );
  countDesiredSumAttempts();
  return sum;

}
// second function to calculate the number of times it took to find
//the desired sum .
int countDesiredSumAttempts(){

   counter ++;

  return counter;
}
//Functions are called from your main program
int main() {
  int a, b, tries;
  int finish = 0;
  a = (rand() % 10) + 1;
  b = (rand() % 10) + 1;
  int originalSum;
  int currentSum = -1;
  originalSum = a + b;


  /* using time to print the date at the bottom of sample 3/31/21 */
  int day, month, year;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  day = local->tm_mday;            // get day of month (1 to 31)
  month = local->tm_mon + 1;       // get month of year (0 to 11)
  year = local->tm_year + 1900;    // get year since 1900

  printf("Practicing C Programming Language");
  printf("\n\n\n");
  printf("First Generated Number : %d\n", a);
  printf("Second Generated Number : %d\n\n", b);
  printf("First Number + Second Number = %d\n\n", originalSum );
  printf("Processing . . . . . . . \n\n\n" );

  do{
    sleep(1);  //ADDING THIS so that random numbers don't pop up the same over and over.  this shortens the list of tries
    currentSum = randomGenerator(now);
    tries = countDesiredSumAttempts();

    //printf("genrand and current sum = %d\n\n", currentSum );
    //printf("tries %d\n\n", tries );
    if(currentSum == originalSum){
      printf("Number of Times the Numbers were Generated Before the Desired sum was reached = %d\n\n", countDesiredSumAttempts());
      printf("Implemented By Eddie Dounn \n");
       printf(" %02d/%02d/%d\n", month, day, year);
      finish = 1;
    }
  }while(finish < 1);

}
