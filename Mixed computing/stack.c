#include "stack.h"
#include<math.h>

//栈的初始化 
LinkStack* InitStack() {
    LinkStack *t = (LinkStack*)malloc(sizeof(LinkStack));
    t->next = NULL;
    return t;
}

//空栈 
int Empty(LinkStack *s) {
    return s->next == NULL;
}

//
void Push(LinkStack *s, dataType x) {
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = s->next;
    s->next = t;
}

//删除最后一个 
void Pop(LinkStack *s) {
    if (Empty(s)) exit(1);
    node *p = s->next;
    s->next = p->next;
    free(p);
}

//取顶层元素 
dataType GetTop(LinkStack *s) {
    return s->next->data;
}

//优先级 
int priority(char x) {
    switch (x) {
        case '+':
        case '-':
        case '=': return 1;
        case '*':
        case '/': return 2;
        case '(': return 3;
    }
}
double compute(double x, double y, char op) {
    switch(op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
    }
}                
