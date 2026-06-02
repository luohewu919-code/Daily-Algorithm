//15-对称二叉树
bool check(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) return true;
	else if (p == NULL || q == NULL) return false;
	else if (p->val != q->val) return false;
	return check(p->left, q->right) && check(p->right, q->left);
	//与判断是否两个二叉树相同的方法一样的
	//不过，我们要注意的点，镜像对称的本质
	//就是左节点的左孩子与右节点的右孩子相等 && 左节点的右孩子与右节点的左孩子相等
}

bool isSymmetric(struct TreeNode* root) {
	return check(root->left, root->right);
	//其实，对于一个二叉树是否镜像对称，其实本质就是从根节点拆解，拆解成左、右二叉树
	//然后，再去明确是否，满足镜像位置的数值相等
	//拆解本质，就是把复杂问题，简单化
}

