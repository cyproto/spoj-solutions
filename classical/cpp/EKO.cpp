#include <iostream>
using namespace std;

int main() {
    long long treesCount;
    cin>>treesCount;

    int heightToCut;
    cin>>heightToCut;

    long long trees[treesCount];
    long long left, right, mid;
    right = 0;
    left = 0;
    long long cutHeight = 0;
    for(int i = 0; i < treesCount; i++) {
        cin>>trees[i];
        if(right < trees[i])
            right = trees[i];
    }

    while(left<=right) {
        cutHeight = 0;
        mid = (left + right)/2;
        for(int i = 0; i < treesCount; i++) {
            if(mid < trees[i])
                cutHeight += trees[i] - mid;
        }

        if(heightToCut <= cutHeight){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout<<right;    
}