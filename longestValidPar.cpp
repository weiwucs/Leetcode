//Tags: DP, String

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Optimized DP
 */
int longestValidParentheses(string s){
        if(s.empty()) return 0;
        stack<int> sta;
        int maxlen = 0;
        int len = 0;

        for(int i=0; i<s.length(); i++) {
                if(s.at(i) == '(') sta.push(i);
                else if(sta.empty()) len = 0;
                else{
                        int matchedPos = sta.top();
                        sta.pop();
                        int matchedLen = i - matchedPos + 1;
                        if(sta.empty()) {//()()
                                len += matchedLen;
                                matchedLen = len;
                        } else matchedLen = i - sta.top(); //()(()()
                        maxlen = max(maxlen, matchedLen);
                }
        }
        return maxlen;
}

/**
 * DP
 */
int longestValidParenthesesB(string s){
        if(s.empty() || s.length() == 0) return 0;

        stack<int> sta;
        int dp[s.length()] = {0};
        int maxlen = 0;

        for(int i = 0; i < s.length(); i++) {
                if(s.at(i) == '(') sta.push(i);
                else if(sta.empty()) continue;
                else if(sta.top() > 0) {
                        dp[i] = 2 + dp[sta.top() - 1] + dp[i - 1];//()(()()
                        sta.pop();
                }else {
                        dp[i] = 2 + dp[i-1];//()()
                        sta.pop();
                }
                maxlen = max(dp[i], maxlen);
        }
        return maxlen;
}


/**
 * Two pass
 * use a stack to store index of unmatched parentheses
 * go through the stack and find maximum of different between indices
 * include len - first and last - 0
 */
int longestValidParenthesesC(string s){
        stack<int> sta;
        int len = s.length();
        int longest = 0;

        for(int i = 0; i < len; i++) {
                if(s.at(i) == '(') sta.push(i);
                else if(s.at(i) == ')' && !sta.empty() && s.at(sta.top()) == '(') sta.pop(); //pop if there is a pair.
                else sta.push(i); //right paren, empty ot top is also right.
        }

        if(sta.empty()) return len; //all valid
        //calculate longest length between each unpaired
        int a = len, b = 0;
        while(!sta.empty()) {
                b = sta.top();
                sta.pop();
                longest = max(longest, a - b -1);//update longest
                a = b;
        }
        longest = max(longest, a);//compare with last - 0
        return longest;
}

int main(){
        cout << longestValidParentheses("()(()()") <<endl;
        cout << longestValidParenthesesB("()(()()") <<endl;
        cout << longestValidParenthesesC("()(()()") <<endl;
        return 0;
}
