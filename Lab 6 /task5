#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int evaluatePrefix(string exp) {
    stack<int> st;

    for(int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if(isdigit(ch)) {
            st.push(ch - '0');
        }
        else if(isOperator(ch)) {
            if(st.size() < 2) {
                cout << "Invalid Expression!" << endl;
                return -1;
            }

            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int result = 0;

            switch(ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/':
                    if(op2 == 0) {
                        cout << "Division by Zero Error!" << endl;
                        return -1;
                    }
                    result = op1 / op2;
                    break;
                case '^': result = power(op1, op2); break;
            }
            st.push(result);
        }
    }

    if(st.size() != 1) {
        cout << "Invalid Expression!" << endl;
        return -1;
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    int result = evaluatePrefix(prefix);
    if(result != -1)
        cout << "Result = " << result << endl;

    return 0;
}
