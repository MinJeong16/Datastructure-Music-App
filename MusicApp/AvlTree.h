#pragma once
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

/*
* AVL Tree에서 쓰이는 NodeAVL 구조체
*/
template <class T>
struct nodeAVL
{
	T data;
	nodeAVL* left;
	nodeAVL* right;
};

//AVL Tree 클래스
template <class T>
class AvlTree
{
private:
	nodeAVL<T>* root;
	nodeAVL<T>* cur;

public:
	/*
* 디폴트 생성자
*/
	AvlTree();

	/**
	*	소멸자.
	*/
	~AvlTree();

	/**
	*	트리의 height를 계산해주는 함수
	*/
	int height(nodeAVL<T>* node);

	/**
	*	
	*	노드간의 높이를 계산해서 로테이션이 필요한지 확인할 때 사용
	*/
	int diff(nodeAVL<T>* node);

	//회전 함수들
	nodeAVL<T>* RR(nodeAVL<T>* parent);
	nodeAVL<T>* LL(nodeAVL<T>* parent);
	nodeAVL<T>* LR(nodeAVL<T>* parent);
	nodeAVL<T>* RL(nodeAVL<T>* parent);

	//회전 함수를 이용해 균형을 맞추는 함수
	nodeAVL<T>* Balance(nodeAVL<T>* temp);

	//avl tree에 노드를 삽입
	nodeAVL<T>* Insert(nodeAVL<T>*& root, T value);
	/**
*	@brief	Tree가 Empty인지 확인
*	@pre	none
*	@post	none
*	@return	Tree가 비어있으면 true리턴, 아니면 false 리턴
*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree가 Full인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 Full이면 true 리턴, 아니면 false 리턴
	*/
	bool IsFull() const;

	/**
	*	@brief	Tree를 비운다
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree에 node가 몇 개인지 확인함
	*	@pre	none
	*	@post	none
	*	@return	Tree의 node 개수를 리턴
	*/
	int GetLength() const;

	/**
	*	@brief	Tree에 새 node를 추가한다
	*	@pre	T의 객체를 생성
	*	@post	Tree에 새 node가 추가됨
	*/
	void Add(T& item);

	/**
	*	@brief	Tree에서 지우고자 하는 node를 찾고 지움
	*	@pre	T의 객체를 생성
	*	@post	Tree에서 입력한 node가 삭제됨
	*/
	int DeleteItem(T item);

	/**
	*	@brief	Tree에 새 node로 갱신한다
	*	@pre	T의 객체를 생성
	*	@post	Tree에 새 node가 갱신됨
	*/
	int Replace(T item);
	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	node가 Tree에 있는지 검색결과를 알려줌
	*/
	int RetrieveItem(T& item, bool &found)const;

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void PrintTree(ostream &out)const;

	//파일을 작성
	void WriteUser(ofstream& fout);

	//노드 삭제
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
	//왼쪽 자식을 기준으로 RR, 본인을 기준으로 LL
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
	// 왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우입니다.
	if (factor > 1)
	{
		// 그 왼쪽 자식노드에 문제가 발생했습니다.
		if (diff(temp->left) > 0)
		{
			temp = LL(temp);
		}
		// 그 오른쪽 자식 노드에 문제가 발생했습니다.
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
	// 현재 트리가 비었을 때
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
	// 크거나 같은 경우 오른쪽 서브트리에 삽입합니다.
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
	nodeAVL<T>* room;					// 임시의 node를 만들고
	try
	{
		room = new nodeAVL<T>;		// 새 노드를 추가할 수 있는지 확인
		delete room;			// 임시로 만든 room 노드를 지움
		return false;			// isFull에 대한 false 리턴
	}
	catch (std::bad_alloc exception)		// 더 이상 아이템 추가를 할 수 없고 Full일 경우
	{
		return true;					// isFull에 대한 true 리턴
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

// 가장 큰 값을 찾는 함수 
template<class T>
void GetPredecessor(nodeAVL<T> *root, T& item)
{
	while (root->right != nullptr)			// root의 오른쪽이 존재할 경우
		root = root->right;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->data;					// root 노드의 값을 item에 복사한다.
}

// 가장 작은 값을 찾는 함수 
template<class T>
void GetSuccessor(nodeAVL<T> *root, T& item)
{
	while (root->left != nullptr)			// root의 오른쪽이 존재할 경우
		root = root->left;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->data;		        // root 노드의 값을 item에 복사한다.
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
	nodeAVL<T>* tempPtr;			// 임시 노드를 생성하고 root 노드를 임시 노드에 복사
	tempPtr = node;

	if (node->left == nullptr)				// 왼쪽노드가 없을 때
	{
		node = node->right;				// 오른쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else if (node->right == nullptr)		// 오른쪽노드가 없을 때
	{
		node = node->left;				// 왼쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else
	{
		GetPredecessor(node->left, item);	// 중간에 있는 노드를 지우고 싶을 때 (left, right, child 노드 있을 경우)
		node->data = item;					// 지우려는 노드보다 작은 노드들 중에 가장 큰 노드를 찾음
		Delete(node->left, item);			// 그 값을 지울 노드에 복사를 해서 지운 것처럼 눈속임
	}
}

template<class T>
int AvlTree<T>::Delete(nodeAVL<T> *&root, T item)
{
	if (root != nullptr) {
		if (item < root->data)				// root노드값보다 item노드가 작을 때
			Delete(root->left, item);		// 왼쪽노드로 가서 delete함수 호출
		else if (item > root->data)			// root노드값보다 item노드가 클 때
			Delete(root->right, item);		// 오른쪽노드로 가서 delete함수 호출
		else {
			DeleteNode(root);				// 찾고자 하는 값이 일치하는 경우 deletenode 함수 호출
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
