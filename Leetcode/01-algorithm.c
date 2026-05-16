//01-两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i <= numsSize - 1; i++) {
        for (int j = i + 1; j <= numsSize - 1; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
//易错点：
//数组越界，注意数组长度为numsSize，而下面应该是numsSize - 1
//难点：返回2个及2个以上的数据，记得用数组指针申请空间后，然后返回该指针


//02-合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1 != NULL) {
        tail->next = list1;
    }
    if (list2 != NULL) {
        tail->next = list2;
    }
    return dummy->next;
}
//易错点：
//忘记移动tail,list1或list2的节点位置
//返回东西搞错：dummy表示虚拟头节点，适合函数参数未传入，因此返回的是虚拟头节点的真头节点
