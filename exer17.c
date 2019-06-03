#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int comparaString(char *str, char *str2);
void insertion(char **s, int n);

int main()
{

    char **vS;
    int n,i;

    printf("Digite o numero de strings:\n");
    scanf("%d", &n);
    getchar();

    vS = malloc(n * sizeof(char));
    for(i=0; i<n; i++)
        vS[i] = malloc(30 * sizeof(char));

    if(!vS){
            printf("nao foi possivel alocar\n");
            exit(1);
        }

    insertion(vS, n);

    for(i=0; i<n; i++)
        puts(vS[i]);

    return 0;
}


void insertion(char **s, int n)
{
    int i,j;
    char key[30];

    strcpy(s[0], key);

    for(i=0; i<n; i++){
        printf("Digite o nome:\n");
        scanf("%[^\n]s", key);
        getchar();

        j = i - 1;

        while(j >= 0 && comparaString(s[j], key)){
            strcpy(s[j+1], s[j]);
            j--;
        }
        strcpy(s[j+1], key);
    }
}

int comparaString(char *str, char *str2)
{
    char s1[30];
    char s2[30];
    char *aux;

    strcpy(s1, str);
    strcpy(s2, str2);

    aux = s1;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    aux = s2;
    while(*aux){
        *aux = tolower(*aux);
        aux++;
    }

    if(strcmp(s1, s2) > 0)
        return 1;

    return 0;
}
