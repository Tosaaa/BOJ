// 곱셈
// https://www.acmicpc.net/problem/1629
// Recursion

#include <stdio.h>

long long mult(int A, int B, int C) {
    long long result = 0;
    if (B == 1) {
        return A % C;    
    } else {
        long long r1, r2, r3;
        if (B % 2 == 1) {
            r1 = mult(A, B/2, C);
            r3 = mult(A, 1, C);
            result = r1;
            result *= r1;
            result %= C;
            result *= r3;
            result %= C;
        } else {
            r1 = mult(A, B/2, C);
            result = r1;
            result *= r1;
            result %= C;
        }
        return result;
    }
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", mult(A, B, C));
    return 0;
}