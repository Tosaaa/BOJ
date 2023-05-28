#include "testlib.h"
using namespace std;
const long long INF = 3'000'000'000'000'000'000LL;
int n;
vector<long long> a, g;
long long f(TResult x, const char* quit_msg){
    long long c=0,d=0;
    for(int i=0;i<n;i++){
        if((INF-c)/a[i]<g[i]) quitf(x, quit_msg);
        c += a[i]*g[i];
        d += g[i];
    }
    long long C=c,D=0;
    for(int i=n-1;i>=0;i--){
        D += C/a[i];
        C %= a[i];
    }
    if(d>=D) quitf(x, quit_msg);
    return c;
}
int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    n = inf.readInt(1, 500, "n");
    a = inf.readLongs(n, 1LL, 1'000'000'000'000'000'000LL, "a");
    string s = ouf.readToken("Yes|No", "user output");
    string t = ans.readToken("Yes|No", "judge data");
    if(s == "Yes"){
        if(t == "Yes") quitf(_ok, "passed (no counterexample)");
        else{
            g = ans.readLongs(n, 0LL, 3'000'000'000'000'000'000LL, "g_judge");
            f(_fail, "judge output is not a valid counterexample");
            quitf(_wa, "judge found counterexample, but user did not");
        }
    }
    else if(s == "No"){
        g = ouf.readLongs(n, 0LL, 3'000'000'000'000'000'000LL, "g_user");
        long long h = f(_wa, "user output is not a counterexample");
        if(t == "Yes") quitf(_fail, "user found counterexample, but judge did not");
        else{
            g = ans.readLongs(n, 0LL, 3'000'000'000'000'000'000LL, "g_judge");
            long long i = f(_fail, "judge output is not a counterexample");
            if(h > i) quitf(_wa, "judge found a smaller counterexample");
            else if(h < i) quitf(_fail, "user found a smaller counterexample");
            else quitf(_ok, "passed (valid counterexample)");
        }
    }
}