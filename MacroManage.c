#define super1(n) "singleton {" #n "}"
#define super2(n, n1) "pair {"#n", "#n1"}"
#define super3(n, n1, n2) "triplet {"#n", "#n1", "#n2"}"

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define stringify(...) GET_MACRO(__VA_ARGS__, super3, super2, super1)(__VA_ARGS__)


/*
#define stringify(...) \
  STRING_N(#__VA_ARGS__, ##__VA_ARGS__, 3, 2, 1, 0)

#define STRING_N(S, _1, _2, _3, N, ...) \
  TUPLE_WORD_##N(" {" S "}")

#define TUPLE_WORD_1(S) \
  ("singleton" S)

#define TUPLE_WORD_2(S) \
  ("pair" S)

#define TUPLE_WORD_3(S) \
  ("triplet" S)
  
  

#define tuple(a,b,c,d,e,...) e
#define stringify(...) tuple(0, ##__VA_ARGS__, "triplet {", "pair {", "singleton {", 0) #__VA_ARGS__ "}"
*/
