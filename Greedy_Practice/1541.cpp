// 잃어버린 괄호
// https://www.acmicpc.net/problem/1541

#include <iostream>
#include <vector>
#include <string>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

// 그냥 - 만난 순간부터는 싹 다 빼면 될 듯

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<int> num;
    vector<char> sign;
    string tmp = "";
    sign.push_back('+');
    REP(i, 0, s.size()) {
        if (s[i] == '-' || s[i] == '+') {
            num.push_back((stoi(tmp)));
            tmp = "";
            sign.push_back(s[i]);
        } else {
            tmp += s[i];
        }
    }
    num.push_back((stoi(tmp)));

    int sum = 0;
    int state = 0;
    for (int i = 0; i < num.size(); i++) {
        if (sign[i] == '+') {
            if (!state)
                sum += num[i];
            else
                sum -= num[i];
        } else if (sign[i] == '-') {
            state = 1;
            sum -= num[i];
        }
    }

    cout << sum << endl;

    return 0;
}