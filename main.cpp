#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node* head, int data)
{
    Node* oldNext = head->next;
    head->next = new Node;
    (*(*head).next).data = data;
    (*(*head).next).next = oldNext;
}

void append(Node* head, int data)
{
    // find end of list
    Node* currentNode = head;
    while(currentNode->next!=NULL)
    {
        currentNode=currentNode->next;
    }
    currentNode->next = new Node;
    (currentNode->next)->data = data;
    (currentNode->next)->next = NULL;
}

// wouldn't we need to reference multiple nodes
// to remove a node in the middle of the list?
Node* remove(Node* head)
{
    Node* newHead = head->next;
    delete head;
    return newHead;
}

void remove_all(Node* head)
{
    Node* currentNode = head;
    while(currentNode!=NULL)
    {
        Node* delNode = currentNode;
        delete delNode;
        currentNode = currentNode->next;
    }
}

Node* find(Node*head,int data)
{
    Node* currentNode = head;
    while(currentNode!=NULL)
    {
        if (currentNode->data == data)
        {
            break;
        }
        else
        {
            currentNode=currentNode->next;
        }
    }
    return currentNode;
}

// I think you need at least 3 nodes to reverse a linked list
Node* reverse(Node* head)
{
    Node* currentNode = head;
    Node* nextNode = head->next;
    head->next = NULL;
    Node* temp;
    while(nextNode!=NULL)
    {
        temp = nextNode->next;
        nextNode->next = currentNode;
        currentNode = nextNode;
        nextNode = temp;
    }
    return currentNode;
}


void printList(Node* head)
{
    Node* currentNode = head;
    while(currentNode!=NULL)
    {
        cout << currentNode->data << endl;
        currentNode=currentNode->next;
    }
    cout << endl;
}

int main()
{
    Node head;
    head.data = 5;
    head.next = NULL;

    // INSERT
    insert(&head,10);
    insert((head.next),20);
    printList(&head); // 5 10 20

    // APPEND
    append(&head,30);
    printList(&head); // 5 10 20 30

    // REMOVE
    Node* newHead = remove(&head);
    printList(newHead); // 10 20 30

    // REMOVE ALL
    remove_all(newHead);

    // FIND
    Node headA;
    headA.data = 5;
    headA.next = NULL;
    insert(&headA,10);
    insert((headA.next),20);
    Node* foundNode = find(&headA,20);
    printList(foundNode); // 20

    // REVERSE
    insert((headA.next),15);
    Node* reverseHead;
    printList(&headA); // 5 10 15 20
    reverseHead = reverse(&headA);
    printList(reverseHead); // 20 15 10 5

}
