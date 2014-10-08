#include <iostream>
using namespace std;

int longestNonDecreasingSequence(int* array, int length) {
    int maxSequenceLength = 1, currentSequenceLength = 1, currentSequenceNumber = array[0];
    for(int i=0;i<length;i++) {
        for(int j=i+1;j<length;j++) {
        	if(currentSequenceNumber <= array[j]) {
        		currentSequenceLength++;
        		currentSequenceNumber = array[j];
        	}
        }
        if(currentSequenceLength > maxSequenceLength) maxSequenceLength = currentSequenceLength;
        currentSequenceLength = 1;
        currentSequenceNumber = array[i];
    }
    return maxSequenceLength;
}

int main() {
    int n;
    cin>>n;
    int* array = new int[n];
    for(int i=0;i<n;i++) {
        cin>>array[i];
    }
    cout<<longestNonDecreasingSequence(array, n);
    return 0;
}