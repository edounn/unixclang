#include <stdio.h>

int main()

{

   int memNum = 351;

   float cost = 123.45;

   double price = 123.45;

   char letter = 'Q';



   printf("\n**Integer outputs**\n");



   printf("My   CS Club  has %d Members\n", memNum);

   printf("My   CS Club  has %10d Members\n", memNum);

   printf("My   CS Club  has %-10d Members\n", memNum);

   printf("My   CS Club  has %2d Members\n", memNum);



   printf("\n**float outputs**\n");



   printf("Your total is $%f today\n", cost);

   printf("Your total is $%e today\n", cost);

   printf("Your total is $%.2f today\n", cost);

   printf("Your total is $%9.2f today\n", cost);



   printf("\n**double outputs**\n");



   printf("Your total is $%f today\n", price);

   printf("Your total is $%e today\n", price);

   printf("Your total is $%.2f today\n", price);

   printf("Your total is $%9.2f today\n", price);



   printf("\n**char/string outputs**\n");



   printf("%s%c%s\n", "*  ", letter, "  *");

   printf("%s%10s%-10sEND\n", "Hello", "Alice", "Bob");          }
