#include <iostream>
using namespace std;

int main() {
	int n, matrix[20][20], count=0;
	bool isNull;
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	// diagonali tip /
	for (int k = n - 1; k > -n; k--) {
		isNull = true;
		if (k % 2 == 0) {
			for (int i = n - 1; i >= 0; i--) {
				if (i - k < n && i - k >= 0 && matrix[i][i - k] != 0) {
					isNull = false;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i - k < n && i - k >= 0 && matrix[i][i - k] != 0) {
					isNull = false;
					break;
				}
			}
		}
		if(isNull) count++;
	}
	//diagonali tip
	for (int k = 0; k < 2 * n - 1; k++) {
		isNull = true;
		if (k % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (k - i >= 0 && k -i < n && matrix[i][k - i] != 0) {
					//cout<<"Saw something not null at: ["<<i<<"]["<<k-i<<"]\n";
					isNull = false;
					break;
				}
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				if (k-i < n && k-i >= 0 && matrix[i][k-i] != 0) {
					//cout<<"Saw something not null at: ["<<i<<"]["<<k-i<<"]\n";
					isNull = false;
					break;
				}
			}
		}
		if(isNull) count++;
	}
	cout<<count;
	return 0;
}