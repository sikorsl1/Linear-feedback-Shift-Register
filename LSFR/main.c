#include <stdio.h>
#include <stdlib.h>

int getch(FILE *fp){
    int m = getc(fp);
    if(m == 32 || m == 10){
        m = getc(fp);
    }
    if(m == EOF)
        return 0;
    return m;
}

int and(int x, int y){
    if(x==1 && y==1)
        return 1;
    else
        return 0;
}

int xor(int x, int y){
    if(x==y)
        return 0;
    else
        return 1;
}

int main()
{
    FILE *fpr = fopen("dane.txt", "r");
    int L;
    fscanf(fpr, "%d", &L);
    int *D = malloc(L*sizeof(int));
    int i,j;
    for(i=0;i<L;i++){
        D[i] = getch(fpr)-'0';
    }
    int *S = malloc(L*sizeof(int));
    for(i=0;i<L;i++){
        S[i] = getch(fpr)-'0';
    }
    fclose(fpr);//koniec ustawien poczatkowych
    printf("LSFR = <%i, 1 + ",L);
    for(i=1;i<L-1;i++){
        if(D[i-1]==1)
            printf("D%i + ",i);
    }
    if(D[L-1]==1)
        printf("D%i>\n",L);
    else
        printf(">\n"); //ladne wypisywanie LSFR
    printf("Podaj ilosc bitow do wygenerowania: ");
    int k = 0;
    int zwr;
    scanf("%d", &k);
    for(i=1;i<=k;i++){
        printf("%i",S[L-1]);
        zwr = and(S[0],D[0]);
        for(j=L-1;j>=1;j--){
            zwr = xor(zwr,and(S[j],D[j]));
            S[j]=S[j-1];
        } //przesuwanie rejestrow i obliczanie sprzezenia zwrotnego
        S[0]=zwr;
    }
    return 0;
}
