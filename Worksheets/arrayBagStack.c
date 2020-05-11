#include "arrayBagStack.h"
#include <stdio.h>

void initBag (struct arrayBagStack *b){//list members in bag
   int i;
   if(b.count==0){
      printf("nothing in bag")
   }
   else{
      for(i=0; i<b.count; i++){
         printf("%d \n", b.data[i]);
      }
   }
}

void addBag (struct arrayBagStack *b, TYPE v){//add an element to the bag
   b.count++;
   b.data[count-1]=v;
}
int containsBag (struct arrayBagStack *b, TYPE v){
   int i;
   for(i=0; i<b.count; i++){
      
   }
}
