//二叉树的层序遍历：
void Levelorder(BiTree T) {
	if (T == NULL) return;
	BiTree queue[100];		//创建一个队列，搞定层序遍历
	int front = 0, rear = 0;
	queue[rear++] = T;		
	while (front < rear) {
		BiTree node = queue[front++];
		printf("%c ", node->data);
		if (node->lchild != NULL) queue[rear++] = node->lchild;
		if (node->rchild != NULL) queue[rear++] = node->rchild;
	}
}
