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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vi> graph(n + 1);
    vector<int> shorted(n + 1, -1);
    queue<int> q;
    
    vector<int> query(k);
    for (int i = 0; i < k; i++) cin >> query[i];
    q.push(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    shorted[n] = 0;
    while(q.size()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < graph[top].size(); i++) {
            if (shorted[graph[top][i]] == -1) shorted[graph[top][i]] = shorted[top] + 1, q.push(graph[top][i]);
        }
    }

    for (int i = 0; i < k; i++) cout << shorted[query[i]] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
