#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int left, int right, string res, vector<string>& ans){
	if(left == 0 && right == 0){
		ans.push_back(res);
		return;
	}
	if(left > 0) dfs(left -1, right + 1, res + "(", ans);
	if(right > 0) dfs(left, right - 1, res + ")", ans);
}

vector<string> generateParenthesis(int n){
	vector<string> ans;
	if(n <= 0) return ans;
	dfs(n, 0, "", ans);
	return ans;
}

int main(){
	vector<string> ans;
	ans = generateParenthesis(3);
	for(string one : ans){
		cout << one << endl;
	}
	return 0;
}

