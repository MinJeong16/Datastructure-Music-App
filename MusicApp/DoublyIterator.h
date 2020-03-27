#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.


	bool NotNull(); //�����Ͱ� null�̸� false return
	bool NextNotNull(); //�������� next��  null�̸� false return
	T First(); //�ʱ�ȭ
	T Next(); //��������� data
	T Prev(); //���� ����� data
	DoublyNodeType<T> GetCurrentNode(); //���� ��� ����
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

//ó������ �ʱ�ȭ
template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

//���� ����� �����͸� ����
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

//���� ����� �����͸� ����
template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _DOUBLYITERATOR_H