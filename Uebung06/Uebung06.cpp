#include <iostream>
#include <string>
#include <regex>

#include "Stack.h"

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

string infixToPostfix(string infix) {
    Stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (s.top() != '(') {
                postfix += s.pop();
            }
            s.pop();
        }
        else {
            postfix += c;
        }
    }

    while (!s.empty()) {
        postfix += s.pop();
    }

    return postfix;
}

double evaluatePostfix(string postfix) {
    Stack<double> s;
    double op1, op2;

    for (char c : postfix) {
        if (isdigit(c)) {
            double digit = c - '0';
            s.push(digit);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            op2 = s.pop();
            op1 = s.pop();

            switch (c) {
            case '+': 
                s.push(op1 + op2); 
                break;
            case '-': 
                s.push(op1 - op2); 
                break;
            case '*': 
                s.push(op1 * op2); 
                break;
            case '/': 
                s.push(op1 / op2); 
                break;
            }
        }
    }
    return s.top();
}

int main() {
    //Infix to Postfix
    string infix = "5+(4-2)*2";
    string new_postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << new_postfix << endl;

    //Postfix evaluation
    string postfix = "72-13+*8/"; // "48*8+42/+" //<23 a)
    double result = evaluatePostfix(postfix);
    cout << "Ergebnis: " << result << endl;


    return 0;
}


//void to_infix(char postfix_value[], Stack<char>& toInf) {
//	int size = sizeof(postfix_value) - 1;
//
//	for (int i = 0; i < size; i++) {
//		if (postfix_value[i]=='(') {															//step 1
//			toInf.push(postfix_value[i]);
//		}
//		else if (isdigit(postfix_value[i])) {													//step 2
//			cout << postfix_value[i];
//		}
//		else if (regex_match(to_string(postfix_value[i]), regex("\/|\*"))) {					//step 3
//			while (regex_match(to_string(toInf.top()), regex("\/|\*|\+|-")) && !toInf.empty()) {
//				cout << toInf.pop();
//			}
//			toInf.push(postfix_value[i]);
//		}
//		else if (regex_match(to_string(postfix_value[i]), regex("\+|-"))) {						//step 3
//			while (regex_match(to_string(toInf.top()), regex("\+|-")) && !toInf.empty()) {
//				cout << toInf.pop();
//			}
//			toInf.push(postfix_value[i]);
//		}
//		else if (postfix_value[i] == ')') {														//step 4
//			while (regex_match(to_string(toInf.top()), regex("\/|\*|\+|-"))) {
//				cout << toInf.pop();
//			}
//			toInf.pop();
//		}
//	}
//
//	while (!toInf.empty()) {
//		cout << toInf.pop();
//	}
//	
//	cout << endl;
//}
//
//int main() {
//	Stack<char> toInf;
//	Stack<char> toPos;
//
//	char postfix_value[] = "542-2*+";
//	const char* infix_value = "5+(4-2)*2";
//
//	to_infix(postfix_value, toInf);
//}
