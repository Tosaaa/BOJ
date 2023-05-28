// 연속합
// https://www.acmicpc.net/problem/1912

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int p[100001];
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    
    int sum = p[1];
    int s[100001] = {0};
    s[1] = p[1];
    for (int x = 2; x <= N; x++) {
        if (s[x-1] <= 0) {
            s[x] = p[x];
        } else {
            s[x] = s[x-1] + p[x];
        }
        sum = max(sum, s[x]);
    }
    
    cout << sum << endl;

    return 0;
}