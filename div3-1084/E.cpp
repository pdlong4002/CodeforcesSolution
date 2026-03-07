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

// const int N = 5e5 + 5;
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
//  build : build
//  run : run
//  test : run && input + output
// -------

int N = 1e6 + 5;
vector<int>spf(N);

void __init__() {
    iota(all(spf), 0);
    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) { // prime
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int>a(n);
    for(auto &x : a)
        cin >> x;

    // check
    auto valid = [&] () -> bool {
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i - 1])
                return false;
        }
        return true;
    };

    if(valid()) {
        cout << "Bob\n";
        return;
    }

    auto get = [&] (int x) -> int {
        if(x == 1)
            return 1;
        int p = spf[x];
        while(x % p == 0)
            x /= p;
        return x > 1 ? -1 : p;
        // if return -1, there are >= 2 diff primes and many way to split the number:D
    };

    for(int i = 0; i < n; i++)
        a[i] = get(a[i]);

    if(count(all(a), -1) != 0) {
        cout << "Alice\n";
        return;
    }
    
    cout << (valid() ? "Bob" : "Alice") << endl;
}

int32_t main()
{
    faster();
    int tc = 1;
    cin >> tc;
    __init__();
    while (tc--)
    {
        solve();
    }
    return 0;
}