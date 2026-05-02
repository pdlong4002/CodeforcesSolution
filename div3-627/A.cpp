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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define DEBUG
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

void solve() {
    int n, cnt = 0; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt = cnt + (x & 1);
    }

    auto ok = (cnt == 0 || cnt == n);
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    faster();
    clock_t start = clock();

    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();

    cerr << '\n';
    cerr << "Time elapsed: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}