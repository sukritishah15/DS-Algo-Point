def find_balance(expression):
    stack = []
    for symbol in expression:
        if(symbol == '{' or symbol == '[' or symbol == '('): #if symbol is an opening bracket then push to stack
            stack.append(symbol)
        elif(len(stack) != 0):
            if((symbol == '}' and stack[-1]=='{') or (symbol == ']' and stack[-1]=='[') or (symbol == ')' and stack[-1]=='(')): #if stack top and symbol are of same kind then pop
                stack.pop()
            elif(symbol == '}' or symbol == ']' or symbol == ')'): #if symbol is a bracket and doesn't match the stack top then the expression is unbalanced
                return "Unbalanced"
        elif(symbol == '}' or symbol == ']' or symbol == ')'): #if a closing bracket appears before any opening bracket then the expression is unbalanced
            return "Unbalanced"
     
    if(len(stack)==0): #if stack is empty expression is balanced
        return "Balanced"
    else:
        return "Unbalanced"


expression = list(str(input("Enter the Expression : ")))
print(find_balance(expression))