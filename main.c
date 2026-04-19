#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proga_1();
void proga_2();

int modmax(int x[], int start, int n);

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
int poloz(int x[], int n){
    int i, p = -1;

    for (i = 0; i < n; i++) {
        if (x[i] > 0) {
            p = i;
        }
    }
    if (p>0){return p;}

    else if (p==-1){
        printf("polozitelnix net\n");
        return -1;
    }
    else{
        printf("pustaya levaya chast\n");
        return 0;
    }
}       


void proga_1() {
    int mini_a = 100000;
    int index_a = -1;
    int index_b = -1;
    int mini_b = 100000;
    int n = 12;
    int a[n], b[n], i, count = 0;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        a[i] = rand() % 51 - 3;
        b[i] = rand() % 31 - 20;
    }

    printf("Massiv A:\n");
    for (i = 0; i < n; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");

    printf("Massiv B:\n");
    for (i = 0; i < n; i++) {
        printf("%4d", b[i]);
    }
    printf("\n");

    int a_n = poloz(a, n);
    int b_n = poloz(b, n);

    for (i = 0; i < a_n; i++) {
        if (a[i] < mini_a) {
            mini_a = a[i];
            index_a = i;
        }
    }

    for (i = 0; i < b_n; i++) {
        if (b[i] < mini_b) {
            mini_b = b[i];
            index_b = i;
        }
    }
    
    printf("Index A = %d\n", a_n);
    printf("Index B = %d\n", b_n);
    printf("Min A = %d\n", mini_a);
    printf("Index min A = %d\n", index_a);
    printf("Min B = %d\n", mini_b);
    printf("Index min B = %d\n", index_b);
}


void proga_2() {
    int n = 5;
    int a[5][5];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 21 - 10;
        }
    }

    printf("Matrica:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMax po modulyu v kazhdoi stroke pravogo verhnego treugolnika:\n");
    for (i = 0; i < n; i++) {
        printf("stroka %d: %d\n", i, modmax(a[i], i, n));
    }
}

int modmax(int x[], int start, int n) {
    int j, m = x[start];

    for (j = start + 1; j < n; j++) {
        if (abs(x[j]) > abs(m)) {
            m = x[j];
        }
    }

    return m;
}
