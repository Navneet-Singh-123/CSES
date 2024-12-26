#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define endl "\n";
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
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int dx8[]={1,1,0,-1,-1,-1, 0, 1}; 
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
typedef long long ll;
 
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
 
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
// ===================================== //
 
 
 
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n+1), pages(n+1);
    for(int i=1; i<=n; i++)
        cin >> price[i];
    for(int i=1; i<=n; i++)
        cin >> pages[i];
    int dp[n+1][x+1];
    for(int i = 0; i <= n; i++){
        for(int money = 0; money <= x; money++){
            if(money == 0 || i == 0)
                dp[i][money] = 0;
            else{
                int op1 = (i == 1) ? 0 : dp[i-1][money];
                int op2 = (money < price[i]) ? 0 : pages[i] + dp[i-1][money - price[i]];
                dp[i][money] = max(op1,op2);
            }
        }
    }
    cout << dp[n][x];
}   
 
int main(){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif 
 
    FAST_IO;
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}