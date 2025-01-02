#include <iostream>
#include <vector>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using ll = long long;
using namespace std;
const int N = 20;

int n;
ll S;
ll w[N];
ll v[N];
ll maxV = 0;

void tryy(int k, ll currW, ll currV) {
    if (k == n) {
        if (currW <= S) maxV = max(maxV, currV);
        return;
    }

    tryy(k + 1, currW, currV);
    if (currW + w[k] <= S) tryy(k + 1, currW + w[k], currV + v[k]);
}

void solve() {
    cin >> n >> S;
    FOR(i, 0, n) cin >> w[i] >> v[i];
    tryy(0, 0, 0);
    cout << maxV << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
