#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution_error {
public:
    vector<int> res;
    void recur(string s){
        if(s.size()==3 && (s[1]=='|' || s[1]=='^' || s[1]=='&')){
            int a=s[0]-'0';
            int b=s[2]-'0';
            if(s[1]=='|'){
                res.push_back(a|b);
                return;
            }
            else if(s[1]=='^'){
                res.push_back(a^b);
                return;
            }
            else{
                res.push_back(a&b);
                return;
            }
        }
        int a=(s[0]-'0');
        if(s[1]=='|'){
            recur(to_string(a|(s[2]-'0'))+s.substr(3));
            if(s.substr(2).size()>=3){
                recur(s.substr(2));
                int x=(res.back()|a);
                res.pop_back();
                res.push_back(x);
            }
                

        }
        else if(s[1]=='^'){
            recur(to_string(a^(s[2]-'0'))+s.substr(3));
            if(s.substr(2).size()>=3){
                recur(s.substr(2));
                int x=(res.back()^a);
                res.pop_back();
                res.push_back(x);
            }
        }
        else if(s[1]=='&'){
            recur(to_string(a&(s[2]-'0'))+s.substr(3));
            if(s.substr(2).size()>=3){
                recur(s.substr(2));
                int x=(res.back()&a);
                res.pop_back();
                res.push_back(x);
            }
        }
    }
    int countEval(string s, int result) {
        recur(s);
        int ans=0;
        for(auto ele:res){
            if(ele==result){
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
private:
    vector<char> arr;
    vector<vector<vector<int>>> dp;
public:
    int cal(int i,int j,char sign){
        if(sign=='|'){
            return i|j;
        }
        else if(sign=='&'){
            return i&j;
        }
        else if(sign=='^'){
            return i^j;
        }
    }
    int recur(int start,int end,int result){
        if(start==end){
            return arr[start]-'0' ==result?1:0;
        }
        //记忆化搜索  ！=-1  防止冗余
        if(dp[start][end][result]!=-1){
            return dp[start][end][result];
        }
        int count=0;
        //计算此次的数量
        for(int k=start;k<end;k+=2){
            char sign=arr[k+1];
            for(int i=0;i<=1;++i){
                for(int j=0;j<=1;++j){
                    if(cal(i,j,sign)==result){
                        count+=recur(start,k,i)*recur(k+2,end,j);
                    }
                }
            }
        }
        dp[start][end][result]=count;
        return count;
    }
    int countEval(string s, int result) {
        int n=s.size();
        arr=vector<char>(n);
        for(int i=0;i<n;++i){
            arr[i]=s[i];
        }
        //dp[s][e][r]  表示从区间 start-end之间值为result的元素的个数
        dp=vector<vector<vector<int>>> (n,vector<vector<int>>(n,vector<int>(2,-1)));
        return recur(0,n-1,result);
    }
};


int main(){
    Solution s;
    int res=s.countEval("0&0&0&1^1|0",1);
    return 0;
}