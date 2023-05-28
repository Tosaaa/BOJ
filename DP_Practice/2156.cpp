// 포도주 시식
// https://www.acmicpc.net/problem/2156

#include <iostream>

using namespace std;

int main() {
    
    // s1(x) = s(x-4) + p(x-2) + p(x-1)
    // s2(x) = s(x-3) + p(x-1) + p(x)
    // s3(x) = s(x-2) + p(x)
    // s(x) = max(s1(x), s2(x), s3(x))

    int N;
    cin >> N;

    int p[10001];
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    int s[10001] = {0};
    s[1] = p[1];
    //cout << "1" << ": " << s[1] << endl;

    for (int x = 2; x <= N; x++) {
        if (x == 2) {
            s[x] = p[x-1] + p[x];
        } else if (x == 3) {
            s[x] = max(p[x-2] + p[x-1], s[x-3] + p[x-1] + p[x]); // s[0] = 0 이라 괜찮음.
            s[x] = max(s[x], s[x-2] + p[x]);
        } else {
            s[x] = max(s[x-4] + p[x-2] + p[x-1], s[x-3] + p[x-1] + p[x]); // s[0] = 0 이라 괜찮음.
            s[x] = max(s[x], s[x-2] + p[x]);
        }
        //cout << x << ": " << s[x] << endl;
    }

    cout << s[N] << endl;

}