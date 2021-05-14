#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases = 0;
    cin>>testCases;

    while(testCases > 0) {

        long long numberOfStalls;
        cin>>numberOfStalls;

        long long numberOfCows;
        cin>>numberOfCows;

        long long stalls[numberOfStalls];
        long long left, right, mid, minDist = 0;
        right = 0;
        left = 0;
        for(int i = 0; i < numberOfStalls; i++) {
            cin>>stalls[i];
            if(right < stalls[i])
                right = stalls[i];
        }

        sort(stalls, stalls + numberOfStalls);

        while(left<=right) {
            mid = (left + right)/2;
            
            bool flag = false;
            int currentPlace = stalls[0];
            long long count = 1;

            for(int i = 1; i < numberOfStalls; i++) {
                if((stalls[i] - currentPlace) >= mid) {
                    currentPlace = stalls[i];
                    if(++count == numberOfCows) {
                        flag = true;
                        break;
                    }
                }
            }

            if(flag == true) {
                left = mid + 1;
                minDist = mid;
            } else {
                right = mid - 1;
            }

        }

        cout<<minDist<<endl;
        testCases--;
    }
    
    return 0;
}