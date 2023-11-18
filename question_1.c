#include <stdio.h>
#include <stdlib.h>

typedef enum _TypeTag {
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIVIDE = 4,
    CONSTANT = 5,
    FIB = 6,
} TypeTag;

typedef struct _Node Node;
struct _Node {
    TypeTag type;
    int value;
    Node* num1;
    Node* num2;
};

/**
 * Recurssive Function which returns Fibonnaci Sequence
 * @param n Number which denotes to calculate the seqence untill nth number.
 * @return Result of the sequence.
 */
int fibonacciSequence(int n)
{
    if (n <= 1)
        return 0;
    else if (n == 2)
        return 1;
    return fibonacciSequence(n - 1) + fibonacciSequence(n - 2);
}

/**
 * Function which creates a Constant Node
 * @param num Value of Constant Node that is to be stored.
 * @return Constant Node
 */
Node* crtConstNode(int num) {
    Node* node = malloc(sizeof(Node));
    node->type = CONSTANT;
    node->value = num;
    node->num1 = NULL;
    node->num2 = NULL;
    return node;
}

/**
 * Function for addition Based Node. Also check for any Null nodes. If Null is present, It will be considered as Fibonnaci Sequence.
 * @param num1 Node pointer for num1
 * @param num2 Node pointer for num2
 * @return Returns Node Pointer.
 */
Node* crtAddNode(Node* num1, Node* num2) {
    Node* res = malloc(sizeof(Node));
    res->type = ADD;
    res->num1 = num1;
    res->num2 = num2;
    if(num1 != NULL && num2 != NULL){
        res->value = num2->value + num1->value;
    }else if(num2 != NULL){
        res->type = FIB;
        res->value = num2->value%2==0?fibonacciSequence(abs(num2->value)):-(fibonacciSequence(abs(num2->value)));
    }else if(num1 != NULL){
        res->type = FIB;
        res->value = num1->value%2==0?fibonacciSequence(abs(num1->value)):-(fibonacciSequence(abs(num1->value)));
    }else {
        res->value = 0;
    }
    return res;
}

/**
 * Function for Subtraction Based Node. Also check for any Null nodes. If Null is present, It will be considered as Fibonnaci Sequence.
 * @param num1 Node pointer for num1
 * @param num2 Node pointer for num2
 * @return Returns Node Pointer.
 */
Node* crtSubNode(Node* num1, Node* num2) {
    Node* res = malloc(sizeof(Node));
    res->type = SUB;
    res->num1 = num1;
    res->num2 = num2;
    if(num1 != NULL && num2 != NULL){
        res->value = num2->value - num1->value;
    }else if(num2 != NULL){
        res->type = FIB;
        res->value = num2->value%2==0?fibonacciSequence(abs(num2->value)):-(fibonacciSequence(abs(num2->value)));
    }else if(num1 != NULL){
        res->type = FIB;
        res->value = num1->value%2==0?fibonacciSequence(abs(num1->value)):-(fibonacciSequence(abs(num1->value)));
    }else {
        res->value = 0;
    }
    return res;
}

/**
 * Function for Multiplication Based Node. Also check for any Null nodes. If Null is present, It will be considered as Fibonnaci Sequence.
 * @param num1 Node pointer for num1
 * @param num2 Node pointer for num2
 * @return Returns Node Pointer.
 */
Node* crtMulNode(Node* num1, Node* num2) {
    Node* res = malloc(sizeof(Node));
    res->type = MUL;
    res->num1 = num1;
    res->num2 = num2;
    if(num1 != NULL && num2 != NULL){
        res->value = num2->value * num1->value;
    }else if(num2 != NULL){
        res->type = FIB;
        res->value = num2->value%2==0?fibonacciSequence(abs(num2->value)):-(fibonacciSequence(abs(num2->value)));
    }else if(num1 != NULL){
        res->type = FIB;
        res->value = num1->value%2==0?fibonacciSequence(abs(num1->value)):-(fibonacciSequence(abs(num1->value)));
    }else {
        res->value = 0;
    }
    return res;
}

/**
 * Function for Division Based Node. Also check for any Null nodes. If Null is present, It will be considered as Fibonnaci Sequence.
 * @param num1 Node pointer for num1
 * @param num2 Node pointer for num2
 * @return Returns Node Pointer.
 */
Node* createDivideNode(Node* num1, Node* num2) {
    Node* res = malloc(sizeof(Node));
    res->type = MUL;
    res->num1 = num1;
    res->num2 = num2;
    if(num1 != NULL && num2 != NULL){
        res->value = num2->value / num1->value;
    }else if(num2 != NULL){
        res->type = FIB;
        res->value = num2->value%2==0?fibonacciSequence(abs(num2->value)):-(fibonacciSequence(abs(num2->value)));
    }else if(num1 != NULL){
        res->type = FIB;
        res->value = num1->value%2==0?fibonacciSequence(abs(num1->value)):-(fibonacciSequence(abs(num1->value)));
    }else {
        res->value = 0;
    }
    return res;
}
//pointer to a fucntion
typedef Node* (*Function)(Node*, Node*);

/**
 * A Dynamic function which returns another Function based on the Input.
 * @param typeTag Enum based input upon which function is to be returned.
 * @return Returns a Function.
 */
Function MakeFunction(TypeTag typeTag){
    switch(typeTag){
        case ADD:{
                return crtAddNode;
        }
        case SUB:{
            return crtSubNode;
        }
        case MUL:{
            return crtMulNode;
        }
        case DIVIDE: {
            return createDivideNode;
        }
        default:{
            printf("Invalid selection.\n");
            return NULL;
        }
    }
}

/**
 * Function which prints the result of the Node.
 * @param node Node pointer which contains a type, and value
 * @return void
 */
void calc(Node* node) {
    switch(node->type){
        case ADD:{
            printf("add: %d\n",node->value);
            break;
        }
        case MUL:{
            printf("mul: %d\n",node->value);
            break;
        }
        case DIVIDE: {
            printf("mul: %d\n",node->value);
            break;
        }
        case SUB: {
                printf("sub: %d\n",node->value);
                break;
        }
        case FIB:{
            printf("fibo: %d\n",node->value);
        }
    }
}

int main() {

    Node *add = (*MakeFunction(ADD))(crtConstNode(10),crtConstNode(6));
    Node *mul = (*MakeFunction(MUL))(crtConstNode(5),crtConstNode(4));
    Node *sub = (*MakeFunction(SUB))(mul, add);
    Node *fibo = (*MakeFunction(SUB))(sub, NULL);

    calc(add); 
    calc(mul);
    calc(sub);
    calc(fibo);

    free(fibo);
    free(sub);
    free(mul);
    free(add);

    return 0;
}