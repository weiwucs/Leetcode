#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string letters[] = {
	"",  //0
	"",  //1
	"abc", //2
	"def", //3
	"ghi", //4
	"jkl", //5
	"mno", //6
	"pqrs", //7
	"tuv", //8
	"wxyz" //9
};
void helper(string digits, int s, string comb, vector<string>& res);
vector<string> lettercombinations(string digits);

	/**
	 *backtracing to generate all combinations
	 * */

vector<string> lettercombinations(string digits){
	vector<string> res;
	if(digits.empty()) return res;

	helper(digits, 0, "", res);
	return res;
}

void helper(string digits, int s, string comb, vector<string>& res){
	if(s == digits.length()){
		res.push_back(comb);
		return;
	}
	string c = letters[digits.at(s) - '0'];
	for(int i = 0; i < c.length(); i++){
		helper(digits, s + 1, comb + c.at(i), res);
	}
}

int main(){
	string ex = "23";
	vector<string> res;

	res = lettercombinations(ex);
	cout << "bigin" << endl;
	for(string one : res){
		cout << one << endl;
	}
	cout << "end" << endl;
	return 0;
}
