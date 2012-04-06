#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

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

void insert(Node* head, int data)
{
    if (head!=NULL)
    {
        Node* oldNext = head->next;
        head->next = new Node;
        (*(*head).next).data = data;
        (*(*head).next).next = oldNext;
    }

}

void append(Node* head, int data)
{
    if (head!=NULL)
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

}

// removes the first node where data matches the input parameter
Node* remove(Node* head,int data)
{
    if (head==NULL)
    {
        return head;
    }
    else
    {
        if (head->data==data)
        {
            Node* newHead = head->next;
            delete head;
            return newHead;
        }
        else
        {
            Node* currentNode = head->next;
            Node* prevNode = head;
            while(currentNode!=NULL)
            {
                if (currentNode->data == data)
                {
                    prevNode->next=currentNode->next;
                    delete currentNode;
                    break;
                }
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            return head;
        }
    }

}

// removes all nodes with data matching int data
Node* remove_all(Node* head,int data)
{
    if (head==NULL)
    {
        return head;
    }
    else
    {
        Node*newHead = head;
        Node* currentNode = head;
        Node* prevNode = NULL;
        Node* tempNode = NULL;
        while(currentNode!=NULL)
        {
            if (currentNode->data == data)
            {
                if (prevNode==NULL)
                {
                    newHead = head->next;
                }
                else
                {
                    prevNode->next=currentNode->next;
                }

                tempNode = currentNode;
                currentNode = currentNode->next;
               // printList(newHead);
                delete tempNode;
                // printList(newHead);
            }
            else
            {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return newHead;
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
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    else
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
}




int main()
{
    Node head;
    head.data = 5;
    head.next = NULL;

    // INSERT
    cout << "INSERT" << endl;
    insert(&head,10);
    insert((head.next),20);
    printList(&head); // 5 10 20

    // APPEND
    cout << "APPEND" << endl;
    append(&head,30);
    append(&head,20);
    append(&head,20);
    printList(&head); // 5 10 20 30 20 20

    // REMOVE
    cout << "REMOVE" << endl;
    Node* newHead = remove(&head,20);
    printList(newHead); // 5 10 30 20 20

    // REMOVE ALL
    cout << "REMOVE ALL" << endl;
    newHead = remove_all(newHead,20);
    printList(newHead); // 5 10 30

    // FIND
    cout << "FIND" <<endl;
    Node headA;
    headA.data = 5;
    headA.next = NULL;
    insert(&headA,10);
    insert((headA.next),20);
    Node* foundNode = find(&headA,20);
    printList(foundNode); // 20

    // REVERSE
    cout << "REVERSE" << endl;
    Node* reverseHead;
    printList(&headA); // 5 10 20
    reverseHead = reverse(&headA);
    printList(reverseHead); // 20 10 5

    cout << "REVERSE 2 NODES" << endl;
    reverseHead = remove(reverseHead,10);
    printList(reverseHead);
    reverseHead = reverse(reverseHead);
    printList(reverseHead);


}
