#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Im going to put here an ideal solution, to this problem
//You when for the right way, but didnt know that we could use the stack library
/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top()=='(' && s[i]==')')
            {
                st.pop();
            }
            else if(st.top()=='[' && s[i]==']')
            {
                st.pop();
            }
            else if(st.top()=='{' && s[i]=='}')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size()==0;
    }
};
*/



class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int last_pos = stack.size() - 1;
        for (char & c : s) {
            if (c == '(' || c == '{' || c == '[') {
                last_pos++;
                stack.push_back(c); 
            } 
            else if (last_pos < 0) return false;
            else if ( c == ')' && stack.at(last_pos) != '('
                    || c == ']' && stack.at(last_pos) != '['
                    || c == '}' && stack.at(last_pos) != '{') {
                last_pos--;
                return false; 
            }
            else stack.pop_back(); 
        }
        if (!stack.empty()) return false;
        return true;
    }
};

int main() {

    Solution s = Solution();

    cout << s.isValid(")") << endl;

    return 0;
}
