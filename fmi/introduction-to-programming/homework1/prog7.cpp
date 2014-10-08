#include <iostream>
using namespace std;

bool isInArray(int arr[], int num, int arrlen) {
	for(int i=0;i<arrlen;i++) {
		if(arr[i] == num) return true;
	}
	return false;
}

int main() {
	int a[200], b[200], c[200], pars = 0;
	int alen, blen, clen;
	cin>>alen;
	for(int i=0;i<alen;i++) {
		cin>>a[i];
	}
	cin>>blen;
	for(int i=0;i<blen;i++) {
		cin>>b[i];
	}
	cin>>clen;
	for(int i=0;i<clen;i++) {
		cin>>c[i];
	}
	if(alen > blen && alen > clen) {
		for(int i=0;i<alen;i++) {
			if(isInArray(b, a[i], blen) && isInArray(c, a[i], clen)) {
				pars++;
			}
		}
	}
	else if(blen > alen && blen > clen) {
		for(int i=0;i<blen;i++) {
			if(isInArray(a, b[i], alen) && isInArray(c, b[i], clen)) {
				pars++;
			}
		}
	}
	else {
		for(int i=0;i<clen;i++) {
			if(isInArray(a, c[i], alen) && isInArray(b, c[i], blen)) {
				pars++;
			}
		}
	}
	cout<<pars;
	return 0;
}