#include <iostream>
#include <stack>
using namespace std;

int main() {
	
    int testCases;
    cin>>testCases;

    while(testCases != 0) {

        stack<char> operands;
        stack<char> operators;
        stack<char> finalExpression;
        string expression;

        cin>>expression;
        int openBracketsCount = 0;

        for(int i = 0; i < expression.length(); i++) {
            if(expression[i] == '(') {
                continue;
            } else if(expression[i] >= 97 && expression[i] <= 122) {
                finalExpression.push(expression[i]);
            } else if(expression[i] == ')') {
                    finalExpression.push(operators.top());
                    operators.pop();
            } else {
                operators.push(expression[i]);
            }
        }

        string finalOutput;
        while(!finalExpression.empty()) {
            finalOutput = finalExpression.top() + finalOutput;
            finalExpression.pop();
        }
        cout<<finalOutput<<endl;
        testCases--; 
    }
	return 0;
}