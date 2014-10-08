#include <iostream>
using namespace std;

bool isTriangle(int** matrix, int length) {
	bool topNotTriangle = false, botNotTriangle = false;
	for(int i=0;i<length;i++) {
		for(int j=0;j<length;j++) {
			if(i < j && matrix[i][j] != 0) topNotTriangle = true; 
			if(i > j && matrix[i][j] != 0) botNotTriangle = true;
			if(topNotTriangle && botNotTriangle) return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	int** matrix = new int*[n];
	for(int i=0;i<n;i++) {
		matrix[i] = new int[n];
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	cout<<isTriangle(matrix, n);
	return 0;
}