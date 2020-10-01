def isBalanced(s):
    restart=True
    while restart:
        if '{}' in s:
            s=s.replace('{}','')
        elif '()' in s:
            s=s.replace('()','')
        elif '[]' in s:
            s=s.replace('[]','')
        else:
            restart=False
    return 'YES' if len(s)==0 else 'NO'
		
x=isBalanced("[{}")
print(x)
