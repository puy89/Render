#pragma once

class Node {
	int data;
public:
	Node *next;
};

class LinkedList
{
	Node *head;
public:
	void reverse() {
		if (head == nullptr)
			return;
		Node *next_next=head->next, *prev=head;
		while (next_next != nullptr) {
			next_next = prev->next;
			next_next->next = prev;
			prev = next_next;
		}
		head->next = nullptr;
		head = prev;

	}
};

