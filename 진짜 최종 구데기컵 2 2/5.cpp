// 5
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    FILE *fp = fopen("wordlist.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");

    char buf[10];
    char *pLine;
    bool valid;
    bool validA;
    while (fgets(buf, 10, fp) != NULL) {
        valid = true;
        validA = false;
        REP(i, 0, 5) {
            if (buf[i] == 'T') {
                valid = false;
                break;
            }
            if (buf[i] == 'R') {
                valid = false;
                break;
            }
            if (buf[i] == 'O') {
                valid = false;
                break;
            }
            if (buf[i] == 'P') {
                valid = false;
                break;
            }
            if (buf[i] == 'E') {
                valid = false;
                break;
            }
            if (buf[i] == 'L') {
                valid = false;
                break;
            }
            if (buf[i] == 'C') {
                valid = false;
                break;
            }
            if (buf[i] == 'I') {
                valid = false;
                break;
            }
            if (buf[i] == 'D') {
                valid = false;
                break;
            }
            if (buf[i] == 'A') {
                validA = true;
            }
            if (buf[i] == 'A') {
                validA = true;
            }
            if (buf[i] == 'N') {
                valid = false;
                break;
            }
            if (buf[i] == 'B') {
                valid = false;
                break;
            }
        }
        if (!valid || !validA) continue;
        if (buf[0] != 'Q' || buf[1] != 'U' || buf[2] != 'A') continue;
        fprintf(fp2, "%s", buf);
    }
    fclose(fp);
    fclose(fp2);

    return 0;
}