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
    long long n, ans = 0; cin >> n;
    vector<int>a(n), b(n), d(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        d[i] = a[i] - b[i];

    sort(all(d));
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(d.begin() + i + 1, d.end(), -d[i]) - d.begin();
        ans = ans + (n - it);
    }

    cout << ans << endl;
}
// 0 -1 -2 3 5
// 2
// 2
// 2
// 1

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