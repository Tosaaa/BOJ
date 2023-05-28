// 카드 합체 놀이
// https://www.acmicpc.net/problem/15093

#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    long long arr[1000];
    long long sum = 0;
    REP(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }


    REP(i, 0, m) {
        sort(arr, arr + n);
        arr[0] += arr[1];
        arr[1] = arr[0];
        sum += arr[0];
    }
    
    cout << sum << endl;

    return 0;
}