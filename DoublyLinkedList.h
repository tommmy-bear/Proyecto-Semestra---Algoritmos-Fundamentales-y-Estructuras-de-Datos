#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

struct Node {
    std::string artist_name;
    std::string track_name;
    unsigned long long streams;
    Node* next;
    Node* prev;

    Node(std::string artist, std::string track, unsigned long long str)
        : artist_name(artist), track_name(track), streams(str), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(Node* newNode);
    void sort();
    void printList(); 

private:
    Node* split(Node* head);
    Node* merge(Node* first, Node* second);
    Node* mergeSort(Node* node);
};

//Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

//Destructor
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

//Add a new node to the list
void DoublyLinkedList::append(Node* newNode) {
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

//Sorting the list
void DoublyLinkedList::sort() {
    head = mergeSort(head);
    Node* temp = head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    tail = temp;
}

//Print the list
void DoublyLinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Artist: " << current->artist_name << ", Track: " << current->track_name << ", Streams: " << current->streams << std::endl;
        current = current->next;
    }
}

Node* DoublyLinkedList::split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;
    return mid;
}

Node* DoublyLinkedList::merge(Node* first, Node* second) {
    if (!first) 
        return second;
    if (!second) 
        return first;

    // Cambiar la condición para ordenar de mayor a menor.
    if (first->streams > second->streams) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

Node* DoublyLinkedList::mergeSort(Node* node) {
    if (!node || !node->next) {
        return node;
    }

    Node* second = split(node);
    node = mergeSort(node);
    second = mergeSort(second);

    return merge(node, second);
}

#endif // DOUBLY_LINKED_LIST_H
