/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

*/

//left max_heap  right min_heap
#include<queue>
#include<iostream>

using namespace std;

class MedianFinder{
public:
    priority_queue<int,vector<int>,less<int>> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    MedianFinder(){

    }
    void addNum(int num){
        if(max_heap.size()==min_heap.size()){
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }
    double findMedian(){
        if(min_heap.size()==max_heap.size()){
            return (min_heap.top()+max_heap.top())/2.0;
        }
        else{
            return min_heap.top();
        }
    }

};



int main(){
    cout<<"hello world"<<endl;
    return 0; 
}


