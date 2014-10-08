#include <iostream>
using namespace std;

bool contains(int array[], int length, int num) {
	for(int i=0;i<length;i++) {
		if(array[i] == num) return true;
	}
	return false;
}

bool areAlike(int rowA[], int rowB[], int length) {
	for(int i=0;i<length;i++) {
		if(!contains(rowA, length, rowB[i])) return false;
	}
	for(int i=0;i<length;i++) {
		if(!contains(rowB, length, rowA[i])) return false;
	}
	return true;
}

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	int** matrix = new int*[m];
	for(int i=0;i<m;i++) {
		matrix[i] = new int[n];
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	for(int i=0;i<m;i++) {
		if(i < m-1 && i != k && areAlike(matrix[i], matrix[k], n)) cout<<i<<' ';
		else if(i == m-1 && i != k && areAlike(matrix[i], matrix[k], n)) cout<<i;
	}
	return 0;
}