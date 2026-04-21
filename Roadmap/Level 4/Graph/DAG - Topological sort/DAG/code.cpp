// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
vector<vi> tre(MSIZE);
int cnt = 0;
vector<int> ind(MSIZE, 0);
queue<int> q;

void solve()
{
    int a, b;
    cin >> n >> m;    
    for (int i = 0; i < m;i++) {
        cin >> a >> b;
        tre[a].push_back(b);
        ind[b]++;
    }

    for (int i = 1; i <=n ; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    
    while (q.size()) {
        int it = q.front();
        q.pop();
        cnt++;

        for (auto &ve : tre[it]) {
            ind[ve]--;
            if (ind[ve] == 0) q.push(ve);
        }
    }
    if (cnt != n) cout << "NO";
    else cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
