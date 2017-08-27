#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x){
		val = x;
		next = NULL:
	}
} 

/**
 *Recursive
 *the order of l1, l2 doesn't matter
 */
ListNode* mergeTwoListsRec(ListNode* l1, ListNode* l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	if(l1.val < l2.val){
		l1.next = mergeTwoListsRec(l1.next, l2); //notice l1.next
		return l1;
	}else{
		l2.next = mergeTwoListsRec(l1, l2.next);
		return l2;
	}
} 


/**
 *iterasive
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	//merge
	ListNode* dummyhead;
	ListNode* head;
	dummyhead.next = head;
	while(l1 != NULL && l2 != NULL){
		if(l1.val < l2.val){
			head.next = l1;
			l1 = l1.next;
		}else{
			head.next = l2;
			l2 = l2.next;
		}
		head = head.next;
	}

	//merge
	while(l1 != NULL){
		head.next = l1;
		head = head.next;
		l1 = l1.next;
	}

	while(l2 != NULL){
		head.next = l2;
		head = head.next;
		l2 = l2.next;
	}
	return dummyhead.next.next;
}



int main(){
	
}
