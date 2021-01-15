#include<iostream>
#include<vector>
#include<map>
using namespace std;

class UnionFind{
public:
    map<int,int> father;
    int count=0;
    UnionFind(){
    }
    int find_father(int x){
        int root=x;
        if(father.count(x)==0){
            father[x]=x;
            count++;
        }
        while(root!=father[root]){
            root=father[root];
        }
        return root;
    }
    int get_count(){
        return count;
    }
    void merge(int x,int y){
        int root_x=find_father(x);
        int root_y=find_father(y);
        if(root_x!=root_y){
            father[root_x]=root_y;
            count--;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for(auto ele:stones){
            uf.merge(ele[0]+10000,ele[1]);
        }
        return stones.size()-uf.get_count();
    }
};

int main947(){
    cout<<"hahah"<<endl;
    cout<<"hahah"<<endl;
    cout<<"hahah"<<endl;
    Solution s;
    vector<vector<int>> stones={{0,0},{0,2},{1,1},{2,0},{2,2}};
    int res=s.removeStones(stones);
    cout<<res<<endl;
    return 0;
}