//10-环形链表2
struct ListNode* detectCycle(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {	
		//判断头节点与头节点的下一个节点是否为空
		//（两个指针，一般都是要判断该指针和下一个指针是否为空）
		//小的细节，为什么不把fast != slow设置成循环条件？
		//因为：最开始设置的初始fast和slow的指针都是在head节点处
		return NULL;	
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {	//由于fast要移动两个节点，必然要限定下一个节点
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {		//第一次指针移动到同一个位置
			break;
		}
	}
	if (fast == NULL || fast->next == NULL) {	
		//注意前面循环结束有两个条件：
		//1.fast = NULL || fast->next = NULL
		//2.fast = slow
		return NULL;
	}
	fast = head;	
	//数学关系：当fast = slow的时候，我们让fast重新回到起点，再次移动fast和slow
	// 重合的时候，两者均会在开始进入环形的处重合
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
//该题解法：
//首先采用龟兔赛跑的算法，然后，重新将fast移动到头部，与slow保存同样的速度，相遇的时候，即为开始进入环形循环的地点
//明确：
// fast == NULL || fast->next == NULL表示就是一个单链
//总结步骤：
//1.判断头节点是否为空
//2.利用循环判断是否存在环
//	注意循环条件fast != NULL && fast->next != NULL
//3.从两条路线出发：
//	要么循环条件成立，也就是说不存在环
//	要么存在环，且fast和slow在同一个节点处
//		我们就使fast移动到头节点，再次移动fast和slow，当重合的时候，即为所求


//11-删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;	//没有任何元素，则无法删除
	}
	int j = 0;	//初始为0，是为了后续比较，插入元素
	for (int i = 1; i < numsSize; i++) {	
		//由于是有序的数组，所以一重循环即可
		//记得i的初始值为1，因为形成错查，就是后面的元素与前一个元素，看看是否相等
		if (nums[i] != nums[j]) {
			j++;	//j的作用是记录不重复的元素
			//所以我们向后移动j，记录不重复的元素
			//同时，有一个细节，就是j的初始值是0，结合它的作用，我们可以知道第一个元素是永远不会重复的
			nums[j] = nums[i];
		}
	}
	return j + 1;	//由于初始值是int j = 0；且为先加，所以有效的元素个数，自然是j + 1;
}
//解决方法：双指针
//题目要求：
//考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。
//nums的前k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
//题目总结：
//1.从初始条件，判断是否能删除（就是数组里面有无数据）
//2.建立两个变量，一个用于侦察，一个用于记录不重复的元素
//	明确：第一个元素是不会重复的
//	由于本题，已经排好序了，所以使用一维循环即可
//	注意：排好序的数组，我们判断是否重复直接两个变量的初始值设置成0和1
//3.不重复的元素加入到有效、所需的数组后面



//12-移除元素
int removeElement(int* nums, int numsSize, int val) {
	if (numsSize == 0) {	//从元素的个数入手，如果一个元素都没有，无法继续删除
		return 0;	
	}
	int j = 0;	//j的作用是记录不等于val的元素
	for (int i = 0; i < numsSize; i++) {	//i的作用是侦察是否等于val的元素
		if (nums[i] != val) {
			nums[j] = nums[i];	//记录不等于val的元素
			j++;	//进入下一个下标，同时这个也是return的下标的关键
		}
	}
	return j;	//由于我们记录val的元素，然后j的下标再向后移动一个，所以只需return j;
}








