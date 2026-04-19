#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proga_1();
void proga_2();

int main() {
    int k = 0;
    printf("Vvedite nomer zadaniya:\n");
    scanf("%d", &k);

    if (k == 1) {
        proga_1();
    }

    else if (k == 2) {
        proga_2();
    }

    return 0;
}
void proga_1() {
    int n = 7;
    int x[n];
    int i, max, imax, s1 = 0, s2 = 0;

    printf("Vvedite elementi massiva:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    max = x[0];
    imax = 0;

    for (i = 1; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
            imax = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (x[i] < 0 && i<imax ) {
            s2 = s2 + x[i];
        }
        else if ( i>imax && x[i]>0){
            s1+=x[i];
            
        }
    }

    printf("S1 = %d\n", s1);
    printf("S2 = %d\n", s2);

    
}

void proga_2() {
    int a[10][12];
    int b[6] = {0};
    int i, j, count = 0;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 12; j++) {
            a[i][j] = rand() % 51 - 10;
        }
    }

    printf("Matrica:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 12; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 12; j++) {
            if (i >= 5 && a[i][j] > 0) {
                count++;
            }

            if (j % 2 == 0 && a[i][j] < 0) {
                b[j / 2]++;
            }
        }
    }

    printf("\nKolichestvo polozhitelnih elementov v nizhnei polovine = %d\n", count);

    printf("Massiv b:\n");
    for (j = 0; j < 6; j++) {
        printf("%d ", b[j]);
    }
    printf("\n");
}

        