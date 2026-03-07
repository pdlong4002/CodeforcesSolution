#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
#define int long long
#define fi first
#define se second
#define el cout << "\n"
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define DEBUG
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

// ------- dashboard -------
//  cd SOLUTION 
//  build : build and run
//  run : run
//  test : run && input + output
// -------

void solve() {
    int n; cin >> n;
    vector<int>a(n);
    for(auto &x : a)
        cin >> x;
    
    int ans = n;

    auto valid = [&] (vector<int>& a) -> int {
        if(a.size() == 1) return 1;
        for(int i = 1; i < a.size(); i++) {
            if(a[i] < a[i - 1])
                return 0;
        }
        return 1;
    };

    if(valid(a)) {
        cout << n << endl;
        return;
    }


    for(int mask = 1; mask < (1 << n); mask++) {
        vector<int>cur;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cur.push_back(a[i]);
            }
        }
        if(valid(cur))
            ans = min(ans, (int)cur.size());
    }

    cout << ans << endl;
}

int32_t main()
{
    faster();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}