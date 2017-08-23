#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

const int maxDiv10 = INT_MAX / 10;

bool isDigit(char c){
	if(c >= '0' && c <= '9') return true;
	else return false;
}

int getNumericValue(char c){
	if(isDigit(c)){
		return c - '0';
	}
}

int atoi(string s){
	int length = s.length();
	int i = 0;
	while(i < length && s.at(i) == ' ') i++;
	int sign = 1;
	if(i < length && s.at(i) == '+'){
		i++;
	}
	if(i < length && s.at(i) == '-'){
		sign = -1;
		i++;
	}
	long num = 0;
	while(i < length && isDigit(s.at(i))){
		int digit = getNumericValue(s.at(i));
		if(num > maxDiv10 || num == maxDiv10 && digit >= 8){
			return sign == 1 ? INT_MAX : INT_MIN;
		}
		num = num * 10 + digit;
		i++;
	}
	return sign*num;
}


int main(){
	string str = "-9876aaa";
	cout << atoi(str) << endl;
	return 0;
}
