#include<iostream>
#include<iomanip>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 20;

int n; ll S;
ll w[N];
ll v[N];
bool flag[N] = { 0 };
ll maxV = 0;
ll max_w = 0;
ll max_v = 0;
int mi = 0;

void tryy(int k) {
    FOR(i, 0, n) {
        if (flag[i]) continue;
        max_w -= w[i];
        max_v -= v[i];
        flag[i] = 1;
        if (max_w <= S) {
            if (maxV < max_v) maxV = max_v;
            //if (k == 0) continue;
            max_w += w[i];
            max_v += v[i];
            flag[i] = 0;
            return;
        }
        tryy(k + 1);
        max_w += w[i];
        max_v += v[i];
        flag[i] = 0;
    }
}

void solve()
{
    cin >> n >> S;
    FOR(i, 0, n) {
        cin >> w[i] >> v[i];
        max_w += w[i];
        max_v += v[i];
    }
    FOR(i, 0, n) if (v[mi] > v[i]) mi = i;
    if (max_w - w[mi] <= S) maxV = max_v - v[mi];
    if (max_w <= S) maxV = max_v;
    tryy(0);
    cout << maxV << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
