#include <stdio.h>

enum foo1
{
    a=1,b
};
enum foo2
{
    c,d
};
int main()
{
    enum foo1 s1=c;
    enum foo1 s=a;
    enum foo2 s2=d;
    printf("%d",s);
    printf("%d",s1);
    printf("%d",s2);
}
