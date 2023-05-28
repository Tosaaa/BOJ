#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    inf.readEoln();
    vector<long long> v = inf.readLongs(n, 1LL, 1'000'000'000'000'000'000LL, "v");
    inf.readEoln();
    ensuref(v[0] == 1LL, "v[0] = %lld", v[0]);
    for(int i=1;i<n;i++) ensuref(v[i-1] < v[i], "v[%d] >= v[%d]", i-1, i);
    inf.readEof();
}