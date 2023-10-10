#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;
///// Agamista

void cntSort(vector<int>& p,vector<int>& c){
    int n = p.size();
    vector<int> cnt(n,0);
    for(int i : p)
        cnt[c[i]]++;
    for(int i=1 ; i<n ;i++) cnt[i] += cnt[i-1];
    for(int i=0 ; i<n ;i++) cnt[i]--;

    vector<int> p_new(n);
    for(int i=n-1 ; i>=0 ;i--){
        p_new[cnt[c[p[i]]]] = p[i];
        cnt[c[p[i]]]--;
    }
    p = p_new;
}

void updateClass(vector<int>& p,vector<int>& c,int k){
    int n = p.size();
    vector<int> c_new(n);
    c_new[p[0]] = 0;
    for(int i=1 ; i <n ;i++){
        if(c[p[i]] == c[p[i-1]] && c[(p[i]+(1<<k))%n] == c[(p[i-1]+(1<<k))%n])
            c_new[p[i]] = c_new[p[i-1]];
        else
            c_new[p[i]] = c_new[p[i-1]]+1;
    }
    c = c_new;
}

vector<int> suffixArray(string &s){

    s = s + '$';
    int n = s.size();

    vector<vector<int>> vec(n);
    for(int i=0 ; i<n ;i++) vec[i] = {s[i],i};
    sort(vec.begin(),vec.end());
    vector<int> p(n);
    for(int i=0 ; i<n ;i++) p[i] = vec[i][1];

    vector<int> c(n);
    c[p[0]] = 0;
    for(int i=1 ; i<n ;i++)
        c[p[i]] = (s[p[i]] == s[p[i-1]] ? c[p[i-1]] : c[p[i-1]]+1);

    int k = 0;
    while ((1<<k) < n){
        for(int i=0 ; i<n ;i++)
            p[i] = ( p[i] - (1<<k) +n)%n;
        cntSort(p,c);
        updateClass(p,c,k);
        k++;
    }
    return p;
}

ll fun(ll inx,string &z,string &x) {
    ll sz = z.size();
    ll f = 0;
    ll n = x.size();
    for (int i = inx; sz > 0; ++i, sz--, f++) {
        if (x[i % n] < z[f])return 0;
        else if (x[i % n] > z[f])return 1;
    }
    return 2;
}
void solve() {
    string x;
    cin >> x;
    vi suf = suffixArray(x);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string z;
        cin >> z;
        ll st = 0;
        ll en = suf.size() - 1;
        while (st < en) {
            ll mid = st + (en - st) / 2;
            if (fun(suf[mid], z, x)) {
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        if (fun(suf[en], z, x) != 2) {
            cout << 0 << endl;
            continue;
        }
        ll fir = st;
        st = 0;
        en = suf.size()-1;
        while (st < en) {
            ll mid = st + (en - st + 1) / 2;
            if (fun(suf[mid], z, x) != 1) {
                st = mid;
            } else {
                en = mid - 1;
            }
        }
        cout << st - fir + 1 << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}