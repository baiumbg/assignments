#include <iostream>
#include <cmath>
using namespace std;

bool isNumber(char c){ 
	if(c>='0' && c<='9') return true;
	return false;
}

int toDec(string number, int base) {
	int result = 0, power = number.length() - 1;
	for(int i=0;i<number.length();i++, power--) {
		if(isNumber(number[i])) result+=(number[i]-'0')*pow(base, power);
		else result+=(number[i]-'7')*pow(base, power);
	}
	return result;
}

string toBase(int number, int base) {
	string result="";
	while(number>0) {
		int temp = number%base;
		if(temp < 10) result = (char)(temp+'0') + result;
		else result = (char)(temp+'7') + result;
		number/=base;
	}
	return result;
}

int main() {
	string number;
	int base, target;
	cin>>base>>target>>number;
	cout<<toBase(toDec(number, base), target);
	return 0;
}