#include <iostream>
using namespace std;

bool isIdentifier(char c) {
	if(c == ' ' || c == '.' || c == ',' || c == ';' || c == '\0') return true;
	return false;
}

int main() {
	char text[1000];
	int i=0, maxlen = 0, currlen = 0, lengths[1000] = {0};
	cin.getline(text, 1000);
	while(!isIdentifier(text[i])) {
		maxlen++;
		i++;
	}
	lengths[maxlen] = 1;
	i++;
	while(text[i] != '\0') {
		if(isIdentifier(text[i])) {
			lengths[currlen]++;
			if(currlen > maxlen) {
				maxlen = currlen;
			}
			currlen = 0;
		}
		else currlen++;
		i++;
	}
	lengths[currlen]++;
	if(currlen > maxlen) maxlen = currlen;
	for(int i=1;i<maxlen;i++) {
		cout<<lengths[i]<<endl;
	}
	cout<<lengths[maxlen];
	return 0;
}