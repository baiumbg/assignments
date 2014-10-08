#include <iostream>
using namespace std;

int recFunc(int x, int n) {
	if(n == 1) return 1;
	return recFunc(x, n-1)*x + n;
}

int main() {
	int x, n;
	cin>>n>>x;
	cout<<recFunc(x, n);
	return 0;
}