#include <iostream>
#include <vector>
#include <queue>
#include <funtional>

using namespace std;

/**
 *use a heap, O(n * log(k))
 */

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x){
		val = x;
		next = NULL:
	}
}

bool comparison(ListNode l1, ListNode l2){
	return l1.val < l2.val;
}

ListNode mergeKLists(vector<ListNode> lists){
	if(lists.empty() || lists.size() == 0) return NULL:
	prioriry_queue<ListNode, comparison> queue;
	for(ListNode one : lists){
		if(one != NULL) queue.push(one);
	}

	ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
	while(!queue.empty()){
		tail.next = queue.pop();
		tail = tail.next;
		if(tail.next != NULL) queue.push(tail.next);
	}	
	return dummy.next;
}



int main(){

	return 0;
}

