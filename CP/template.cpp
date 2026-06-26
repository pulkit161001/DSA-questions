// Header Files and Namespace //
#include<bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------
// PBDS //
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//find_by_order : val at ith, order_of_key : 0 indexed
template<class T> using ordered_set     =  tree<T,null_type,less<T>      ,rb_tree_tag,tree_order_statistics_node_update>;
//allow duplicate values
template<class T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//--------------------------------------------------------------------------------------------------------------------------------------
// MACROS //
#define ll long long int
#define ull unsigned long long
#define ld long double
 
#define pl pair<ll,ll>
#define tl tuple<ll,ll,ll>
 
#define vi vector<int>
#define vl vector<ll>
#define vd vector<ld>
#define vp vector<pl>
#define vt vector<tl>
#define vvl vector< vector<ll> >
 
#define pb push_back
#define mp make_pair
#define mt make_tuple
 
#define lb lower_bound
#define ub upper_bound
 
#define f(i,s,e) for(ll i=s;i<e;i++)
#define ff(i,s,e) for(ll i=s;i>=e;i--)
#define full(v) v.begin(),v.end()
 
#define YES {cout<<"YES"<<endl;return;}
#define NO {cout<<"NO"<<endl;return;}
#define TRUE {cout<<"TRUE"<<endl;return;}
#define FALSE {cout<<"FALSE"<<endl;return;}
 
const ll MOD = 1000000007;
#define MOD2 998244353
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define endl "\n"
#define pi 3.141592653589793238462
#define F first
#define S second
 
#define mx(v)  *max_element(full(v))
#define mn(v)  *min_element(full(v)) 
#define sm(v)  accumulate(full(v), 0)
#define rev(v) reverse(full(v))
 
#define input(v) for(ll i=0;i<v.size();i++){cin>>v[i];}
#define output(v) for(ll i=0;i<v.size();i++){cout<<v[i]<<" ";} cout<<endl;
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Modular Arithmetic //
ll mod_pow(ll x, ll y, ll m=MOD){
    ll ans = 1; x %= m; 
    while(y>0){ if(y%2!=0) ans=(ans*x)%m; y>>=1; x=(x*x)%m; }
    return ans;
}
ll mod_add(ll a, ll b, ll m=MOD) {a=a%m; b=b%m; return (((a+b)%m)+m)%m;}
ll mod_mul(ll a, ll b, ll m=MOD) {a=a%m; b=b%m; return (((a*b)%m)+m)%m;}
ll mod_sub(ll a, ll b, ll m=MOD) {a=a%m; b=b%m; return (((a-b)%m)+m)%m;}
ll mod_div(ll a, ll b, ll m=MOD) {a=a%m; return (((a*mod_pow(b,m-2,m))%m)+m)%m;}
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Segment Tree //
class SegTree{
    ll n;
    vl a;
    vl stSum, stMax, stMin;     
 
    void construct(ll i, ll l, ll r){
        if(l==r){ stSum[i]=stMax[i]=stMin[i]=a[l]; return; }
        ll mid = l+(r-l)/2;
        construct(2*i+1,l,mid);
        construct(2*i+2,mid+1,r);
        stSum[i]=stSum[2*i+1]+stSum[2*i+2];
        stMax[i]=max(stMax[2*i+1],stMax[2*i+2]);
        stMin[i]=min(stMin[2*i+1],stMin[2*i+2]);
    }
    ll getSum(ll i, ll sl, ll sr, ll l, ll r){
        if(l<=sl && sr<=r)  return stSum[i];
        if(sr<l || sl>r)    return 0;
        ll mid=sl+(sr-sl)/2;
        return getSum(2*i+1,sl,mid,l,r)+getSum(2*i+2,mid+1,sr,l,r);
    }
    ll getMax(ll i, ll sl, ll sr, ll l, ll r){
        if(l<=sl && sr<=r)  return stMax[i];
        if(sr<l || sl>r)    return LLONG_MIN;
        ll mid=sl+(sr-sl)/2;
        return max(getMax(2*i+1,sl,mid,l,r),getMax(2*i+2,mid+1,sr,l,r));
    }
    ll getMin(ll i, ll sl, ll sr, ll l, ll r){
        if(l<=sl && sr<=r)  return stMin[i];
        if(sr<l || sl>r)    return LLONG_MAX;
        ll mid=sl+(sr-sl)/2;
        return min(getMin(2*i+1,sl,mid,l,r),getMin(2*i+2,mid+1,sr,l,r));
    }
    void update(ll id, ll val, ll i, ll l, ll r){
        if(l==r){ stSum[i]=stMax[i]=stMin[i]=val; return; }
        ll mid=l+(r-l)/2;
        if(id<=mid) update(id,val,2*i+1,l,mid);
        else        update(id,val,2*i+2,mid+1,r);
        stSum[i]=stSum[2*i+1]+stSum[2*i+2];
        stMax[i]=max(stMax[2*i+1],stMax[2*i+2]);
        stMin[i]=min(stMin[2*i+1],stMin[2*i+2]);
    }
 
    public:
    SegTree(vl &arr){
        this->a=arr; n=arr.size();
        stSum.assign(4*n,0);
        stMax.assign(4*n,LLONG_MIN);
        stMin.assign(4*n,LLONG_MAX);
        construct(0,0,n-1);
    }
    ll getSum(ll l, ll r){ return getSum(0,0,n-1,l,r); }
    ll getMax(ll l, ll r){ return getMax(0,0,n-1,l,r); }
    ll getMin(ll l, ll r){ return getMin(0,0,n-1,l,r); }
    void update(ll id, ll val){ a[id]=val; update(id,val,0,0,n-1); }
};
 
//--------------------------------------------------------------------------------------------------------------------------------------  
 
void pulkit() {
    
}
 
 
// MAIN FUNCTION //
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    // ll TestCase; cin >> TestCase; f(i,0,TestCase) pulkit();
    pulkit();
}
