#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int cnt = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < cnt; j++)
            printf("*");
        printf("\n");
        cnt--;
    }
    return 0;
}