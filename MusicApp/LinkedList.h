#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
#include <string>
using namespace std;

//���Ḯ��Ʈ���� ���Ǵ� ����ü
template <typename N>
struct NodeType
{
	N info;
	NodeType *next;
	void operator = (const NodeType<N>& n)
	{
		info = n.info;
	}
};

template <typename T>
class LinkedList
{
public:
	/**
	*   ������
	*/
	LinkedList();

	/**
	*   �Ҹ���
	*/
	~LinkedList();
	//������ = �����ε�
	void operator=(LinkedList<T> &l);
	/**
	*   @brief   Initialize list to empty state.
	*   @pre   None
	*   @post   List is empty.
	*/
	void MakeEmpty();
	void ResetList();
	/**
	*   @brief   Add item into appropriate spot of this list.
	*   @pre   List is not full. item is not in list.
	*   @post   Item is inserted in this list.
	*   @return   1 if this function works well, otherwise 0.
	*/
	int Add(T& data);
	/**
*   @brief   Delete item from this list.
*   @pre   List is not empty. the item exists in list.
*   @post   Item is deleted from this list.
*   @return   1 if this function works well, otherwise 0.
*/
	int Delete(T data);
	/**
	*   @brief   Change value of item which is in this list.
	*   @pre   List is not empty. the item exists in list.
	*   @post   Item's value is changed.
	*   @return   1 if this function works well, otherwise 0.
	*/
	int Replace(T& data);
	/**
	*   @brief   Retrieve list element whose key matches item's key (if present).
	*   @pre   Key member of item is initialized.
	*   @post   If there is an element whose key matches with item's key then the element's record is copied to the item.
	*   @return   1 if any element's primary key matches with item's, otherwise 0.
	*/
	int	Get(T& data);
	/**
	*   @brief   Get the next element in list.
	*   @pre   current pointer is defined. Element at current pointer is not last in list.
	*   @post   current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& data);
	/**
	*   @brief   Get number of elements in the list.
	*   @pre   None.
	*   @post   Function value = number of elements in list.
	*   @return   Number of elements in this list.
	*/
	int GetLength() const;

private:
	NodeType<T> *m_pList;
	NodeType<T> *m_pCurpointer;
	int m_Length;
};

//������
template<typename T>
LinkedList<T>::LinkedList()
{
	m_Length = 0;
	m_pList = nullptr;
	m_pCurpointer = nullptr;
}
//�Ҹ���
template<typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

template<typename T>
void LinkedList<T>::operator=(LinkedList<T>& l)
{
	// ���� ��� �ʱ�ȭ
	MakeEmpty();

	// ����Ʈ�� ������ ���
	if (l.GetLength())
	{
		// l curPtr �ʱ�ȭ
		l.ResetList();

		T data;
		//��� ����
		for (int i = 0; i < l.GetLength(); i++)
		{
			l.GetNextItem(data);
			Add(data);
		}
	}
}
//�� ����Ʈ �����
template<typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T> *temp;

	while (m_pList != nullptr) //Null�� �ƴ� ����
	{
		temp = m_pList; //temp�� m_pList���� ����
		m_pList = m_pList->next; //m_pList�� m_pList�� ���� ��带 ����
		delete temp; //temp���� ����
	}
	m_Length = 0;
}
template<typename T>
void LinkedList<T>::ResetList()
{
	m_pCurpointer = nullptr;
}

//����Ʈ ���� �߰�
template<typename T>
int LinkedList<T>::Add(T& data)
{
	ResetList(); //������ �ʱ�ȭ

	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *preLoc;
	T dummy;

	node->info = data;
	node->next = nullptr;

	if (!m_Length) //0�϶�
	{
		m_pList = node;
	}
	else
	{
		if (Get(data) == 1)
		{
			return 0;
		}
		else
		{
			while (1)
			{
				preLoc = m_pCurpointer; //preLoc�� curpointer
				GetNextItem(dummy); //pointer ����

				if (m_pCurpointer->info > node->info)
				{
					if (preLoc == nullptr)
						//���� �ڸ� �� ���Ұ� �������� ���� ��
					{
						node->next = m_pCurpointer;
						m_pList = node;
						break;
					}

					node->next = m_pCurpointer;
					preLoc->next = node;
					break;
				} //���� ����Ű�� ������ info���� node�� info���� Ŭ ��� pre�ڿ� ����.
				if (m_pCurpointer->next == nullptr) //�ǵڿ� ����
				{
					m_pCurpointer->next = node;
					break;
				}
			}
		}
	}

	m_Length++;
	return 1;
}
//����Ʈ ���� ����
template<typename T>
int LinkedList<T>::Delete(T data)
{
	bool moreToSearch, found;
	NodeType<T>* pre = nullptr; // ��������

	m_pCurpointer = m_pList; //�����͸� ù��° ����
	found = false;
	moreToSearch = (m_pCurpointer != nullptr); //�������Ͱ� Null�� �Ǹ�(�������� �����ϸ�) moreToSearch�� False��

	while (moreToSearch && !found)
	{
		if (data == m_pCurpointer->info)
		{
			found = true; //ã��
			if (pre == nullptr)
				m_pList = m_pCurpointer->next; //������ �ٸ� ���Ұ� ������ �׸��� ���� ���Ҹ� ù��° ���ҷ� 
			else
			{
				pre->next = m_pCurpointer->next;
				delete m_pCurpointer;
			}//������ ������ �������Ҹ� ����Ű�� �׸��� ���� ���ҷ� �ٲ۴�.
			m_Length--;
		}
		else
		{
			pre = m_pCurpointer; //pre�� �������������� ��带 ����
			m_pCurpointer = m_pCurpointer->next; //�������Ϳ� ���� ��尪�� ����
			moreToSearch = (m_pCurpointer != nullptr); //moreTosearch�� ������Ʈ
		}
	}

	if (found)
		return 1;
	else
		return 0;
}
//����Ʈ ���� ����
template<typename T>
inline int LinkedList<T>::Replace(T& data)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);
	// location�� NULL�� �ƴϸ� moreToSearch�� �ؾ��Ѵ�.

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (data == location->info)
		{
			found = true;
			location->info = data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;
}
//����Ʈ ���� ���
template<typename T>
int LinkedList<T>::Get(T & data)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (data == location->info)
		{
			found = true;
			data = location->info;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;
}
//���� �������� ���
template<typename T>
void LinkedList<T>::GetNextItem(T & data)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurpointer == nullptr)
	{
		m_pCurpointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurpointer = m_pCurpointer->next;

	data = m_pCurpointer->info;
	//item �� current position �� info �� ����

}
// ���� ���
template<typename T>
int LinkedList<T>::GetLength() const
{
	return m_Length;
}
#endif // ! _LINKED_LIST_