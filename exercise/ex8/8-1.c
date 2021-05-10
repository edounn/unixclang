#include <stdio.h>

void Mystery(int* a, int* b, int c) {
            a = b + c;
            b = 0;
            c = 0;
}
int main() {
            int x = 0, y = 1, z = 2;
            Mystery(x, y, z);
            printf("%d    %d   %d  \n\n", x, y, z);
            Mystery(&x, &y,  z);
            printf("%d    %d   %d  \n\n", x, y, z);
}
