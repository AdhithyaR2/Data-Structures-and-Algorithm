#include <stdio.h>

#define SIZE 10

int S[SIZE+1];
int top = 0;

int is_empty() {
if(top == 0)
  return 1;
return 0;
}

void push(int x) {
top = top+1;
if(top > SIZE) {
  printf("Stack Overflow\n");
}
else {
  S[top] = x;
}
}

int pop() {
if(is_empty()) {
  printf("Stack Underflow\n");
  return -1000;
}
else {
  top = top-1;
  return S[top+1];
}
}

int main() {
pop();
push(10);
push(20);
push(30);
push(40);
push(50);
push(60);
push(70);
push(80);
push(90);
push(100);
push(110);

int i;
for(i=1; i<=SIZE; i++) {
  printf("%d\n",S[i]);
}
return 0;
}
