//13-二叉树的最大深度：
int maxDepth(struct TreeNode* root) {
	if (root == NULL) return 0;		//当根节点为空的时候，即深度为0
	int m = maxDepth(root->left);	//接收左节点的深度
	int n = maxDepth(root->right);		//接收右节点的深度
	if (m > n) return m + 1;	//其实最大深度 = 左节点的深度（右节点的深度）+ 1
	else return n + 1;
}
//易错点：
//需要判断根节点是否为空，为空需要返回0
//当然，返回0，也表示深度从0开始计算
//还有一个易错点，定义m、n的时候，一定是函数的返回的结果，不是左节点、右节点
//本质，是类型不同

//注意：
//计算的数据和查找的数据是两个不同的概念

//明确：
//求深度，可以拆解成左子树和右子树来计算深度
//然后，左子树和右子树求深度又可以进行拆解


//14-翻转二叉树：
struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL) return NULL;		//当根节点为空时，无需翻转二叉树
	struct TreeNode* left = invertTree(root->left);	
	//代码理解容易，不过我们要看看那个，前面left、right的类型
	//代码：翻转二叉树就是使二叉树的左右子树进行交换，同理，左右子树里面的左右节点进行交换
	struct TreeNode* right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}
//难点在于，接受函数的类型的把握，注意不是int，而是结构体指针
//始终记住，移动的节点是root，而不是新的节点指向root


//15-相同的树：
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) return true;	//如果二叉树均为空，则树是相同的
	else if (p == NULL || q == NULL) return false;	//如果二叉树有一个为空，另一个不为空，则树一定不同
	else if (p->val != q->val) return false;	//检查二叉树对应位置的数据
	//注意：不能检查直接检查节点,比如p->left != q->left，因为节点有地址，必然不同
	else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	//使用“&&”，表示同时进行
}
//思维：
//采用深度优先搜索
//本质，使用对比对应位置的数据，从而判断二叉树是否为空
//当然在开始之前，我们肯定需要先预判一些，就是p与q在NULL的情况，从而判断是否相同




