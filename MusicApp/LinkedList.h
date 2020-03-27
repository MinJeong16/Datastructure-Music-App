#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
#include <string>
using namespace std;

//연결리스트에서 사용되는 구조체
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
	*   생성자
	*/
	LinkedList();

	/**
	*   소멸자
	*/
	~LinkedList();
	//연산자 = 오버로딩
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

//생성자
template<typename T>
LinkedList<T>::LinkedList()
{
	m_Length = 0;
	m_pList = nullptr;
	m_pCurpointer = nullptr;
}
//소멸자
template<typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

template<typename T>
void LinkedList<T>::operator=(LinkedList<T>& l)
{
	// 기존 노드 초기화
	MakeEmpty();

	// 리스트가 존재할 경우
	if (l.GetLength())
	{
		// l curPtr 초기화
		l.ResetList();

		T data;
		//노드 복사
		for (int i = 0; i < l.GetLength(); i++)
		{
			l.GetNextItem(data);
			Add(data);
		}
	}
}
//빈 리스트 만들기
template<typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T> *temp;

	while (m_pList != nullptr) //Null이 아닌 동안
	{
		temp = m_pList; //temp에 m_pList값을 저장
		m_pList = m_pList->next; //m_pList에 m_pList의 다음 노드를 연결
		delete temp; //temp값을 삭제
	}
	m_Length = 0;
}
template<typename T>
void LinkedList<T>::ResetList()
{
	m_pCurpointer = nullptr;
}

//리스트 원소 추가
template<typename T>
int LinkedList<T>::Add(T& data)
{
	ResetList(); //포인터 초기화

	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *preLoc;
	T dummy;

	node->info = data;
	node->next = nullptr;

	if (!m_Length) //0일때
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
				preLoc = m_pCurpointer; //preLoc에 curpointer
				GetNextItem(dummy); //pointer 갱신

				if (m_pCurpointer->info > node->info)
				{
					if (preLoc == nullptr)
						//넣을 자리 앞 원소가 존재하지 않을 때
					{
						node->next = m_pCurpointer;
						m_pList = node;
						break;
					}

					node->next = m_pCurpointer;
					preLoc->next = node;
					break;
				} //지금 가리키는 원소의 info값이 node의 info보다 클 경우 pre뒤에 삽입.
				if (m_pCurpointer->next == nullptr) //맨뒤에 넣음
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
//리스트 원소 삭제
template<typename T>
int LinkedList<T>::Delete(T data)
{
	bool moreToSearch, found;
	NodeType<T>* pre = nullptr; // 변수선언

	m_pCurpointer = m_pList; //포인터를 첫번째 노드로
	found = false;
	moreToSearch = (m_pCurpointer != nullptr); //컬포인터가 Null이 되면(마지막에 도달하면) moreToSearch를 False로

	while (moreToSearch && !found)
	{
		if (data == m_pCurpointer->info)
		{
			found = true; //찾음
			if (pre == nullptr)
				m_pList = m_pCurpointer->next; //이전에 다른 원소가 없을때 항목의 다음 원소를 첫번째 원소로 
			else
			{
				pre->next = m_pCurpointer->next;
				delete m_pCurpointer;
			}//이전의 원소의 다음원소를 가리키는 항목의 다음 원소로 바꾼다.
			m_Length--;
		}
		else
		{
			pre = m_pCurpointer; //pre에 현재컬포인터의 노드를 저장
			m_pCurpointer = m_pCurpointer->next; //컬포인터에 다음 노드값을 저장
			moreToSearch = (m_pCurpointer != nullptr); //moreTosearch값 업데이트
		}
	}

	if (found)
		return 1;
	else
		return 0;
}
//리스트 원소 갱신
template<typename T>
inline int LinkedList<T>::Replace(T& data)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);
	// location이 NULL이 아니면 moreToSearch를 해야한다.

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (data == location->info)
		{
			found = true;
			location->info = data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;
}
//리스트 원소 얻기
template<typename T>
int LinkedList<T>::Get(T & data)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (data == location->info)
		{
			found = true;
			data = location->info;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;
}
//다음 아이템을 얻기
template<typename T>
void LinkedList<T>::GetNextItem(T & data)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurpointer == nullptr)
	{
		m_pCurpointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurpointer = m_pCurpointer->next;

	data = m_pCurpointer->info;
	//item 에 current position 의 info 를 삽입

}
// 길이 얻기
template<typename T>
int LinkedList<T>::GetLength() const
{
	return m_Length;
}
#endif // ! _LINKED_LIST_