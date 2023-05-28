// 뒤집기
// https://www.acmicpc.net/problem/1439

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c = getchar();
    int tmp = c;
    int cnt = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
        if (c != tmp) cnt++;
        tmp = c;
    }
    if (cnt != 0) cnt /= 2;
    
    cout << cnt << endl;
    

    return 0;
}