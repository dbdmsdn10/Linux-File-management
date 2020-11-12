#include <stdio.h>
int main()
{
    char s1[30];
    printf("이름을 입력하시오: ");
    scanf("%[^\n]",s1);
    char s2[30];
    printf("학번을 입력하시오: ");
    scanf(" %[^\n]",s2);
    addlist(s1,s2);
}
