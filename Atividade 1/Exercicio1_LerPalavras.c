#include <stdio.h>

int main()
{
    char p1[50], p2[50], p3[50];

    printf("Digite suas 3 palavras:\n ");
    scanf("%s %s %s", p1, p2, p3);

    printf("Essa sera a ordem inversa: %s %s %s", p3, p2, p1);

    return 0;
}