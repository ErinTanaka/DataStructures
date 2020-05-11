
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include "stack_exercise.h"

void assertTrue(int predicate, char *message) 
{
  printf("%s: ", message);
  if (predicate)
    printf("PASSED\n");
  else
    printf("FAILED\n");
}

void check_modified(DynArr * d,int n){
  int fail = 0;
  if(d->size!=n) {
    fail = 1;
    assertTrue(0,"Stack wrong size");
  }
  else{
    for(int i=0;i<n;i++){
      fail |= getDynArr(d,i)!=(i+'a');
    }
  }
  assertTrue(!fail,"Stack was modified!");
}

int main(int argc, char* argv[]){
/*
  char* t1 = "{}[]()";
  assertTrue(valid_bracket(t1)==1,t1);
  char* t2 = "{][}(]";
  assertTrue(valid_bracket(t2)==0,t2);
  char* t3 = "({[])";
  assertTrue(valid_bracket(t3)==0,t3);
  char* t4 = "(([]{}))";
  assertTrue(valid_bracket(t4)==1,t4);
  char* t5 = ")";
  assertTrue(valid_bracket(t5)==0,t5);
  char* t6 = "{(([){}])"; 
  assertTrue(valid_bracket(t6) == 0, t6);
  char* t7 = "({}[])";
  assertTrue(valid_bracket(t7) == 1, t7);
  char* t8 = "({}([]))";
  assertTrue(valid_bracket(t8) == 1, t8);
  char* t9 = "({}([(]){([])})";
  assertTrue(valid_bracket(t9) == 0, t9);
  char* t10 = "({([])})";
  assertTrue(valid_bracket(t10) == 1, t10);
  char* t11 = "({}[]((){}))";
  assertTrue(valid_bracket(t11) == 1, t11);
*/
  DynArr * d = createDynArr(10);
  for(int i=0;i<10;i++){
    addDynArr(d,i+'a');
  }
  
  for(int i=0;i<10;i++){
    char * tmp;
    char * tmp2;
    asprintf(&tmp,"Checking %c",i+'a');
    asprintf(&tmp2,"Checking %c",i+'o');

    assertTrue(in_stack(d,i+'a'),tmp);  
    check_modified(d,10);
    assertTrue(!in_stack(d,i+'o'),tmp2);  
    check_modified(d,10);

    free(tmp);
    free(tmp2);
    deleteDynArr(d);
	
  }
}
