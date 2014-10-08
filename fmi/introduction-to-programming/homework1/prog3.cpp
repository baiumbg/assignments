#include <iostream>
using namespace std;

int main() {
	int n, counter = 0, nlcounter = 0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		if(counter == nlcounter) {
			if(i != n) {
				counter = 0;
				nlcounter++;
				cout<<i<<endl;
			}
			else {
				cout<<i;
				return 0;
			}
		}
		else {
			cout<<i<<' ';
			counter++;
		}
	}
	while(counter<=nlcounter) {
		cout<<'*';
		if(counter != nlcounter) cout<<' ';
		counter++;
	}
	return 0;
}