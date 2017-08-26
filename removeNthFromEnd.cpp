#include <iostram>

using namespace std;

/**
 *Definition for singly-linked list.
 *struct ListNode{
 *int val;
 *ListNode next;
 *ListNode(int x) {val = x}
 *}
 */

ListNode removeNthFromEnd(){
	ListNode pre = new ListNode(0);
	pre.next = head;
	ListNode p1 = pre;
	ListNode p2 = pre;
	int i = 0;
	while(i < n){
		p2 = p2->next;
		i++;
	}

	while(p2.next != next){
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	p1 -> next = p1 -> next -> next;
	return pre.next;
}

int main(){
	return 0;
}

