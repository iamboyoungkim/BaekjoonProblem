#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX_SIZE 100000

using namespace std;

typedef struct _stack{
    int arr[MAX_SIZE];
    int top;
} Stack;

void StackInit(Stack *s){
    s->top = -1;
}
int IsEmpty(Stack *s){
    if (s->top == -1) return 1;
    else return 0;
}
int IsFull(Stack *s){
    if (s->top > MAX_SIZE) return 1;
    else return 0;
}
void Push(Stack *s, int data){
    if (IsFull(s)) return;
    s->arr[++s->top] = data;
}
int Pop(Stack *s){
    if (IsEmpty(s)) return -1;
    else return s->arr[(s->top)--];
}
int Size(Stack *s){
    return s->top+1;
}
int Peek(Stack *s){
    if (IsEmpty(s)) return -1;
    else return s->arr[s->top];
}

int main(){
    int n, num;
    Stack st;
    string s;
    cin >> n;
    StackInit(&st);
    
    for (int i = 0; i<n; i++){
        cin >> s;
        if(!s.compare("push")){
            cin >> num;
            Push(&st, num);
        }
        else if(!s.compare("pop")) printf("%d\n", Pop(&st));
        else if(!s.compare("empty")) printf("%d\n", IsEmpty(&st));
        else if(!s.compare("size")) printf("%d\n", Size(&st));
        else if(!s.compare("top")) printf("%d\n", Peek(&st));
    }
    return 0;
}
