#include <iostream>
using namespace std;

bool areLinearlyDependent(double vec1[], double vec2[], int length) {
	for(int i=0;i<length-1;i++) {
		if(vec1[i]*vec2[i+1] - vec1[i+1]*vec2[i] != 0) return false;
	}
	return true;
}

int main() {
	double length, vec1[20], vec2[20];
	cin>>length;
	for(int i=0;i<length;i++) {
		cin>>vec1[i];
	}
	for(int i=0;i<length;i++) {
		cin>>vec2[i];
	}
	cout<<areLinearlyDependent(vec1, vec2, length);
	return 0;
}