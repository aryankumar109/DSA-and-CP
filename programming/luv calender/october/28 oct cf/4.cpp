#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pf push_front
#define pb push_back
#define SZ(x) ((int)(x).size())
#define AhmedPlusPlus ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define YN(X) cout << ( X ? "YES\n" : "NO\n" );                  

int summ (int n) {
    return (n*(n+1))/2;
}

void pewpew() {

    int n;cin>>n;
    int a[n+1]{},pre[n+1]{},PRE[n+1]{};
    for (int i =1;i<=n;i++)cin>>a[i];
    for (int i =1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for (int i =1;i<=n;i++)PRE[i]=PRE[i-1]+pre[i];

    int sum=0;
    for (int i=1;i<=n;i++) {
        int sz = n-i+1;
        sum += a[i]*sz;
    }
    int blocks[n+1]{};
    for (int i =1;i<=n;i++) {
        blocks[i] = sum;
        int sz = n-i+1;
        sum-= a[i]*sz;
        blocks[i]+=blocks[i-1];
    }

    auto query = [&](int end) {
        int s = 1 , e = n , mid,block,final_index;
        while(s<=e) {
            mid = (s+e)>>1;
            int cur = summ(n) - summ(n-mid);
            if (end <= cur)
                block = mid , e = mid-1,final_index=cur;
            else
                s = mid+1;
        }
        int rt = blocks[block-1];
        int R = n-( final_index - end ) , L = block ;
        rt += PRE[R] - pre[L-1]*(R-L+1) - PRE[L-1] ;
        return rt;
    };

    int q;cin>>q;
    while(q--) {
        int l,r;cin>>l>>r;
        cout <<query(r) - query(l-1)<<"\n";
    }


}

signed main() {

    int Hi = 1;
    while (Hi--)
        pewpew();

}