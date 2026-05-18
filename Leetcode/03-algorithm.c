//05-删除链表中倒数第n个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));	

	//创建虚拟头节点，因为头节点只有一个元素的时候，我们无法直接删除
	dummy->next = head;
	
	//记录链表的节点数目
	struct ListNode* cur = dummy;
	int count = 0;
	while (cur != NULL) {
		count++;
		cur = cur->next;
	}

	//目标删除节点的前一个节点
	struct ListNode* p = dummy;
	for (int i = 0; i < count - n - 1; i++) {	//注意i表示移动节点的数目，不是下标
		p = p->next;
	}
	struct ListNode* temp = p->next;

	//为了不是程序报错，我们需要判断temp节点是否为空
	if (temp != NULL) {
		p->next = temp->next;
		free(temp);
	}
	
	return dummy->next;
}

//注意点：
//使用dummy虚拟头节点来搞定程序（增删改等）
//明确for循环里面，i代表的是移动的步数，而不是下标
//删除节点的时候，我们使用temp，一定需要先让它不是空节点，然后再运行