#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,int& count,vector<vector<int>>& land){
        if(x>=land.size() || y>=land[0].size()){
            return;
        }
        if(land[x][y]==0){
            count++;
            land[x][y]=1;
        }
        else{
            return;
        }   
        dfs(x+1,y,count,land);
        dfs(x,y+1,count,land);
        dfs(x-1,y,count,land);
        dfs(x,y-1,count,land);
        dfs(x+1,y+1,count,land);
        dfs(x-1,y-1,count,land);
        dfs(x+1,y-1,count,land);
        dfs(x-1,y+1,count,land);
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        set<vector<int>> visited;
        for(int i=0;i<land.size();++i){
            for(int j=0;j<land[i].size();++j){
                int count=0;
                if(land[i][j]==0){
                    dfs(i,j,count,land);
                    res.push_back(count);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

int main(){
    cout<<"hello world"<<endl;
    cout<<"hello world"<<endl;
    Solution s;

    return 0;
}