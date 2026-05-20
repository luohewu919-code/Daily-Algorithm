//08-用栈实现队列
typedef struct {
	int in[100];	
	int Input;
	int out[100];
	int Output;
} MyQueue;	//定义一个队列，表达两个顺序栈


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));	
	obj->Input = 0;	   //与顺序栈类似，初始化的top下标均为0
	obj->Output = 0;
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	obj->in[obj->Input++] = x;	//主要是明确是先加还是后加
}

int myQueuePop(MyQueue* obj) {
	if (obj->Output == 0) {	   //就是第二个顺序栈为空的时候，将第一个顺序栈的元素加到第二个顺序栈里面
		while (obj->Input < 0) {	//当obj->Input = 0时，表示第一个顺序栈的元素已经逆向复制到第二个顺序栈了
			obj->out[obj->Output++] = obj->in[--obj->Input];	
		}
	}
	return obj->out[--obj->Output];	   
	//其实return表示两层含义：
	//1.返回我们删除的元素
	//2.将第二层的顺序栈的栈顶下标下移
}

int myQueuePeek(MyQueue* obj) {
	if (obj->Output == 0) {
		while (obj->Input > 0) {
			obj->out[obj->Output++] = obj->in[--obj->Input];
		}
	}
	return obj->out[obj->Output - 1];	
	//大体与删除元素类似，不过，我们返回的是第二个顺序栈的最后一个数据，且不改变顺序栈
}

bool myQueueEmpty(MyQueue* obj) {
	return obj->Input == 0 && obj->Output == 0;
	//当obj内部的两个顺序栈都为空的时候，才是空
}

void myQueueFree(MyQueue* obj) {
	free(obj);
}
//总结：
//不明确栈(后入先出)与队列(先入先出)的不同和联系
//对于栈和队列的插入：都是从后面插入的，所以没有什么区别
//对于栈与队列的删除：其实就是一个逆向的操作

//大体步骤：
//1.创建一个队列：本质上就是两个顺序栈的组合
//2.插入元素，就是类似顺序表
//3.删除元素：
// 就是在一个顺序栈为空的情况下，把一个顺序栈的元素复制到另一个顺序栈中
// 同时，删除另一个顺序栈的栈顶元素 = 删除前一个顺序栈的栈底元素
//4.判空：就是两个顺序栈都为空，队列就是空



//09-用队列实现栈：
typedef struct {
	int head;
	int rear;
	int data[100];
} MyStack;	//定义队列

MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));	//队列初始化
	obj->head = 0;
	obj->rear = 0;
	return obj;
}

void myStackPush(MyStack* obj, int x) {
	obj->data[obj->rear++] = x;	   //插入元素
	int n = obj->rear - obj->head;	   // 获取最新的顺序队列的长度，为了后续旋转数据
	for (int i = 0; i < n - 1; i++) {
		int front = obj->data[obj->head++];	   //获取栈顶的元素
		obj->data[obj->rear++] = front;	   
		//添加到原本的最后一个节点后面
		//(细节：由于我们在插入元素时，我们将rear向后移动一位，所以将front的数据加到后面，就不要先加，而是后加)
	}
}

int myStackPop(MyStack* obj) {
	return obj->data[obj->head++];	
	//由于受到队列添加元素后，旋转节点的影响，自然，队列的head的数据即为栈顶元素，不过删除后，记得移动下标
}

int myStackTop(MyStack* obj) {
	return obj->data[obj->head];
	//由于队列已经旋转，所以队列的head的数据，即为栈顶元素
}

bool myStackEmpty(MyStack* obj) {
	return obj->head == obj->rear;
	//由于队列可以从两边操作，自然，当队列为空的时候，队列的head与rear重合
}

void myStackFree(MyStack* obj) {
	free(obj);
}
//总结：
//用一个队列实现栈，本质是因为队列是可以对两端操作，但是栈只能一端
//操作步骤：
//1.定义、初始队列
//2.插入元素：（其实是向让队列逆向旋转）
//	难点：如何使队列前面的元素旋转到刚插入的元素中？
//	首先，获取队列最前方的元素
//	然后，放到rear上
//3.删除元素：受到插入元素的影响，直接返回head处的数据
//4.获取栈顶元素：受到插入元素的影响，直接返回head处的数据
//5.判断队列是否空：head与rear是否重合（本质是由于从两端入手）





