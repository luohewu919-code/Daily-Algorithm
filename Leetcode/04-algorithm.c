//06-有效的括号
char pairs(char s) {
	if (s == '}') return '{';
	if (s == ')') return '(';
	if (s == ']') return '[';
	return 0;
}
bool isValid(char* s) {
	int n = strlen(s);
	if (n % 2 == 1) {
		return false;	//因为有效的括号需要成对，所以奇数个的括号肯定不符条件
	}
	int stack[n], top;	//创建顺序栈来存储左括号
	//本质是从左往右数：一定是从左括号开始
	for (int i = 0; i < n; i++) {	//利用循环进行遍历括号，分为两种括号，左括号与右括号
		if (pairs(s[i]) != 0) {		//遍历到右括号
			if (top == 0 || stack[top - 1] != pairs(s)) {	//判断栈是否为空或者栈顶的左括号是否符合我们所需的括号
				return false;
			}
			top--;	//满足匹配，我们就拿出去，继续遍历下一个括号
		}
		else {
			stack[top++] = s[i];	//遍历到左括号，我们就存储，同时存储top会上一层
		}
	}
	return top == 0;	//如果说栈里面有剩余，也就是左括号有剩余，就说明多余的右括号与之匹配
}
//解决方法：利用顺序栈存储左括号，来判断是否与右括号匹配
//难点：
//1.不明确从左往右，第一个一定是左括号，所以栈应该存储左括号
//2.未建立顺序：
//  有效括号必定成对，所以为计数个的括号，直接判断无效
//  栈存储左括号
//  循环遍历：分为左、右两种括号
//  当为右括号：明确是否有左括号，或者说是否有匹配的左括号
//  当为左括号：存储左括号到栈的内部
//  由于左括号存储到栈的内部，我们一定要判断左括号是否剩余

//易错点：最后不判断top是否为0，还有匹配成功，不踢出去，也就是top--；
// 判断我们想要的左括号和已知的左括号的是否匹配的时候，不去将top下降一位
//本质是不明确，顺序栈的栈顶元素与top的关系



//07-相交链表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;	//只要A链表或者B链表为空，那么一定不会相交的
	}
	struct ListNode* pA = headA;	
	struct ListNode* pB = headB;
	while (pA != pB) {
		pA = pA == NULL ? headB : pA->next;	
		//翻译：pA == NULL ? 如果等于空，就移动pA到headB上面，否则继续移动
		//其实是一个数学问题：如果A与B链表相交，且前面的非相交的节点数目相同，不用更换节点到另一个链表的位置
		//当然，不必担心没有相交，是不是return pA没有意义，因为当pA和pB都是NULL，那个NULL = NULL也是一种意义，就是说return NULL
		pB = pB == NULL ? headA : pB->next;
	}
	return pA;
}
//难点：
//不判断当A链表或者B链表为空的情况，无法相交
//不理解相交如何表示,简单说：
//要么在有数据的节点开始相交，要么在NULL处相交
//明确核心：当两条链表遍历到NULL的时候，然后我们再交换节点到另一条链表的头节点，必然会相交


//08-回文链表
bool isPalindrome(struct ListNode* head) {
	int count = 0;
	struct ListNode* cur = head;
	while (cur != NULL) {
		count++;	//计算节点的个数，方便后续数组的定义
		cur = cur->next;
	}
	int arr[count];
	int n = 0;	//数组下标的起始值
	while (head != NULL) {
		arr[n++] = head->val;	//把链表的数组复制到数组当中，同时，我们将arr[n] = head->val；n++;合并到一步
		head = head->next;
	}
	for (int i = 0, j = n - 1; i < j; i++, j--) {	
	//注意：循环内部不用重复使用int,还有分为3个部分，明确什么时候用","，什么时候用";"
		if (arr[i] != arr[j]) {
			return false;
		}
	}
	return true;
}
//步骤梳理：
//1.将链表的数据复制到数组当中：
//	明确链表的长度，从而定义数组
//2.从数组的两端向中间判断是否相等
//	注意：明确for循环不用重复说明数据类型、符号的使用


