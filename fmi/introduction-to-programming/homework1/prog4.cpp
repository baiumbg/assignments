#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, count=0;
	cin>>a;
	for(int k=1;k<a;k++) {
			double m = sqrt(a*a - k*k);
			if(m - floor(m) == 0) {
				if(count > 0) cout<<endl;
				count++;
				cout<<k<<' '<<m;
			}
	}
	if(count == 0) cout<<"No solution";
	return 0;
}