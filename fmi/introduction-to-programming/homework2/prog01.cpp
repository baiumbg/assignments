#include <iostream>
#include <cmath>
using namespace std;

double area(double a, double b, double c) {
	double p = (a + b + c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int maxIndex(double* areas, int length) {
	double max = areas[0];
	int maxIndex = 0;
	for(int i=1;i<length;i++) {
		if(max < areas[i]) {
			max = areas[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

int main() {
	int n;
	cin>>n;
	double* areas = new double[n];
	for(int i=0;i<n;i++) {
		double a, b, c;
		cin>>a>>b>>c;
		areas[i] = area(a, b, c);
	}
	cout<<maxIndex(areas, n);
	return 0;
}