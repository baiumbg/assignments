#include <iostream>
using namespace std;

int main() {
	double x1, x2, x3, y1, y2, y3, z1, z2, z3, c1, c2, c3;
	cin>>x1>>y1>>z1>>c1>>x2>>y2>>z2>>c2>>x3>>y3>>z3>>c3;
	double D = x1*y2*z3 + x2*y3*z1 + x3*y1*z2 - x3*y2*z1 - x2*y1*z3 - x1*y3*z2;
	double Dx = c1*y2*z3 + c2*y3*z1 + c3*y1*z2 - c3*y2*z1 - c2*y1*z3 - c1*y3*z2;
	double Dy = x1*c2*z3 + x2*c3*z1 + x3*c1*z2 - x3*c2*z1 - x2*c1*z3 - x1*c3*z2;
	double Dz = x1*y2*c3 + x2*y3*c1 + x3*y1*c2 - x3*y2*c1 - x2*y1*c3 - x1*y3*c2;
	if(D == 0) {
		if(Dx == 0 && Dy == 0 && Dz == 0) cout<<"Many solutions";
		else cout<<"No solution";
	}
	else {
		cout<<(double)Dx/D<<' '<<(double)Dy/D<<' '<<(double)Dz/D;
	}
	return 0;
}
