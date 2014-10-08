#include <iostream>
#include <cmath>
using namespace std;

int numLength(int num) {
	int length = 0;
	while(num > 0) {
		num/=10;
		length++;
	}
	return length;
}

void replaceDigit(int& num, int digitToReplace, int digitToReplaceWith, int currentPosInNumber = 0) {
	if(pow(10, currentPosInNumber) > num) return;
	int currentDigit = (int)(num / pow(10, numLength(num) - currentPosInNumber - 1)) % 10;
	if(currentDigit == digitToReplace) {
		num += (digitToReplaceWith - digitToReplace)*pow(10, numLength(num) - currentPosInNumber - 1);
	}
	replaceDigit(num, digitToReplace, digitToReplaceWith, currentPosInNumber+1);
}

int main() {
	int n, a, b;
	cin>>n>>a>>b;
	replaceDigit(n, a, b);
	cout<<n;
	return 0;
}