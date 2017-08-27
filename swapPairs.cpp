#include <iostream>


using namespace std;

class ListNode{
	int val;
	ListNode next;
	ListNode(int x){
		val = x;
		next = NULL:
	}
}

ListNode swap(ListNode next1, ListNode next2){
	next1.next = next2.next;
	next2.next = next1;
	return next2;
}

ListNode swapPairs(ListNode head){
	ListNode dummy = new ListNode(0);
	dummy.next = head;
	ListNode cur = dummy;

	while(cur != NULL && cur.next != NULL && cur.next.next != NULL){
		cur.next = swap(cur.next, cur.next.next);
		cur = cur.next.next;
	}
	return dummy.next;
}


int main(){
	return 0;
}
