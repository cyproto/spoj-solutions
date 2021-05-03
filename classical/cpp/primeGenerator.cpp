#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {

	int iterations;
	cin>>iterations;
	while(iterations){
		int low, high;
		cin>>low;
		cin>>high;
		
		int limit = floor(sqrt(high))+1;
		vector<int> prime;
		
		bool mark[limit+1];
		memset(mark, false, sizeof(mark));
		
		for(int i = 2; i*i<=high; ++i) {
			if(mark[i]==false){
				prime.push_back(i);
				for(int j = i; j <= limit; j += i) {
					mark[j] = true;
				}
			}
		}
		
		int n = high - low + 1;
		bool newmark[n+1];
		memset(newmark, false, sizeof(newmark));
		
		for(int i = 0; i < prime.size(); i++){
			int tempLim = floor(low/prime[i])*prime[i];
			if(tempLim < low)
				tempLim += prime[i];
				
			if(tempLim == prime[i])
				tempLim += prime[i];
				
			for(int j = tempLim; j <= high; j += prime[i]){
				newmark[j - low] = true;
			}
			
		}
		
		if(low == 0) {
			newmark[0] = true;
			newmark[1] = true;
		}
		
		if(low == 1) {
			newmark[0] = true;
		}
		for(int i = low; i <= high; i++){
			if(!newmark[i-low])
				cout<<i<<endl;
		}
		
		cout<<endl;
		iterations--;
	}

	return 0;
}