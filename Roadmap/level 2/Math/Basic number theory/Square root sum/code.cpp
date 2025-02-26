// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {
    ll a, b;
    cin >> a >> b;
    int s_a = sqrt(a);
    int s_b = sqrt(b);
    ll sum = 0;
    if (s_a == s_b) {
        sum += 1ll * (b - a + 1) * s_a;
        cout << sum;
        return;
    } else if (s_a == s_b - 1) {
        sum += 1ll * (1ll * s_b * s_b - a) * s_a;
        sum += 1ll * (b - 1ll * s_b * s_b + 1) * s_b;
        cout << sum;
        return;
    }

    sum += 1ll * (1ll * (s_a + 1) * (s_a + 1) - a) * s_a;
    a = 1ll * (s_a + 1) * (s_a + 1);
    s_a++;

    sum += 1ll * (b - 1ll * s_b * s_b + 1) * s_b;
    b = 1ll * s_b * s_b;
    
    int cur = s_a;
    for (int i = s_a; i <= s_b; i++) {
        sum += 1ll * (b - 1ll * i * i) * cur;
        cur = 1;
    }

    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
