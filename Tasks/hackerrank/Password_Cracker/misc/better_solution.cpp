#include<bits/stdc++.h>
using namespace std;
string s[10],p,memo[2010];
int n;
int match(string &w) {
    int i,j;
    bool f;
    for(i=0;i<n;i++) {
        if(w.size()!=s[i].size())
            continue;
        f=0;
        for(j=0;j<w.size();j++) {
            if(s[i][j]!=w[j]) {
                f=1;
                break;
            }
        }
        if(!f)
            return i;
    }
    return -1;
}
string check(int i) {
    if(i==p.size()) {
        return "";
    }
    if(memo[i]!="")
        return memo[i];
    string w="",ret;
    int j;
    for(;i<p.size();i++) {
        w+=p[i];
        j=match(w);
        if(j!=-1) {
            ret=check(i+1);
            memo[i+1]=ret;
            if(ret!="*")
                return w + " " + ret;
        }
    }
    memo[i]="*";
    return "*";
}
int main() {
    int t,i;
    string ans;
    cin>>t;
    while(t--) {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>s[i];
        cin>>p;
        for(i=0;i<p.size();i++)
            memo[i]="";
        ans=check(0);
        if(ans=="*")
            cout<<"WRONG PASSWORD\n";
        else
            cout<<ans<<'\n';
    }
    return 0;
}
