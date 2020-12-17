#pragma once
#include "Node.h"
#include <iostream>
#include "Fractional.h"
#include "Complex.h"
class DoublyCircularLinkedList
{
public:
	~DoublyCircularLinkedList();
	DoublyCircularLinkedList();
	void Insert(Node*);
	void Display();
	int GetCount();
	bool Delete(Node*);
	Node* FindNode(Node*);
	Node* GetStart();
	void InsertionSort();
	void SortedInsert(Node*);
private:
	Node* Start;
	int Count = 0;
};

DoublyCircularLinkedList::DoublyCircularLinkedList() : Start(nullptr) {}

void DoublyCircularLinkedList::Insert(Node* val)
{
	auto node = val;
	if (Start == nullptr) {
		Start = node;
		node->next = node->previous = node;
	}
	else {
		Start->previous->next = node;
		node->previous = Start->previous;
		node->next = Start;
		Start->previous = node;
	}
	Count++;
}

void DoublyCircularLinkedList::Display()
{
	if (Start == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	int i = 1;
	Node* current = Start;
	do
	{
		std::cout << i++ << ": " << *current->data << std::endl;
		current = current->next;
	} while (current != Start);
	std::cout << "List totally has " << Count << " elements" << std::endl;
}

bool DoublyCircularLinkedList::Delete(Node* node)
{
	if (Start == nullptr)
		return false;

	Node* current = Start;
	do
	{
		if (current == node) {
			current->previous->next = current->next;
			current->next->previous = current->previous;
			if (Start == node) {
				if (Count == 1) {
					delete current;
					current = Start = nullptr;
				}
				else {
					Start = current->next;
					delete current;
					current = nullptr;
				}
			}
			else {
				delete current;
				current = nullptr;
			}
			Count--;
			return true;

		}
		current = current->next;
	} while (current != Start);

	return false;
}

Node* DoublyCircularLinkedList::FindNode(Node* nodeLike)
{
	if (Start == nullptr || nodeLike == nullptr)
		return nullptr;

	return nullptr;
}


DoublyCircularLinkedList::~DoublyCircularLinkedList()
{
	if (Start != nullptr) {
		auto current = Start;
		while (current->next != Start) {
			current = current->next;
			delete current->previous;
		}
		current;
		Start = nullptr;
	}

}

int DoublyCircularLinkedList::GetCount() { return Count; }

Node* DoublyCircularLinkedList::GetStart() { return Start; }

void DoublyCircularLinkedList::InsertionSort()
{

	if (Start == nullptr)
		return;
	auto sorted = new DoublyCircularLinkedList();

	Node* current = Start;
	do {
		Node* next = current->next;

		current->previous = current->next = nullptr;

		sorted->SortedInsert(current);

		// Update current 
		current = next;
	} while (current != Start);

	// Update Start to point to sorted doubly linked list 
	Start = sorted->Start;
}

void DoublyCircularLinkedList::SortedInsert(Node* newNode)
{
	Node* current = nullptr;;

	if (Start == nullptr) {
		Start = newNode;
		Start->next = Start->previous = newNode;
	}

	else if (Start->data->realValue >= newNode->data->realValue) {
		newNode->next = Start;
		newNode->previous = Start->previous;
		Start->previous->next = newNode;
		Start->previous = newNode;
		Start = newNode;
	}

	else {
		current = Start;

		while (current->next != Start &&
			current->next->data->realValue < newNode->data->realValue)
			current = current->next;


		newNode->previous = current;
		newNode->next = current->next;
		current->next->previous = newNode;
		current->next = newNode;

	}
	Count++;
}
