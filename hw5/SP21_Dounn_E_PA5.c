/*
 * NAME : Eddie Dounn
 * CS 4350 – 251 - Unix Systems Programming
 * Assignment Number: Homework 4
 * Due Date: 4 / 12 / 2021
 */
 #include <stdio.h>
 #include <stdlib.h>  // for rand(), srand()
 #include <time.h>    // for time()
 #include <unistd.h>
 #include <ctype.h>
 #include <string.h>
#define BUFFER_SIZE 1000

void createFile(FILE *fp){
  //FILE *fp;
  fp = fopen("pa5in.txt", "w+");
  printf("File Created.\n");

  /*  adding to file.
  *  CS4350 - 251
  *  Unix Programing ; SP 2021
  *  PA # 5;
  *  Due Date 4/2/21
  */
  fputs("CS4350 - 251\nUnix Programing ; SP 2021\nPA # 5;\nDue Date 4/2/21", fp);
  printf("Text Written.\n");
  fclose(fp);
  //printf("File closed.\n");

  
  //return fp;
}

void closeFile(FILE *fp){
  fclose(fp);
  printf("File closed.\n");

}

void displayFile(FILE *fp){
  char buffer[BUFFER_SIZE];
  //char buffer[100];
  int totalRead = 0;
  fp = fopen("pa5in.txt", "r");
  printf("File Open.\n");
  //fscanf(fp, "%s", buffer);
  printf("\n---File pa5in.txt Content------\n");
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        /* Total character read count */
        totalRead = strlen(buffer);


        /*
         * Trim new line character from last if exists.
         */
        buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'
                                    ? '\0'
                                    : buffer[totalRead - 1];


        /* Print line read on cosole*/
        printf("%s\n", buffer);

    }
  fclose(fp);
  printf("\n---End Of FILE Contents------\n");


}

void displaySecondFile(FILE *fp2){
  char buffer[BUFFER_SIZE];
  //char buffer[100];
  int totalRead = 0;
  fp2 = fopen("pa5o1.txt", "r");

  //fscanf(fp, "%s", buffer);
  printf("\n---File pa5o1.txt Content------\n");
    while(fgets(buffer, BUFFER_SIZE, fp2) != NULL)
    {
        /* Total character read count */
        totalRead = strlen(buffer);


        /*
         * Trim new line character from last if exists.
         */
        buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'
                                    ? '\0'
                                    : buffer[totalRead - 1];


        /* Print line read on cosole*/
        printf("%s\n", buffer);

    }
  fclose(fp2);
  printf("\n---End Of FILE Contents------\n");


}

void countLines(FILE *fp){
  char c;  // To store a character read from file
  int count = 0;
  fp = fopen("pa5in.txt", "r");  //#3 open file
  printf("File Open.\n");
  for (c = getc(fp); c != EOF; c = getc(fp))
      if (c == '\n') // Increment count if this character is newline
          count = count + 1;

  // Close the file
  fclose(fp);
  printf("The file has %d lines\n ", count);

}

void countWordsLinesCharacters(FILE *fp){
   char ch;
   int characters, words, lines;


   fp = fopen("pa5in.txt", "r");
   //printf("File Open.\n");
   /* Check if file opened successfully */
   if (fp == NULL)
   {
       printf("\nUnable to open file.\n");
       exit(EXIT_FAILURE);
   }

   /*
    * Logic to count characters, words and lines.
    */
   characters = words = lines = 0;
   while ((ch = fgetc(fp)) != EOF)
   {
       characters++;

       /* Check new line */
       if (ch == '\n' || ch == '\0')
           lines++;

       /* Check words */
       if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
           words++;
   }

   /* Increment words and lines for last word */
   if (characters > 0)
   {
       words++;
       lines++;
   }


   printf("\n-- File statistics --\n");
   printf("Total characters = %d\n", characters);
   printf("Total words      = %d\n", words);
   printf("Total lines      = %d\n", lines);

   fclose(fp);

}

void characterDigitCount(FILE *fp){
  char Character = 0;
  int words = 0;
  int upper_case = 0;
  int lower_case = 0;
  int punctuation = 0;
  int digits = 0;
  int entered_words = 0;


  fp = fopen("pa5in.txt", "r");
  //printf("File Open.\n");

  if (fp == NULL)
    {
        printf("\nError, Unable to open the file for reading\n");
    }

    while((Character = fgetc(fp)) != EOF)
    {

                if (isalnum (Character))
                {
                    if (!entered_words)
                    {
                        entered_words = 1;
                        words++;
                    }
                }


                else
                {
                    if (entered_words)
                    {
                        entered_words = 0;
                    }
                }


                if (isupper(Character))
                {
                    upper_case++;
                }


                else if (islower(Character))
                {
                    lower_case++;
                }


                else if (isdigit(Character))
                {
                    digits++;
                }


                else if (ispunct(Character))
                {
                    punctuation++;
                }
    }

    fclose(fp);

    printf("Total number of digits are %d.\n", digits);
    printf("Total number of uppercase letters is %d.\n", upper_case);
    printf("Total number of lowercase letters is %d.\n", lower_case);
    printf("Total number of Special Symbols is %d.\n", punctuation);

}

void capitalLowerSwap(FILE *fp, FILE *fp2){
  fp = fopen("pa5in.txt", "r");
  fp2 = fopen("pa5o1.txt", "r");
  char ch;
  while((ch=fgetc(fp))!=EOF)
      {
            ch = toupper(ch);
            fputc(ch,fp2);
      }
      printf("\nFile successfully copied with character capitalization swapped\n");

}




 int main() {
   FILE *fp, *fp2;  //file pointer allocated


   printf("\nFile Manipulation Program");
   printf("\n\n\n");

   createFile(fp);
   fclose(fp);  //#3 close file


   displayFile(fp);  //#4 display contents of file

   //countLines(fp);  //#5 counts lines
   countWordsLinesCharacters(fp);   //#5 - #13
   characterDigitCount(fp); //#5 - #13
   capitalLowerSwap(fp,fp2);  //#14
   displaySecondFile(fp2);
   printf("\n\nImplemented By Eddie Dounn \n");
   printf("April – 12 – 2021 \n");

   return(0);
 }
