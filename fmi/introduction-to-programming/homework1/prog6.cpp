#include <iostream>
using namespace std;

bool isInArray(int arr[], int num, int arrlen) {
	for(int i=0;i<arrlen;i++) {
		if(arr[i] == num) return true;
	}
	return false;
}

int main() {
	int a[100], b[100], n, bn = 0;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		if(isInArray(b, a[i], bn)) continue;
		b[bn] = a[i];
		bn++;
	}
	cout<<bn<<endl;
	for(int i=0;i<bn-1;i++) {
		cout<<b[i]<<' ';
	}
	cout<<b[bn-1];
	return 0;
}