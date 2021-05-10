/*
 * NAME : Eddie Dounn
 * CS 4350 – 251 - Unix Systems Programming
 * Assignment Number: Homework 6
 * Due Date: 4 / 21 / 2021
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <string.h>
 #include <signal.h>



//#2 create file with system command.
void systemCreateFile(char *command, char *fileName){
  //char fileName[50];

   strcat (strcpy (command, "touch "), fileName);
   //strcpy(command, "ls -l");
   system(command);

}

//#3 System Command to display permission status
void sysFileStat(char *command, char *fileName){
     strcat (strcpy (command, "ls -l  "), fileName);
     //strcpy(command, "ls -l");
     system(command);


}
//#4 change file mode to 700
void fileMode(char *command, char *fileName){
     strcat (strcpy (command, "chmod 700 "), fileName);
     //strcpy(command, "ls -l");
     system(command);


}



 int main() {
   FILE *fp;  //file pointer allocated
   char fileName[20];
   char command[50];
   printf("Enter name: ");
   scanf("%s", fileName);

   pid_t pid, pgid, child_pid;



   printf("\nSystem / File Manipulation Program");
   printf("\n\n\n");

   //#1
   systemCreateFile(command, fileName);
   printf("\n\n1. Enter File name to be created: %s", fileName);
   //#2
   printf("\n2. %s File is created", fileName);

   //3
   printf("\n3. Permission status is: \n");
   sysFileStat(command, fileName);
   printf("\n");
   //#4

   printf("4. File mode changed");
   fileMode(command,fileName);

   //#5

   printf("\n5. Permission status is: \n");
   sysFileStat(command, fileName);

   //6
   fp = fopen(fileName, "w+");
   fputs("Texas State University , Spring 2021 , Unix Programming", fp);
   printf("\n6. Text is appended to the file. ");

   //7
   fclose(fp);
   printf("\n7. File is closed. ");

   //8
   printf("\n8. Content of the input file: \n");
   strcat (strcpy (command, "cat "), fileName);
   system(command);

   //9
   printf("\n9. Current date and time is : ");
   strcpy (command, "date ");
   system(command);
   //10
   printf("\n10. Time of last file access : \n");
   strcat (strcpy (command, "ls -ltu "), fileName);
   system(command);
   //11
   printf("\n11. The content of the created file is: \n");
   strcat (strcpy (command, "cat "), fileName);
   system(command);
   //12
   printf("\n12. System name:");
   strcpy (command, "hostname -d ");
   system(command);
   //13
   printf("\n13. Local host name:");
   strcpy (command, "hostname -d ");
   system(command);

   //14
   printf("\n14. Host name :");
   strcpy (command, "hostname -d ");
   system(command);

   //15
   //printf("\n15. The process id:\n");
  //strcpy (command, "ps ");
   //system(command);
   pid = getpid();
   printf("\n15. The process id: %d", pid);

   //16
   pgid = getpgrp();
   printf("\n16. Parent process id: %d", pgid);

   //17
   printf("\n17. The file Name is %s", fileName);
   //18
   printf("\n18. The file Name is %s", fileName);
   strcpy (command, "hostname -s ");
   system(command);
    //19
   printf("\n19. The device is :\n");
   strcat (strcpy (command, "stat "), fileName);
   system(command);
//20 21
   printf("\n20. The inode is:\n");
   printf("\n21. File Protection:\n");
   strcat (strcpy (command, "stat %f"), fileName);
   system(command);
   //22 - 27
   printf("\n22 - 27. Number of devices and info:\n");
   strcpy (command, "fdisk -l");
   system(command);

   //32
   printf("\n32. Renamed The file to be p6in-2.txt");
   strcat (strcat (strcpy (command, "mv "), fileName), " p6in-2.txt") ;
   system(command);
   //33
   printf("\n33. The content of the new p6in-2.txt file :\n");
   strcpy (command, "cat p6in-2.txt");
   system(command);

   //34
   printf("\n34. The current date and time : \n");
   strcpy (command, "date ");
   system(command);

   //3535. Removed p6in-2.txt files from current Directory.
    printf("\n35. Removed p6in-2.txt files from current Directory. ");
    strcpy (command, "rm p6in-2.txt");
    system(command);
    //36
    printf("\n36. The content of the new p6in-2.txt file :\n");
    strcpy (command, "cat p6in-2.txt");
    system(command);

   printf("\n\nApril – 2021 \n");
   printf("Eddie Dounn \n");

   return(0);
 }
