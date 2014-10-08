#include <iostream>
#include <cmath>
using namespace std;

bool isInside(double x, double y) {
	double distance = sqrt((x+1)*(x+1)+y*y);
	if((x<=1 && x>=-1 && y<=1 && y>=-1 && distance>=1) || (x>=1 && x<=2 && y>=-1 && y<=0.5)) return true;
	return false;
}

int main() {
    double x,y;
	cin>>x>>y;
    cout<<isInside(x, y);
	return 0;
}