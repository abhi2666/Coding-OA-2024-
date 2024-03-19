/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr){};
 *		Node(int x) : data(x), next(nullptr){};
 *		Node(int x, Node *next) : data(x), next(next){};
 * };
 */

// to insert a node in circular linked list you just have to check for the case where you have to k = 0 hence head will be changed and the link with the head also..

Node* getLastNode(Node* head){
    Node* p = head;
    while(p->next!=head) p = p->next;
    return p;
}

Node* insert(int k, int val, Node *head) {
	Node* temp = head;
	Node* newNode = new Node(val);
	if(k==0){
        Node* last = getLastNode(head);
        last->next = newNode;
        newNode->next = head;
        head = newNode;
		return head;
	}
	// if it is somewhere else
	int counter = 0;
	while(counter < k-1){
		temp = temp->next;
		counter++;
	}
	//you have reached the position
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}