#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}
//初始：类似链表的初始化
//LinkNode* initList(){
//	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
//	head->next = NULL;
//	return head;}

void push(Stack* s, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = s->top;
	s->top = newNode;
}
//插入元素：创建节点，放到栈顶上面，然后更新top

int push(Stack* s) {
	if (s->top == NULL) {
		printf("栈空\n");
		return -1;
	}
	Node* temp = s->top;
	int value = temp->data;
	s->top = s->top->next;
	free(temp);
	return value;
}
//删除元素：其实就是栈顶往下移动，同时释放原本的栈顶

int peek(Stack* s) {
	if (s->top == NULL) {
		return -1;
	}
	return s->top->data;
}
//易错点：就是链栈与顺序栈的top指针指向的内容
//顺序栈：top指向栈顶元素的上一个位置
//链栈：top指向链栈节点本身

int main() {
	Stack* s = initStack();

	push(s, 10);
	push(s, 20);
	push(s, 30);

	printf("出栈: %d\n", pop(s));  // 30
	printf("出栈: %d\n", pop(s));  // 20
	printf("出栈: %d\n", pop(s));  // 10

	return 0;
}