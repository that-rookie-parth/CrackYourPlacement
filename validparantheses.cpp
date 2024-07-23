#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>store;
        for(char c:s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                store.push(c);
            }
            else{
                if(store.empty()) {return false;}
                else if(c == '}' && store.top() == '{') store.pop();  
                else if(c == ')' && store.top() == '(') store.pop();   
                else if(c == ']' && store.top() == '[') store.pop(); 
                else {return false;}  
                }
        } 
        
        return store.empty();

    }
};

int main(){
    string s = "{[]}";
    bool ans;

    Solution obj;
    ans = obj.isValid(s); 

    cout << ans << endl;

    return 0;
}