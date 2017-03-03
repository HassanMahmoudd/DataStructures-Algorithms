#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expression);
int performOperation(char operation, int operand1, int operand2);
bool isOperator(char C);
bool isNumeric(char C);

string infixToPostfix(string infixExpression);
bool hasHigherPrecedence(char op1, char op2);
int operatorWeight(char C);

int main()
{
	string postfixExpression = "10 5 * 6 +";
	int result = evaluatePostfix(postfixExpression);
	cout << result << endl;
	string infixExpression = "(10 * 5) + 6";
	string infixToPostfixExpression = infixToPostfix(infixExpression);
	cout << infixToPostfixExpression << endl;
}

int evaluatePostfix(string expression) {
	stack<int> S;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		else if (isOperator(expression[i])) {
			int operand2 = S.top();
			S.pop();
			int operand1 = S.top();
			S.pop();
			int res = performOperation(expression[i], operand1, operand2);
			S.push(res);
		}

		else if (isNumeric(expression[i])) {
			int operand = 0;
			while (i < expression.length() && isNumeric(expression[i])) {
				operand = operand * 10 + (expression[i] - '0');
				i++;
			}
			i--;
			S.push(operand);
		}
	}
	return S.top();
}

int performOperation(char operation, int operand1, int operand2) {
	if (operation == '+')
		return operand1 + operand2;
	else if (operation == '-')
		return operand1 - operand2;
	else if (operation == '*')
		return operand1 * operand2;
	else if (operation == '/')
		return operand1 / operand2;
}

bool isNumeric(char C)
{
	if (C >= '0' && C <= '9') return true;
	return false;
}

bool isOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}

string infixToPostfix(string expression) {
	stack<char> S;
	string result = "";
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ' || expression[i] == ',')
			continue;
		else if (isOperator(expression[i])) {
			while (!S.empty() && S.top() != '(' && hasHigherPrecedence(S.top(), expression[i])) {
				result += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		else if (isNumeric(expression[i])) {
			int operand = 0;
			while (i < expression.length() && isNumeric(expression[i])) {
				operand = operand * 10 + (expression[i] - '0');
				i++;
			}
			i--;
			string s = to_string(operand);
			result += s + " ";
		}
		else if (expression[i] == '(') {
			S.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!S.empty() && S.top() != '(') {
				result += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while (!S.empty()) {
		result += S.top();
		S.pop();
	}
	return result;
}

int operatorWeight(char C) {
	switch (C)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

bool hasHigherPrecedence(char op1, char op2) {
	int op1Weight = operatorWeight(op1);
	int op2Weight = operatorWeight(op2);
	bool value = op1Weight > op2Weight ? true : false;
	return value;
}
