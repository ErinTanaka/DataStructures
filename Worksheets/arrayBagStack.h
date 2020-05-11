#ifndef ArrayBagStack
#define ArrayBagStack
#define MAX_SIZE 100

#define TYPE int
#define EQ(a,b) (a==b)

struct arrayBagStack{
   TYPE data[MAX_SIZE];
   int count;
}

//interface for bag
void initBag (struct arrayBagStack *b);
void addBag (struct arrayBagStack *b, TYPE v);
int containsBag (struct arrayBagStack *b, TYPE v);
void removeBag (struct arrayBagStack *b, TYPE v);
int sizeBag (struct arrayBagStack *b);

//interface for stack
void pushStack (struct arrayBagStack *b, TYPE v);
TYPE topScack (struct arrayBagStack *b);
void popStack (struct arrayBagStack *b);
#endif
