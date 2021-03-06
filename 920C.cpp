#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const int nmax = 200010;
int n;
int a[nmax];
ii b[nmax];
int lab[nmax];
void zip() {
    for (int i = 1; i <= n; i++) {
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(b + 1, b + 1 + n);
    a[b[1].se] = 1;
    int v = 1;
    for (int i = 2; i <= n; i++)
        if (b[i].fi == b[i - 1].fi) a[b[i].se] = v;
        else
            a[b[i].se] = ++v;
}
int getroot(int x) {
    while (lab[x] > 0) x = lab[x];
    return x;
}
void Union(int x, int y) {
    int r1 = getroot(x);
    int r2 = getroot(y);
    if (r1 != r2) {
        int tmp = lab[r1] + lab[r2];
        if (lab[r1] > lab[r2]) {
            lab[r1] = r2;
            lab[r2] = tmp;
        }
        else {
            lab[r2] = r1;
            lab[r1] = tmp;
        }
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    zip();
    for (int i = 1; i <= n; i++) lab[i] = -1;
    string s;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i < n; i++) 
        if (s[i] == '1') Union(a[i], a[i + 1]);
    for (int i = 1; i <= n; i++)
        if (getroot(i) != getroot(a[i])) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
