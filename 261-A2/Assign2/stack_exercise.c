#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dynamicArray.h"


int in_stack(DynArr * s,char tofind){
  /* 
     Returns 1 if the element `tofind` is present in DynArr `s`, 0
     otherwise.  Upon returning `s` should have its elements in the
     same order as when the function is called. In other words, you
     may modify `s` but must return it to its original state

     You may only call the following funcitons

        DynArr *createDynArr(int cap);
        int isEmptyDynArr(DynArr *v);
        void pushDynArr(DynArr *v, TYPE val);
        TYPE topDynArr(DynArr *v);
        void popDynArr(DynArr *v);

     Hint: use another stack to hold elements while you search
     and then restore the initial state of `s`
  */
//	printf("in function \n");
	DynArr *storage_array = createDynArr(s->capacity);
	int found = 0;
	
	while (isEmptyDynArr(s) == 0)  { //continue searching until s is empty
		if (topDynArr(s) != tofind) {  //top element of s isn't what we are looking for
			pushDynArr(storage_array, topDynArr(s)); //put top element from s into storage
			popDynArr(s); //remove top element from s
		}
		
		else{ // (topDynArr(s) == tofind) { //element on top is what we are looking for
			found = 1; //for conditional later on to signal tofind exists in array
			break; //quit searching
		}
	}

	while (isEmptyDynArr(storage_array)==0) { //continue until storage array is empty
		pushDynArr(s, topDynArr(storage_array)); //take top element of storage an put it on s
		popDynArr(storage_array); //remove top element from storage
	}

	if (found == 1) { //conditional to see if init did exist in s
		return 1; 
	}
	//it would make more sense to use the deleteDynArr or freeDynArray but they aren't in the list of functions we can use
	free (storage_array->data); //free pointer in struct
	free(storage_array); //free pointer
  return 0;
}






int valid_bracket(char * str){
  /*
    str contains only bracking characters - parenthesis ( '(' and ')'
    ), square brackets ('[' and ']') and squiggly brackets ('{' and
    '}')

    This function returns 1 if str contains a set of balanced
    bracketing characters and zero otherwise.  A string is said to
    have balanced bracketing characters if each opening bracket ( '(',
    '{' and '[') contains a correspodning closing bracket
    (')','}',']') of the same type and brackets are closed in the
    reverse order that they are opened.

    For example 

    valid_bracket("{}[]()") returns 1
    valid_bracket("{][}(]") returns 0, the brackets do not match
    valid_bracket("(([]))") returns 1
    valid_bracket("(([)])") returns 0, 
          because the '(' at index 1 is closed by the ')' at index 3
	  before the '[' at index 2 is closed

    valid_bracket("}") returns 0 because there is no opening bracket for '{'

    valid_bracket("({}[])") returns 1
    valid_bracket("({}([]))") returns 1
    valid_bracket("({}([]){([])})") returns 1
    valid_bracket("({([]))") returns 0

  */
	int i=0;
	DynArr * storage=createDynArr(strlen(str));

	if(str == NULL){
	   return 0;
	}

	while(str[i] != 0){ //continure till there isn't anything else to read
	   if(str[i] == '{'){ //open curly brace push onto stack
	       pushDynArr(storage, '{');
	   }
	   else if(str[i] == '['){ //open square bracket, push onto stack
	       pushDynArr(storage, '[');
	   }
	   else if(str[i] == '('){ //open parenthese push onto stack
	       pushDynArr(storage, '(');
	   }
           
	   else if(str[i] == '}'){ //closing curly brace
		   if (  isEmptyDynArr(storage) == 1 || topDynArr(storage) != '{') { //make sure stack has something in it / if top element is {
		       free(storage->data);
		       free(storage);
			   return 0;
		   }
		   else { //remove top element
			   popDynArr(storage);
		   }
	   }
	   else if (str[i] == ']') {
		   if (isEmptyDynArr(storage) == 1 || topDynArr(storage) != '[') { //make sure stack has something in it / if top element is [ 
		       free(storage->data);
		       free(storage);
			   return 0;
		   }
		   else { // remove top element
			   popDynArr(storage);
		   }
	   }
	   else if (str[i] == ')') {
		   if (isEmptyDynArr(storage) == 1 || topDynArr(storage) != '(') { //make sure stack has something in it / if top element is (
		   free(storage->data);
		   free(storage);
			   return 0;

		   }
		   else {//remove top element
			   popDynArr(storage);
		   }
	   }
	   i++; //counter to keep track of where in str function is currently checking
	}

	if (isEmptyDynArr(storage) == 1) { //storage has nothing left init   
		free(storage->data);   
		free(storage);
		return 1;//valid
		
	}
	free(storage->data);
	free(storage);
	return 0; //not valid
}


