#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
//#define int long long
#define fi first
#define se second
#define el cout << "\n"
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define DEBUG
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

vector<int>G[N];
int f[N], dp[N];
vector<int>a(N + 1);
vector<int>ans;
// f[u] : gia tri tot nhat cua cac subtree
// dp[u] : gia tri tot nhat cua subtree bao gom u
// 1 -> 1 : -1
void dfs(int u, int p) {
    for(auto &v : G[u]) {
        if(v == p) continue;
        dfs(v, u);
        f[u] = f[u] + max(0, f[v]);
    }
}

void cal(int u, int p) {
    for(auto &v : G[u]) {
        if(v == p) continue;
        // reroot, len cac nhanh cha ngoai tru v
        int rem = dp[u] - max(0, f[v]);
        dp[v] = f[v] + max(0, rem);
        cal(v, u);
    }
}

void solve() {
    int n; cin >> n;
    ans.assign(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = (a[i] == 1 ? 1 : -1);
    }

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1, 1);
    dp[1] = f[1];
    cal(1, 1);

    for(int u = 1; u <= n; u++)
        cout << dp[u] << ' ';
    cout << endl;
}

int32_t main() {
    faster();
    clock_t start = clock();

    int tc = 1;
    //cin >> tc;

    while (tc--)
        solve();

    cerr << '\n';
    cerr << "Time elapsed: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
