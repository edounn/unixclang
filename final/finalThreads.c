// Program is written by Eddie Dounn
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>


pthread_mutex_t mutex;

void* addFiveGetOdd(void *x) {
  int final = *(int *) x;
  pthread_mutex_lock(&mutex);
  int withFive = final + 5;
  int i;
  printf("Thread 1:  X= %d\n", withFive);
  printf("All Odd numbers are: ");
  for (i = 1; i <= withFive; i += 2) {
    printf(" %d ", i);
   }

  printf("\n");
  pthread_mutex_unlock(&mutex);
  return 0;
}

void* addTenGetEven(void *x) {
   int final = *(int *) x;
  pthread_mutex_lock(&mutex);
  int withFive = final + 15;
  int i;

  printf("Thread 2:  X= %d\n", withFive);
  printf("All even numbers are: ");
  for (i = 3; i <= withFive; i += 2) {
    printf(" %d ", i);
   }

  printf("\n");
  pthread_mutex_unlock(&mutex);
  return 0;
}

void* squareX(void *x){
  int final = *(int *) x;
  int sq = pow (final, 2);
  pthread_mutex_lock(&mutex);
  printf("thread 3: X = %d \n", sq);
  pthread_mutex_unlock(&mutex);

  return 0;
}

int main(int argc, char* argv[]){
  pthread_t p1, p2, p3;
  pthread_mutex_init(&mutex, NULL);
  int x = 0;

  printf("\nEnter an Integer > 0 --->  ");
  scanf("%d", &x);

  if(x < 0){
    printf("\n**** Number positive ***\n");
    return 0;
  }

  if (pthread_create(&p1, NULL, &addFiveGetOdd, &x) != 0) {
        return 1;
  }
  if (pthread_create(&p2, NULL, &addTenGetEven, &x) != 0) {
       return 2;
  }
  if (pthread_create(&p3, NULL, &squareX, &x) != 0) {
        return 3;
  }
  if (pthread_join(p1, NULL) != 0) {
        return 5;
  }
  if (pthread_join(p2, NULL) != 0) {
        return 6;
  }
  if (pthread_join(p3, NULL) != 0) {
        return 7;
  }

  pthread_mutex_destroy(&mutex);
  return 0;
}
