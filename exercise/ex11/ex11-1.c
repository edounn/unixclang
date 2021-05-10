#include <stdio.h>

main(int argc, char **argv) {

          char *newargv[3];

          int i, j;



          newargv[0] = "cat";

          newargv[1] = "f1";

          newargv[2] = NULL;



          j = 0;

          while (j < 4) {

                   j++;

                   if (fork() == 0) {

                             i = execvp("cat", newargv);

                   } else {

                             wait(&i);

                   }

          }

}
