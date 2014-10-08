#include <iostream>
#include <string>
using namespace std;

bool isLetter(char c) {
	if(c >= 'a' && c <= 'z') return true;
	return false;
}

char* encode(char* source, char const* alpha) {
	char* encodedString = new char[strlen(source)+1];
	for(int i=0;i<strlen(source);i++) {
		if(isLetter(source[i])) {
			encodedString[i] = alpha[(int)(source[i] - 'a')];
		}
		else {
			encodedString[i] = source[i];
		}
	}
	encodedString[strlen(source)] = '\0';
	return encodedString;
}

int main() {
	char* source = new char[1000];
	char* alpha = new char[26];
	cin.getline(source, 1000);
	cin>>alpha;
	cout<<encode(source, alpha);
	return 0;
}