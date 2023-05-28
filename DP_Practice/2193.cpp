// 이친수
// https://www.acmicpc.net/problem/2193

#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

int main() {

    // z(x) = z(x-1) + o(x-1)
    // o(x) = z(x-1)
    // p(x) = z(x) + o(x) = z(x+1) = z(x) + z(x-1)
    // z(x) = z(x-2) + z(x-3)

    int N;
    cin >> N;

    vector<long long> zero(N+1);
    zero[0] = 0;
    zero[1] = 1;
    for (int x = 2; x < N+1; x++) {
        zero[x] = INF;
        if (x-2 >= 0) {
            zero[x] = zero[x-1] + zero[x-2];
        }
    }
    
    cout << zero[N] << endl;

    return 0;
}