#include <stdio.h>

int main()
{
    int v[5];

    printf("Digite 5 numeros: ");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("Sua ordem inversa: ");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d", v[i]);
    }
    return 0;
}