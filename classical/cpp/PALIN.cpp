#include <iostream>
using namespace std;

bool checkAll9s(string number) {
    for(int i = 0; i < number.length(); i++) {
        if(number[i] != '9') {
            return false;
        }
    }
    return true;
}

int main() {

    int testCases, nextNum;
    cin>>testCases;

    while(testCases != 0) {
        string inputNumber;
        cin>>inputNumber;
        char nextPalin[inputNumber.length() + 5];

        if(checkAll9s(inputNumber)) {
            nextPalin[0] = '1';
            int i;
            for(i = 1; i < inputNumber.length(); i++) {
                nextPalin[i] = '0';
            }
            nextPalin[inputNumber.length()] = '1';
            nextPalin[++i] = '\0';
            cout<<nextPalin<<endl;
        } else {

            long long firstHalf, secondHalf;
            firstHalf = inputNumber.length()/2;
            secondHalf = firstHalf;

            if(inputNumber.length() % 2 == 0) {
                firstHalf--;
            }

            while(firstHalf >= 0 && inputNumber[firstHalf] == inputNumber[secondHalf]) {
                firstHalf--;
                secondHalf++;
            }

            if(firstHalf < 0 || inputNumber[firstHalf] < inputNumber[secondHalf]) {
                firstHalf = inputNumber.length()/2;
                secondHalf = firstHalf;

                if(inputNumber.length() % 2 == 0) {
                    firstHalf--;
                }

                int carryTerm = 1;
                while(firstHalf >= 0) {
                    nextNum = ((inputNumber[firstHalf] - '0') + carryTerm);
                    carryTerm = nextNum / 10;
                    inputNumber[firstHalf] = nextNum % 10 + '0';
                    inputNumber[secondHalf] = inputNumber[firstHalf];
                    firstHalf--;
                    secondHalf++;
                }
            } else {
                while(firstHalf >= 0) {
                    inputNumber[secondHalf] = inputNumber[firstHalf];
                    firstHalf--;
                    secondHalf++;
                }
            }
            
            cout<<inputNumber<<endl;
        }

        testCases--;
    }

	return 0;
}