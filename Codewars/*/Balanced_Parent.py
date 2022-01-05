def generateParenthesis(n, open, close, s, ans):
    if(open==n and close==n):
        ans.append(s);
        return;
    if(open<n):
        generateParenthesis(n, open+1, close, s+"(", ans);
    if(close<open):
        generateParenthesis(n, open, close+1, s+")", ans);
       
def balanced_parens(n):
    print(n);
    l = [];
    generateParenthesis(n, 0, 0, '', l)
    return l;
