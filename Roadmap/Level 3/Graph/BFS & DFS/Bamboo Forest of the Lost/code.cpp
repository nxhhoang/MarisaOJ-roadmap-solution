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
    int ma, re;
    cin >> ma >> re;
    vector<vi> graph(n + 1);
    vector<int> shorted(n + 1, -1);
    vector<int> longer(n + 1, -1);
    queue<int> q;
    
    q.push(ma);
    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (ma == re) {
        cout << 0 << endl;
        return;
    }
    shorted[ma] = 0;
    while(q.size()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < graph[top].size(); i++) {
            if (shorted[graph[top][i]] == -1) shorted[graph[top][i]] = shorted[top] + 1, q.push(graph[top][i]);
        }
    }

    q.push(re);
    longer[re] = 0;
    while(q.size()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < graph[top].size(); i++) {
            if (longer[graph[top][i]] == -1) longer[graph[top][i]] = longer[top] + 1, q.push(graph[top][i]);
        }
    }
    int value = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if ((longer[i] + shorted[i]) % 2 == 0 && i != re && i != ma) 
            value = min(value, longer[i] + shorted[i]);
    } 
    if (value != INT_MAX) cout << value / 2 << endl;
    else cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
