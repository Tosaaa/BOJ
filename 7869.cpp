// 두 원
// https://www.acmicpc.net/problem/7869

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(3);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (r1 + d <= r2) {
        cout << PI * r1 * r1 << endl;
    } else if (r2 + d <= r1) {
        cout << PI * r2 * r2 << endl;
    } else if (r1 + d > r2 && d < r2) {
        double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double result1 = r1 * r1 * theta1;
        double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        double result2 = r2 * r2 * (theta2 - 0.5 * sin(2 * theta2));
        double result3 = 0.5 * r1 * r1 * sin(2 * PI - 2 * theta1);
        cout << result1 + result2 + result3 << endl;
    } else if (r2 + d > r1 && d < r1) {
        double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        double result2 = r2 * r2 * theta2;
        double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double result1 = r1 * r1 * (theta1 - 0.5 * sin(2 * theta1));
        double result3 = 0.5 * r2 * r2 * sin(2 * PI - 2 * theta2);
        cout << result1 + result2 + result3 << endl;
    } else if (r1 + r2 <= d) {
        cout << 0.000 << endl;
    } else {
        double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double result1 = r1 * r1 * (theta1 - 0.5 * sin(2 * theta1));
        double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        double result2 = r2 * r2 * (theta2 - 0.5 * sin(2 * theta2));
        cout << result1 + result2 << endl;
    }

    return 0;
}