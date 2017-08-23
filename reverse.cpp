#include <iostream>
#include <limits.h>

using namespace std;

int reverse(int a){
	long out = 0;
	while(a!=0){
		out = out * 10 + a % 10;
		a = a / 10;
	}
	if(out > INT_MAX || out < INT_MIN) return 0;
	return (int)out;
}

int main(){
	cout << reverse(-321) << endl;
	return 0;
}
