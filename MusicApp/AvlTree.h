#pragma once
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

/*
* AVL Tree���� ���̴� NodeAVL ����ü
*/
template <class T>
struct nodeAVL
{
	T data;
	nodeAVL* left;
	nodeAVL* right;
};

//AVL Tree Ŭ����
template <class T>
class AvlTree
{
private:
	nodeAVL<T>* root;
	nodeAVL<T>* cur;

public:
	/*
* ����Ʈ ������
*/
	AvlTree();

	/**
	*	�Ҹ���.
	*/
	~AvlTree();

	/**
	*	Ʈ���� height�� ������ִ� �Լ�
	*/
	int height(nodeAVL<T>* node);

	/**
	*	
	*	��尣�� ���̸� ����ؼ� �����̼��� �ʿ����� Ȯ���� �� ���
	*/
	int diff(nodeAVL<T>* node);

	//ȸ�� �Լ���
	nodeAVL<T>* RR(nodeAVL<T>* parent);
	nodeAVL<T>* LL(nodeAVL<T>* parent);
	nodeAVL<T>* LR(nodeAVL<T>* parent);
	nodeAVL<T>* RL(nodeAVL<T>* parent);

	//ȸ�� �Լ��� �̿��� ������ ���ߴ� �Լ�
	nodeAVL<T>* Balance(nodeAVL<T>* temp);

	//avl tree�� ��带 ����
	nodeAVL<T>* Insert(nodeAVL<T>*& root, T value);
	/**
*	@brief	Tree�� Empty���� Ȯ��
*	@pre	none
*	@post	none
*	@return	Tree�� ��������� true����, �ƴϸ� false ����
*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull() const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	T�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(T& item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	T�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	int DeleteItem(T item);

	/**
	*	@brief	Tree�� �� node�� �����Ѵ�
	*	@pre	T�� ��ü�� ����
	*	@post	Tree�� �� node�� ���ŵ�
	*/
	int Replace(T item);
	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	int RetrieveItem(T& item, bool &found)const;

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out)const;

	//������ �ۼ�
	void WriteUser(ofstream& fout);

	//��� ����
	void DeleteNode(nodeAVL<T> *&node);
	int Delete(nodeAVL<T> *&root, T item);
};

template<class T>
AvlTree<T>::AvlTree()
{
	root = NULL;
	cur = NULL;
}

template<class T>
AvlTree<T>::~AvlTree()
{
}

template<class T>
int AvlTree<T>::height(nodeAVL<T>* node)
{
	int h = 0;
	if (node != NULL)
	{
		int left = height(node->left);
		int right = height(node->right);
		int MaxH = max(left, right);
		h = MaxH + 1;
	}
	return h;
}

template<class T>
int AvlTree<T>::diff(nodeAVL<T>* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left = height(node->left);
		int right = height(node->right);
		int f = left - right;
		return f;
	}
}

template<class T>
nodeAVL<T> * AvlTree<T>::RR(nodeAVL<T>* parent)
{
	nodeAVL<T>* temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

template<class T>
nodeAVL<T>* AvlTree<T>::LL(nodeAVL<T>* parent)
{
	nodeAVL<T>* temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

template<class T>
nodeAVL<T>* AvlTree<T>::LR(nodeAVL<T>* parent)
{
	//���� �ڽ��� �������� RR, ������ �������� LL
	nodeAVL<T>* temp;
	temp = parent->left;
	parent->left = RR(temp);
	return LL(parent);
}

template<class T>
nodeAVL<T>* AvlTree<T>::RL(nodeAVL<T>* parent)
{
	nodeAVL<T>* temp;
	temp = parent->right;
	parent->right = LL(temp);
	return RR(parent);
}

template<class T>
nodeAVL<T>* AvlTree<T>::Balance(nodeAVL<T>* temp)
{
	int factor = diff(temp);
	// ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ����Դϴ�.
	if (factor > 1)
	{
		// �� ���� �ڽĳ�忡 ������ �߻��߽��ϴ�.
		if (diff(temp->left) > 0)
		{
			temp = LL(temp);
		}
		// �� ������ �ڽ� ��忡 ������ �߻��߽��ϴ�.
		else
		{
			temp = LR(temp);
		}
	}
	else if (factor < -1)
	{
		if (diff(temp->right) > 0)
		{
			temp = RL(temp);
		}
		else
		{
			temp = RR(temp);
		}
	}
	return temp;
}

template<class T>
nodeAVL<T>* AvlTree<T>::Insert(nodeAVL<T>*& root, T value)
{
	// ���� Ʈ���� ����� ��
	if (root == NULL)
	{
		root = new nodeAVL<T>;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = Insert(root->left, value);
		root = Balance(root);
	}
	// ũ�ų� ���� ��� ������ ����Ʈ���� �����մϴ�.
	else if (value >= root->data)
	{
		root->right = Insert(root->right, value);
		root = Balance(root);
	}
	return root;
}

template<class T>
bool AvlTree<T>::IsEmpty() const
{
	if (root == nullptr)
		return true;
	else
		return false;
}

template<class T>
bool AvlTree<T>::IsFull() const
{
	nodeAVL<T>* room;					// �ӽ��� node�� �����
	try
	{
		room = new nodeAVL<T>;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

template<class T>
void AvlTree<T>::MakeEmpty()
{
	root = NULL;
}

template<class T>
int AvlTree<T>::GetLength() const
{
	return CountNodes(root);
}

template<class T>
void AvlTree<T>::Add(T& item)
{
	Insert(root, item);
}

template<class T>
int AvlTree<T>::DeleteItem(T item)
{
	if (Delete(root, item))
	{
		root = Balance(root);
		return 1;
	}
	return 0;
}

template<class T>
int AvlTree<T>::Replace(T item)
{
	if (DeleteItem(item))
	{
		Add(item);
		return 1;
	}
	else
		return 0;
}

template<class T>
int AvlTree<T>::RetrieveItem(T & item, bool & found) const
{
	Retrieve(root, item, found);
	return found ? 1 : 0;
}

// ���� ū ���� ã�� �Լ� 
template<class T>
void GetPredecessor(nodeAVL<T> *root, T& item)
{
	while (root->right != nullptr)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ���� ���� ���� ã�� �Լ� 
template<class T>
void GetSuccessor(nodeAVL<T> *root, T& item)
{
	while (root->left != nullptr)			// root�� �������� ������ ���
		root = root->left;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;		        // root ����� ���� item�� �����Ѵ�.
}

template<class T>
void AvlTree<T>::PrintTree(ostream & out) const
{
	inorder(root, out);
}

template<class T>
void AvlTree<T>::WriteUser(ofstream& fout)
{
	Write(root, fout);
}

template<class T>
void AvlTree<T>::DeleteNode(nodeAVL<T> *&node)
{
	T item;
	nodeAVL<T>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = node;

	if (node->left == nullptr)				// ���ʳ�尡 ���� ��
	{
		node = node->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (node->right == nullptr)		// �����ʳ�尡 ���� ��
	{
		node = node->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(node->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		node->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		Delete(node->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

template<class T>
int AvlTree<T>::Delete(nodeAVL<T> *&root, T item)
{
	if (root != nullptr) {
		if (item < root->data)				// root��尪���� item��尡 ���� ��
			Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
		else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
			Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
		else {
			DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
			return 1;
		}
	}
	else {
		return 0;
	}
}

/*
template<class T>
T* AvlTree<T>::GetNextItem()
{
	GetNext(cur);
}

template<class T>
T * AvlTree<T>::GetNext(nodeAVL<T>* curp)
{
	nodeAVL<T> node;
	if (curp != NULL)
	{
		if (curp->left != NULL)
		{
			GetNext(curp->left);
			node = curp->data;
			cur = curp->left;
			return node;
		}
		else if (curp->right != NULL)
		{
			GetNext(node->right, curp->right);
			node = curp->data;
			cur = curp->right;
			return node;
		}
	}
}

template<class T>
void AvlTree<T>::ResetCur()
{
	cur == root;
}
*/

template <class T>
void Retrieve(nodeAVL<T>* root, T& item, bool& found)
{
	if (root == nullptr)
		found = false;
	else if (item < root->data)
		Retrieve(root->left, item, found);
	else if (item > root->data)
		Retrieve(root->right, item, found);
	else
	{
		item = root->data;
		found = true;
	}
}

template<class T>
void Write(nodeAVL<T>* tree, ofstream& out)
{
	if (tree == NULL)
		return;
	else
	{
		Write(tree->left, out);
		out << tree->data << endl;
		Write(tree->right, out);
	}
}

template<class T>
void inorder(nodeAVL<T> * tree, ostream& out)
{
	if (tree == NULL)
		return;
	else
	{
		inorder(tree->left, out);
		out << tree->data << endl << endl;
		inorder(tree->right, out);
	}
}

template<class T>
void preorder(nodeAVL<T>* tree, ostream& out)
{
	if (tree == NULL)
		return;
	else
	{
		out << tree->data << endl << endl;
		preorder(tree->left, out);
		preorder(tree->right, out);
	}

}

template<class T>
void postorder(nodeAVL<T>* tree, ostream& out)
{
	if (tree == NULL)
		return;
	else
	{
		postorder(tree->left, out);
		postorder(tree->right, out);
		out << tree->data << endl << endl;
	}
}

template<class T>
int CountNodes(nodeAVL<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}
