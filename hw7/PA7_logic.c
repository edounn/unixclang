#include <stdio.h>


void getOdd(int x) {
  printf("All odd numbers between 1 and %d:\n", x);
  int i;
  for (i = 1; i <= x; i += 2) {
    printf("Function1: %d:\n", i);
  }
  printf("\n");
}
void getEven(int x) {
  printf("All Even numbers between 1 and %d:\n", x);
  int i;
  for (i = 2; i < x; i += 2) {
    printf("Function2: %d:\n", i);
  }
  printf("\n");
}
void getSpecial(int x) {
  printf("Function3 – Sequenced Process Started\n");
  printf("Input Number %d\n", x);
  while (x != 1) {
    printf("%d ", x);
    if (x % 2 == 0) {
      x = x / 2;
    } else x = 3 * x + 1;
  }
  printf("%d", x);
  printf("\n\n");
}
void getArmstrong(int x) {
  printf("Function4 - Armstrong Process Started \n");
  int ans = 0, t = x, r;
  while (x != 0) {
    r = x % 10;
    ans = ans + r * r * r;
    x = x / 10;
  }

  if (t == ans) {
    printf("Given number is an Armstrong number.\n");
  } else printf("Given number is not an Armstrong number.\n");
}
int main() {
  int x, i;
  printf("Enter the value of X:");
  scanf("%d", & x);

 if(x < 4){
    printf("\n**** Number must be grantor than 4 ***\n");
    printf("\nProgram by Eddie Dounn");
    printf("\n4 – 30 -21 \n");
    return 0;
  }


  getOdd(x);
  getEven(x);
  getSpecial(x);
  getArmstrong(x);
  return 0;
}
