#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;

    priority_queue<pair<int,int>> pq;

    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;

        pq.push(make_pair(a + b, a));
    }

    ll sum = 0;

    while(q--){
        int ff = pq.top().first;
        int ss = pq.top().second;
        if (ss == 0) {
            sum += 1ll * (q + 1) * ff;
            break;
        }
        sum += pq.top().first;
        pq.pop();
        pq.push(make_pair(ff - ss, 0));
    }

    cout << sum << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
