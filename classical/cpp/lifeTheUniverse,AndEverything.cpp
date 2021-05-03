#include <iostream>
#include <unistd.h>
using namespace std;
 
int main() {
	int a;
	if (!isatty(0)) {
		while(cin >> a) {
			if(a == 42) {
				break;
			}
			cout << a << endl;
		}
	}
	return 0;
}