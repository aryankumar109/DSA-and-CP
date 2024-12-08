#include <bits/stdc++.h>

void sortInsert(stack<int> &st, int num) {
	if(st.empty() || st.top() < num){
		st.push(num);
		return;
	}

	int x = st.top();
	st.pop();

	// Recursive call
	sortInsert(st, num);

	st.push(x);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	// recursive call
	sortStack(stack);

	sortInsert(stack, num);
}