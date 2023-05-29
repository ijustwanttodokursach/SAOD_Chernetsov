#pragma once
#include <iostream>	// �����, �.�. ���� ������ ������������
#include <map>		// ��� �������� ����� ������� � �������� �����
#include "Edge.h"
#include "Node.h"
#include<algorithm>
#include<list>
using namespace std;

/// <summary>
/// For Ukkonen algorithm
/// Represents Active Point (state machine)
/// </summary>
class ActivePoint {
public:
	Node* node;		// ������� �������� ����
	int edge = -1;	// ������� �������� ����� � �������� ����
	int length;		// ����� �� ��������� �����
};

class SufTree {
	const char* input;				// ����� ��� ����������� T
	int last_read = -1;				// ���������� ����������� ������
	Node* lastCreatedNode = nullptr;

	int node_count = 0;					// ������� ��� ������� id-����.
	Node* root = new Node(node_count++);

	int remainder = 0;					// ���������� ��������� ��� �� ����������� ����, �� ��� �������������� � ������.
	ActivePoint ap = { root, -1, 0 };	// {������� ����, �������� ����� � ����, ����� �� ��������� �����}
public:

	SufTree(const char* inp) :input(inp){}
	SufTree(const SufTree&) = delete;			// ��������� �����������, ����� ������������ ��������
	SufTree& operator=(const SufTree&) = delete;// ��������� �������������.

	// ��� ��� �����������
	void deleteEdge(Edge& e) {
		if (e.node)
			deleteNode(e.node);
	}

	void deleteNode(Node* n) {
		for (auto& c : n->children)
		{
			deleteEdge(c.second);
		}
		delete n;
	}
	~SufTree() {
		deleteNode(root);
	}
	// ������ ���������� ������
	void extend(int i);
	void finalize();
	
	// ����� �����, �.�. ����� ������ ���������� ������������� �������. 
	int edgeLen(Edge& e) {
		return e.end >= 0 ? e.end - e.start + 1 : last_read - e.start + 1;
	}
#pragma region ���������� ������
private:
	/// <summary>
	/// ��������� ���� sufIdx �������� ����� �������� �������� �� ������� ������
	/// </summary>
	/// <param name="n">��������� �� ����</param>
	/// <param name="len">����� ����� �� ����� �� ����</param>
	void fillLeaves(Node* n, int len)
	{
		for (auto& p : n->children)
		{
			int _len = len + edgeLen(p.second);
			if (p.second.isLeaf()) {
				p.second.sufIdx = last_read - _len + 1;
			}
			if (p.second.node)
				fillLeaves(p.second.node, _len);
		}
	}

	void fillMin(Node* n) {
		list<int> m_indexes;
		for (auto& p:n->children) {
			if (p.second.isLeaf()) {
				m_indexes.push_back(p.second.sufIdx);
			}
			if(p.second.node){
				fillMin(p.second.node);
				m_indexes.push_back(p.second.node->minIdx);
			}
		}
		auto result = std::min_element(m_indexes.begin(), m_indexes.end());
		n->minIdx = *result;
	}

	void fillMax(Node* n, int forleaf) {
		list<int> m_indexes;
		m_indexes.push_back(forleaf);
		for (auto& p : n->children) {
			if (p.second.isLeaf()) {
				m_indexes.push_back(p.second.sufIdx);
			}
			if(p.second.node){
				p.second.node->leaf?
					fillMax(p.second.node, p.second.sufIdx): fillMax(p.second.node, 0);
				m_indexes.push_back(p.second.node->maxIdx);
			}
		}
		auto result = std::max_element(m_indexes.begin(), m_indexes.end());
		n->maxIdx = *result;
	}
	void fillMaxlen(Node*n, int path) {
		n->maxLen = path;
		for (auto& p : n->children) {
			if (!p.second.isLeaf()) {
				fillMaxlen(p.second.node,path+edgeLen(p.second));
			}
		}
	}
	int findMax(Node* n) {
		list<int> maxlengths;
		for (auto& p : n->children) {
			if (!p.second.isLeaf()) {
				maxlengths.push_back(findMax(p.second.node));
			}
		}
		maxlengths.push_back(n->maxLen);
		auto result = std::max_element(maxlengths.begin(), maxlengths.end());
		return *result;
	}
	void findInMaxNode(Node* n, int maxlen, int &mind) {
		if (maxlen == n->maxLen) {
			mind = n->minIdx;
		}
		for (auto& p : n->children) {
			if (!p.second.isLeaf()) {
				findInMaxNode(p.second.node, maxlen, mind);
			}
		}
	}

public:
	void FillLeaves() {
		fillLeaves(root, 0);
	}
	void FillMin() {
		fillMin(root);
	}
	void FillMax() {
		fillMax(root,0);
	}
	void FillMaxlen() {
		fillMaxlen(root, 0);
	}
	int FindMax() {
		return findMax(root);
	}
	void FindInMaxNode(int maxlen, int &mind) {
		findInMaxNode(root, maxlen, mind);
	}
#pragma endregion
private:
	// ������ ������������
	/// <summary>
	/// ������������� �������� ����� (����� ��������� ��������)
	/// </summary>
	void showActivePoint() {
		if (ap.edge >= 0)
			cout << '(' << ap.node->id << ", " << input[ap.edge] << ", " << ap.length << ')';
		else
			cout << '(' << ap.node->id << ", " << "undef, " << ap.length << ')';
	}
	/// <summary>
	/// ������������� �����
	/// </summary>
	/// <param name="e">������ �� �����</param>
	/// <param name="level">������� ����� � ������</param>
	void showEdge(Edge& e, int level)
	{
		for (int i = 0; i < edgeLen(e); i++)
			cout << input[e.start + i];
		if(e.isLeaf())
			cout << '|' << e.sufIdx;	// ������ ����� ����������� ����� � ����
		cout << endl;
	}
	/// <summary>
	/// ������������ ����
	/// </summary>
	/// <param name="n">��������� �� ����</param>
	/// <param name="level">������� ���� � ������</param>
	void showNode(Node* n, int level) {
		string shift(level, '\t');
		cout << "max: " << n->maxIdx<<" min: "<<n->minIdx<<" len: "<<n->maxLen<<"\n";
		cout << shift << n->id;
		if (n->suffix_link)
			cout << " --> " << n->suffix_link->id;
		cout << endl;
		for (auto e : n->children) {
			cout <<shift << "    ";
			showEdge(e.second, level);
			if (e.second.node != nullptr)
				showNode(e.second.node, level+1);
		}
	}

public: 
	void ShowTree()
	{
		showNode(root, 0);
		cout << "max= "<<FindMax();
	}

};
