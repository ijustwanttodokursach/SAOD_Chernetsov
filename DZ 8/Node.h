#pragma once
#include <map>
#include "Edge.h"

class Node {
public:
	int id;				// for visualization
	std::map<char, Edge> children;
	bool leaf = false;
	Node* suffix_link = nullptr;
	int minIdx = 0, maxIdx = 0, maxLen = 0;

	Node(int id) : id(id) {}

};


