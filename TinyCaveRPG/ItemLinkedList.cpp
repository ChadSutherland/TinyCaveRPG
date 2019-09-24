// Chad Sutherland
// 5/12/2019
#include "ItemLinkedList.h"
#include <fstream>

ItemLinkedList::~ItemLinkedList() {
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;
	while (nodePtr != nullptr) {
		nextNode = nodePtr->next;
		delete nodePtr->value;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void ItemLinkedList::appendNode(Item* newItem) {
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = newItem;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else {
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void ItemLinkedList::deleteNode(Item* searchItem) {
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	if (!head)
		return;

	if (*head->value == *searchItem) {
		nodePtr = head->next;
		delete head->value;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;
		while (nodePtr != nullptr && *nodePtr->value != *searchItem) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr->value;
			delete nodePtr;
		}
	}
}

Item* ItemLinkedList::findNode(Position pos, string input) {
	ListNode *nodePtr;
	Item* searchResult = nullptr;

	if (head->value->getDescription() == input && head->value->getPosition() == pos){
		searchResult = head->value;
	}
	else {
		nodePtr = head;
		while (nodePtr->next != nullptr && !(nodePtr->value->getDescription() == input && nodePtr->value->getPosition() == pos)) {
			nodePtr = nodePtr->next; 
		}
		if (nodePtr->value->getDescription() == input && nodePtr->value->getPosition() == pos)
			searchResult = nodePtr->value;
			
	}

	return searchResult;
}

string ItemLinkedList::getPositionDescriptions(Position pos) {
	return getDescriptions(pos, head);
}

string ItemLinkedList::getDescriptions(Position pos, ListNode* nodePtr) {
	if (nodePtr->next == nullptr) {
		if (nodePtr->value->getPosition() == pos)
			return "There is a " + nodePtr->value->getDescription() + ".\n";
		else
			return "";
	}
	else {
		if (nodePtr->value->getPosition() == pos)
			return "There is a " + nodePtr->value->getDescription() + ".\n" + getDescriptions(pos, nodePtr->next);
		else
			return "" + getDescriptions(pos, nodePtr->next);
	}
}

void ItemLinkedList::writeList(fstream &saveFileHandler) {
	writeSerializedItem(saveFileHandler, head);
}

void ItemLinkedList::writeSerializedItem(fstream &saveFileHandler, ListNode* nodePtr) {
	nodePtr->value->serialize(saveFileHandler);
	if (nodePtr->next != nullptr) {
		writeSerializedItem(saveFileHandler, nodePtr->next);
	}
}

void ItemLinkedList::deleteList() {
	ListNode* nodePtr = head;
	while (nodePtr->next) {
		head = nodePtr->next;
		delete nodePtr;
		nodePtr = head;
	}
	delete head;
	head = nullptr;
}