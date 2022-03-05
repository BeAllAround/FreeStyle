const Not = A => (T)=> (T2) => !unchurch(A);
const And = A => B => (T2) => (T1) => unchurch(A) && unchurch(B);
const Or = A => B => () => () => unchurch(A) || unchurch(B);
const Xor = A => B => () => () => Boolean(unchurch(A) ^ unchurch(B));

// Codewars
// const Not = A => /*if*/A/*then*/(False)/*else*/(True)
// const And = A => B => /*if*/A/*then*/(B)/*else*/(False);
// const Or = A => B => /*if*/A/*then*/(True)/*else*/(B);
// const BOOL_EQ = A => B => /*if*/A/*then*/(B)/*else*/(Not(B));
// const Xor = A => B => /*if*/Not(BOOL_EQ(A)(B))
