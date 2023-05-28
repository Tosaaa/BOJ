#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < cnt; j++)
            printf(" ");
        for (int j = 0; j < 2*(N-cnt)-1; j++)
            printf("*");
        // for (int j = 0; j < N-cnt; j++)
        //     printf(" ");
        printf("\n");
        cnt++;
    }
    return 0;
}