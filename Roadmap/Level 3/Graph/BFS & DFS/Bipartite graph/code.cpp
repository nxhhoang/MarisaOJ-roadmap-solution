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
    vector<int> colored(n + 1, -1);
    vector<vi> graph(n + 1);
    queue<int> q;

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (colored[i] == -1) {
            colored[i] = 0;
            q.push(i);
            while(q.size()){
                int top = q.front();
                q.pop();
                for (int j = 0; j < graph[top].size(); j++) {
                    if (colored[graph[top][j]] == -1) {
                        q.push(graph[top][j]);
                        colored[graph[top][j]] = 1 - colored[top];
                    } else if (colored[graph[top][j]] == colored[top]) {
                        cout << "NO" << endl;
                        return;
                    } 
                }            
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (colored[i] == -1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
