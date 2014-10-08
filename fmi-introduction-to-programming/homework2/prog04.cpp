#include <iostream>
#include <string>
using namespace std;

void printBottomLeft(string** table, int startX, int startY, int endX, int endY, int actionsDone, int totalActions);
void printTopRight(string** table, int startX, int startY, int endX, int endY, int actionsDone, int totalActions) {
	int i, j, counter = actionsDone;
	for(i = startY; i > endY; i--, counter++) {
		cout<<table[i][startX];
		if(counter < totalActions-1) cout<<' ';
	}
	for(j = startX; j >= endX; j--, counter++) {
		cout<<table[endY][j];
		if(counter < totalActions-1) cout<<' ';
	}
	if(counter < totalActions) {
		printBottomLeft(table, endX, endY+1, startX-1, startY, counter, totalActions);
	}
}

void printBottomLeft(string** table, int startX, int startY, int endX, int endY, int actionsDone, int totalActions) {
	int i, j, counter = actionsDone;
	for(i = startY; i < endY; i++, counter++) {
		cout<<table[i][startX];
		if(counter < totalActions-1) cout<<' ';
	}
	for(j = startX; j <= endX; j++, counter++) {
		cout<<table[endY][j];
		if(counter < totalActions-1) cout<<' ';
	}
	if(counter < totalActions) {
		printTopRight(table, endX, endY-1, startX+1, startY, counter, totalActions);
	}
}

int main() {
	int n;
	cin>>n;
	string** table = new string*[n];
	for(int i=0;i<n;i++) {
		table[i] = new string[n];
		for(int j=0;j<n;j++) {
			cin>>table[i][j];
		}
	}
	printTopRight(table, n-1, n-1, 0, 0, 0, n*n);
	return 0;
}