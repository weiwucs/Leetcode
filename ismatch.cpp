#include <iostream>
#include <string>

using namespace std;

bool ismatch(string s, string p){
	int slen = s.length();
	int plen = p.length();
	if(s.empty() || p.empty()) return s == p;
	if(slen == 0 && plen == 0) return true;
	
	bool mat[slen + 1][plen + 1];
	mat[0][0] = true;

	for(int i = 1; i <= slen; i++) mat[i][0] = false;
	for(int j = 1; j <= plen; j++){
		if(p.at(j - 1) == '*'){
			mat[0][j] = mat[0][j - 2];
		}else{
			mat[0][j] = false;
		}
	}
			
	for(int i = 1; i <= slen; i++)
		for(int j = 1; j <= plen; j++){
			if(s.at(i - 1) == p.at(j - 1) || p.at(j - 1) == '.'){
				mat[i][j] = mat[i - 1][j - 1];
			}else if(p.at(j - 1) == '*'){
				if(p.at(j - 2) == s.at(i - 1) || p.at(j - 2) == '.'){
					mat[i][j] = mat[i - 1][j] || mat[i][j -2] || mat[i][j - 1];
				}else{
					mat[i][j] = mat[i][j - 2];
				}
			}else{
				mat[i][j] = false;
			}
			//cout << "i: " << i << " j: " << j << " " << mat[i][j];
		}
	return mat[slen][plen];
}

int main(){
	cout << "aab c*a*b: " << ismatch("aab", "c*a*b") << endl;
	cout << "aaaa a*: " << ismatch("aaaa", "a*") << endl;
	cout << "aaa aa: " << ismatch("aaa", "aa") << endl;
	return 0;
}
