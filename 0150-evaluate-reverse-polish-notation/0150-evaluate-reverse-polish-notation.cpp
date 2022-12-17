class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

  // Iterate through the expression
  for (auto c : tokens) {
    if (c == "+" || c == "-" || c == "*" || c == "/") {
      // If the character is an operator, we pop the top two elements from the stack,
      // perform the operation, and push the result back onto the stack
      long int right = st.top();
      st.pop();
      long int left = st.top();
      st.pop();
      long int result;
      if (c == "+") {
        result = left + right;
      } else if (c == "-") {
        result = left - right;
      } else if (c == "*") {
        result = left * right;
      } else {
        result = left / right;
      }
      st.push(result);
    } else {
      // If the character is not an operator, it must be an operand.
      // We can convert it to an integer and push it onto the stack.
      st.push(stoi(c));
    }
  }

  // The final result will be the only element left on the stack
  return st.top();
    }
};