#pragma once
#include "Number.h"
class Node
{
public:
	Number* data;
	Node* previous, * next;
	Node(Number* data);
	~Node();
};

Node::~Node()
{
	delete data;
}

Node::Node(Number* data) : data(data), previous(nullptr), next(nullptr)
{
}

