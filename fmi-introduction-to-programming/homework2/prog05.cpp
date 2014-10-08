#include <iostream>
#include <string>
using namespace std;

bool isDelimiter(char c) {
	if(c == ' ' || c == '.' || c == ',' || c == ';' || c == '?') return true;
	return false;
}

char const* reverseWordsOnly(const char* sentence) {
	int wordBegin, wordEnd;
	char* reversedString = new char[strlen(sentence)+1];
	for(int i=0;i<strlen(sentence);i++) {
		if(!isDelimiter(sentence[i])) {
			wordBegin = i;
			wordEnd = i;
			while(i < strlen(sentence) && !isDelimiter(sentence[i])) {
				i++;
				wordEnd++;
			}
			for(int j = wordEnd-1, k = wordBegin;j>=wordBegin;j--, k++) {
				reversedString[k] = sentence[j];
			}
			if(i < strlen(sentence)) reversedString[i] = sentence[i];
		}
		else reversedString[i] = sentence[i];
	}
	reversedString[strlen(sentence)] = '\0';
	return reversedString;
}

int main() {
	char* sentence = new char[1000];
	cin.getline(sentence, 1000);
	cout<<reverseWordsOnly(sentence);
	return 0;
}