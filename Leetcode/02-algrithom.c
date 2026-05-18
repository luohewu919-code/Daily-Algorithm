//03-反转链表：
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;	//注意：prev指向head之前的那个NULL
	while (cur != NULL) {
		struct ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}
//易错点：
//1.反转链表无法识别题型
//2.内部循环的顺序：
//	先保存下一个节点(一旦反转链表，"箭头"消失)
//  反转链表（注意不能先移动prev，因为移动后，cur再指向prev，就是自己指自己）
//  先移动prev（不能先移动cur，因为先移动cur，会跳）
//  再移动cur

//难点：
//方法选用
//内部循环执行顺序的把握


