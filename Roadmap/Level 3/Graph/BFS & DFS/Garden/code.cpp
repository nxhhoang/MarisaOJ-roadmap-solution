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
    int n, m;
    cin >> n >> m;
    vector<string> nm(n);
    queue<pair<int, int>> q;
    multiset<int> st;
    for (int i = 0; i < n; i++) cin >> nm[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = 0;
            if (nm[i][j] == '*' || nm[i][j] == 'x') {
                if (nm[i][j] == 'x') val++;
                nm[i][j] = 'Y';
                q.push({i, j});
                while(q.size()){
                    auto [x, y] = q.front();
                    for (int k = 0; k < 4; k++) {
                        int a = x + dx[k];
                        int b = y + dy[k];
                        if (a < 0 || b < 0 || a >= n || b >= m || nm[a][b] == 'Y' || nm[a][b] == '#') continue;
                        if (nm[a][b] == 'x') val++;
                        q.push({a, b});
                        nm[a][b] = 'Y';
                    }
                    q.pop();
                }
                if (val) st.insert(val);
            } 
        }
    }
    for (multiset<int>::iterator it = st.begin(); it != st.end(); it++) cout << *it << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
