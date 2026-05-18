#include<stdio.h>
#include<stdlib.h>

//链栈的节点
typedef struct node {
	int data;
	struct node* next;
}Node;

//链栈的栈顶
typedef struct Stack {
	Node* top;
}Stack;

Stack* initStack(){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}

void push(Stack* s, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = s->top;
	s->top = newNode;
}

Stack* pop(Stack* s, int* delElem) {
	if (s->top == NULL) {
		return NULL;
	}
	Node* temp = s->top;
	*delElem = s->top->data;
	s->top = s->top->next;
	free(temp);
	return s;
}

//查看栈顶的元素
int getElem(Stack* s) {
	if (s->top == NULL) {
		return -1;
	}
	return s->top->data;
}

//递归：
int add(int n) {
	if (n == 0) return 0;
	return n + add(n - 1);
}

//用递归求最大值
int get_Max(int arr[], int length) {
	if (length == 1) {
		return arr[0];	//只有一个元素
	}
	int prevMax = get_Max(arr, length - 1);
	return prevMax > arr[length - 1] ? prevMax : arr[length - 1];
}

int main() {
	int num = 5;
	int sum = add(num);
	printf("%d\n", sum);
	Stack* s = initStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	printf("%d ", getElem(s));
	int delElem;
	pop(s,&delElem);
	printf("%d\n", getElem(s));
	int arr[10] = { 1,2,3,4,5,6,103,8,9,10 };
	int max = get_Max(arr, sizeof(arr) / sizeof(int));
	printf("最大值为%d", max);
}