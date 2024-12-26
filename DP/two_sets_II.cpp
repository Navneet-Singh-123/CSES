#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
typedef long long ll;
typedef long double lld;
#define inf 1e18
#define endl "\n";
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define dbg(x) cout << #x << ": " << x << endl
#define check(k, i, j) ((k>=i) && (k<=j))
#define ff first
#define ss second
#define PI acos(-1)
#define sz(x) (int)((x).size())
#define pii pair<int,int>
#define pll pair<long long, long long>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define all(x)  (x).begin(),(x).end()
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,a,b) for(ll i=a;i<=b;i++)
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#pragma GCC diagnostic ignored "-Wunused-variable" 
int dx8[]={1,1,0,-1,-1,-1, 0, 1}; 
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
template<class T>using ordered_set=tree<T, null_type, 
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using ordered_multiset=tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, 
less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args){
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> 
using u_map = unordered_map<T1, T2, custom_hash>;

mt19937_64 rng((ll)chrono::steady_clock::now().time_since_epoch().count());
template<typename T>void _print(vector<vector<T>> &v)
{for(int i=0; i<sz(v); i++){for(int j=0; j<sz(v[i]); j++){cout << v[i][j] << " ";}cout << endl;}}
void gg(int val) {cout << "Case #" << val << ": ";}
template<typename T>void _print(vector<T> &v, int l, int r){rep1(i, l, r){cout << v[i] << " ";}cout << endl;}
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, 
typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) 
{ os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// ===================================== //

ll n;
vector<vector<ll>> dp;

// ll solve(ll val, ll req){
//     if(!req)return 1;
//     if(val==1)return req==1;
//     if(dp[val][req]!=-1)return dp[val][req];
//     ll op1=solve(val-1, req), op2=0;
//     if(val<=req)op2=solve(val-1, req-val);
//     return dp[val][req] = (op1%mod + op2%mod)%mod;
// }

ll powerm(ll a, ll b, ll c){
    ll x = 1, y = a;
    while(b){
        if(b&1){
            x = (x%c * y%c)%c;
        }
        b>>=1;
        y=(y%c * y%c)%c;
    }
    return x;
}

ll mod_inv(ll x){
    return powerm(x, mod-2, mod);
}

void solve(){   
    cin >> n;
    ll s=(n*(n+1))/2;
    if(s%2){
        cout << 0 << endl;
        return;
    }        
    s=s/2;
    dp=vector<vector<ll>>(n+1, vector<ll>(s+1));
    rep0(i, n+1)dp[i][0]=1;
    ll res=0;
    dp[1][1]=1;
    for(ll val=2; val<=n; val++){
        for(ll req=1; req<=s; req++){
            ll op1=dp[val-1][req], op2=0;
            if(val<=req)op2=dp[val-1][req-val];
            dp[val][req] = (op1%mod + op2%mod)%mod;
        }
    }
    res=dp[n][s];
    res*=mod_inv(2);
    res%=mod;
    cout << res << endl;
}   

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif 

    FAST_IO;
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}