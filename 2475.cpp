// 검증수
// https://www.acmicpc.net/problem/2475

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int ans = (a*a + b*b + c*c + d*d + e*e) % 10;
    
    cout << ans << endl;
    return 0;
}