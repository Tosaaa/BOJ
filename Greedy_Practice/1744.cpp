// 수 묶기
// https://www.acmicpc.net/problem/1744

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    priority_queue<int> pos;
    priority_queue<int> neg;
    int zeros = 0;
    int ans = 0;
    int num;
    REP(i, 0, N) {
        cin >> num;
        if (num > 0)
            if (num == 1)
                ans++;
            else 
                pos.push(num);
        else if (num < 0)
            neg.push(-num);
        else
            zeros++;
    }

 
    int tmp;
    while(!pos.empty()) {
        if (pos.size() == 1) {
            ans+= pos.top();
            pos.pop();
        } else {
            tmp = pos.top();
            pos.pop();
            tmp *= pos.top();
            pos.pop();
            ans += tmp;
        }
    }
    while(!neg.empty()) {
        if (neg.size() == 1) {
            if (zeros > 0) {
                neg.pop();
            } else {
                ans -= neg.top();
                neg.pop();
            }
        } else {
            tmp = neg.top();
            neg.pop();
            tmp *= neg.top();
            neg.pop();
            ans += tmp;
        }
    }

    cout << ans << endl;

    return 0;
}