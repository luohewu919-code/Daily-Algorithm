//二叉树中输出度为2的节点
void PreorderPrintNodes(BiTree T) {
	if (T == NULL) return;		//只要节点为空的时候，我们就回溯
	if (T->lchild != NULL && T->rchild != NULL) printf(" %c", T->data);
	//度为2表示左右节点均不为空
	PreorderPrintNodes(T->lchild);
	PreorderPrintNodes(T->rchild);
}


//二叉树中度为1的节点数
int NumSingleChild(const NODE* root) {
	if (root == NULL) return 0;
	int sum = 0;	//求满足条件的数目，一般都是累加的思想
	if ((root->lch != NULL && root->rch == NULL) || (root->lch == NULL || root->rch != NULL)) sum = 1;
	//易错点：度为1，表示两者中一个为空，一个不为空，常容易陷入root->lch != NULL || root->rch != NULL误区
	//本质：未理解逻辑运算符的含义，root->lch != NULL || root->rch != NULL有三种情况
	//因为，要么要么逻辑（就是逻辑或），他们可能同时成立
	sum += NumSingleChild(root->lch);	//一定要累加，防止数据的丢失
	sum += NumSingleChild(root->rch);
	return sum;
}

