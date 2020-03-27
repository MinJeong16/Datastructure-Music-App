#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.


	bool NotNull(); //포인터가 null이면 false return
	bool NextNotNull(); //포인터의 next가  null이면 false return
	T First(); //초기화
	T Next(); //다음노드의 data
	T Prev(); //이전 노드의 data
	DoublyNodeType<T> GetCurrentNode(); //현재 노드 리턴
private:
	const DoublySortedLinkedList<T> &m_List;
	DoublyNodeType<T>* m_pCurPointer;
};

template <typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else if (m_pCurPointer->next->next == NULL) //m_Last
		return false;
	else
		return true;
}

//처음으로 초기화
template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

//다음 노드의 데이터를 리턴
template <typename T>
T DoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template<typename T>
T DoublyIterator<T>::Prev()
{
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer->data;
}

//현재 노드의 포인터를 리턴
template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _DOUBLYITERATOR_H