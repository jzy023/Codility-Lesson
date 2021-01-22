/*
A string S consisting of N characters is considered to be properly 
nested if any of the following conditions is true:

	> S is empty;
	> S has the form "(U)" or "[U]" or "{U}" where U is a properly 
	  nested string;
	> S has the form "VW" where V and W are properly nested strings.


For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

	int solution(string &S);

that, given a string S consisting of N characters, returns 1 if S is 
properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given 
S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

	> N is an integer within the range [0..200,000];
	> string S consists only of the following characters: "(", "{", "[", 
	  "]", "}" and/or ")".
*/

#include <string>
#include <stack>
#include <map>

int solution(std::string &S) {
	// exceptions
	if((int) S.size() == 0){
		return 1;
	}
	else if ((int) S.size() == 1){
		return 0;
	}

	// initialization
	std::stack<char> myStack;
	std::map<char,int> start{{'(',1}, {'[',2}, {'{',3}};
	std::map<char,int> end{{')',1}, {']',2}, {'}',3}};

	// compute
	for (int ch : S){
		if (ch == '(' || ch == '[' || ch == '{')
		{
			myStack.push(ch);
		}
		else if (end[ch] == start[myStack.top()]){
			myStack.pop();
		}
		else{
			return 0;
		}
	}
	return(myStack.size() == 0) ? 1 : 0;
}