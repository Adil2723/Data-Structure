#include <iostream>
#include <stack>
using namespace std;

class PostfixEvaluator {
private:
    stack<int> st;

public:
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int evaluate(string exp) {
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            if (isdigit(ch)) {
                st.push(ch - '0'); // Convert char to int
            }
            else if (isOperator(ch)) {
                if (st.size() < 2) {
                    cout << "Invalid Expression!" << endl;
                    return -1;
                }
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                int result = 0;

                switch (ch) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': 
                        if (op2 == 0) {
                            cout << "Division by zero error!" << endl;
                            return -1;
                        }
                        result = op1 / op2;
                        break;
                }
                st.push(result);
            }
        }

        if (st.size() != 1) {
            cout << "Invalid Expression!" << endl;
            return -1;
        }

        return st.top();
    }
};

int main() {
    PostfixEvaluator obj;
    string expression;

    cout << "Enter Postfix Expression: ";
    cin >> expression;

    int result = obj.evaluate(expression);

    if (result != -1)
        cout << "Result = " << result << endl;

    return 0;
}
