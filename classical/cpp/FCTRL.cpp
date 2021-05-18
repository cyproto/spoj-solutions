#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int testCases;
    cin>>testCases;

    while(testCases != 0) {
        long long int inputNumber;
        cin>>inputNumber;
        int count = 0;

        for(int i = 5; inputNumber / i > 0; i *= 5) {
            count += floor(inputNumber / i);
        }

        cout<<count<<endl;

        testCases--; 
    }

	return 0;
}