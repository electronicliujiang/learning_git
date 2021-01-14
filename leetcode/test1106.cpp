//解析布尔表达式  hard
/*
给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
*/
#include<vector>
#include<string>
#include<stack>
using namespace  std;


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> sc1,sc2;
        for(int i=0;i<expression.size();++i){
            if(expression[i]=='!' || expression[i]=='|' || expression[i]=='&'){
                sc1.push(expression[i]);
            }
            else if(expression[i]!=')'){
                sc2.push(expression[i]);
            }
            else{
                int t=0;
                int f=0;
                while(sc2.top()!='('){
                    if(sc2.top()=='t'){
                        t++;
                    }
                    else if(sc2.top()=='f'){
                        f++;
                    }
                    sc2.pop();
                }
                sc2.pop();
                char sign=sc1.top();
                sc1.pop();
                if(sign=='!'){
                    if(f==1){
                        sc2.push('t');
                    }
                    else{
                        sc2.push('f');
                    }
                }
                else if(sign=='|'){
                    if(t!=0){
                        sc2.push('t');
                    }
                    else{
                        sc2.push('f');
                    }
                }
                else if(sign=='&'){
                    if(f!=0){
                        sc2.push('f');
                    }
                    else{
                        sc2.push('t');
                    }
                }
            }
        }
        return sc2.top()=='t';
    }
};