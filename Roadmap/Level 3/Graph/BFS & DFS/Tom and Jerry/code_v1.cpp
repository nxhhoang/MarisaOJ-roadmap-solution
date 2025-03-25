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
    int a, b;
    cin >> a >> b;
    vector<vi> graph(n + 1);
    vector<int> tom(n + 1, INT_MAX);
    vi jerry(n + 1, INT_MAX);
    queue<int> q;
    while(m--){
        int c, d;
        cin >> c >> d;
        graph[c].push_back(d);
        graph[d].push_back(c);
    }

    q.push(a);
    jerry[a] = 0;
    while (q.size()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < graph[top].size(); i++) {
            if (jerry[graph[top][i]] == INT_MAX) 
                jerry[graph[top][i]] = jerry[top] + 1, 
                q.push(graph[top][i]);
        }
    }
    
    q.push(b);
    tom[b] = 0;
    while (q.size()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < graph[top].size(); i++) {
            if (tom[graph[top][i]] == INT_MAX) 
                tom[graph[top][i]] = tom[top] + 1, 
                q.push(graph[top][i]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (tom[i] >= jerry[i]) cnt++;
    }
    cout << cnt << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
