/*
_____ ______                                    _________                      _________
__  /____  /_ _____         _______ ___ ______ _______  /        _____________ ______  /_____ ________
_  __/__  __ \_  _ \        __  __ `__ \_  __ `/_  __  /         _  ___/_  __ \_  __  / _  _ \__  ___/
/ /_  _  / / //  __/        _  / / / / // /_/ / / /_/ /          / /__  / /_/ // /_/ /  /  __/_  /
\__/  /_/ /_/ \___/ ________/_/ /_/ /_/ \__,_/  \__,_/   ________\___/  \____/ \__,_/   \___/ /_/
                    _/_____/                             _/_____/
  	handle : the_mad_coder
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector< int > vi;
typedef vector<ll> vll;
typedef vector <string> vs;
typedef pair< int,int > pii;
typedef pair< ll,ll > pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector< vi > vvi;
typedef vector< vll > vvll;

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define len(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define vsum(c) accumulate(all(c), 0);

#define srt(v)	sort (all (v))
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)

#define fir first
#define sec second

#define trans(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define loop(i, a, b)	for (ll i(a); i < (b); i ++)
#define test() int t; scanf("%d",&t); while(t--)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PI 3.14159265358979323
#define MIN -1e9
#define MAX  1e9
const ll MOD = 1000000007LL;

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

ll fun(vll v,ll n){
    if (n==2){
        return v[0]+v[1];
    }
    cout<<n<<endl;
    vll d(n);
    
    vll vn(n-1);
    
    d[0]=v[0]+v[n-1];
    ll min=0;
    loop(i,1,n){
        d[i]=v[i]+v[i-1];
        if (d[i]<d[min]){
            min=i;
        }
    }
    if(min==0){
        vn[0]=d[min];
        loop(i,1,n-1){
            vn[i]=v[i];
        }
    }
    else{
        ll j=0;
        loop(i,0,n){
            if (i==min-1){
                vn[j]=d[min];
                j++;
                i++;
            }
            else{
                vn[j]=v[i];
                j++;
            }
        }
    }
    //cout<<d[min]<<endl;
    return d[min]+fun(vn,n-1);
    
}

int main() {

	//FAST_IO;
	test(){
	    ll n;
	    cin>>n;
	    vll v(n);
	    loop(i,0,n){
	        cin>>v[i];
	    }
	    ll sum = fun(v,n);
		cout<<sum<<endl;
	}

	return 0;
}
