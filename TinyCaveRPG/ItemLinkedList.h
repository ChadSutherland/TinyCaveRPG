#pragma once
// Chad Sutherland
// 5/12/2019
#ifndef ITEMLINKEDLIST_H
#define ITEMLINKEDLIST_H
#include "Item.h"
class ItemLinkedList {
private:
	class ListNode {
	private:
		Item* value;
		ListNode *next;
		friend class ItemLinkedList;
	};
	ListNode *head;
public:
	ItemLinkedList() {head = nullptr;}
	~ItemLinkedList();
	void appendNode(Item* newItem);
	void deleteNode(Item* searchItem);
	Item* findNode(Position pos, string input);
	string getPositionDescriptions(Position pos);
	string getDescriptions(Position pos, ListNode* nodePtr);
	void writeList(fstream &saveFileHandler);
	void writeSerializedItem(fstream &saveFileHandler, ListNode* nodePtr);
	void deleteList();
};
#endif