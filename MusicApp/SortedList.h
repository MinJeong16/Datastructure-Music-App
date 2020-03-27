#ifndef _SORTED_LIST_
#define _SORTED_LIST_
#define INPUTSIZE 10
#include <iostream>
#include <string>
#include <fstream>
#include "MusicType.h"
using namespace std;

template <typename T>
class SortedList
{
public:
	/**
	*	@brief	������
	*/
	SortedList();

	/**
	*   @brief	�Ҹ���
	*/
	~SortedList();

	/**
	*	@brief	����Ʈ �ʱ�ȭ
	*/
	void MakeEmpty();
	/**
	*	@brief	m_CurPointer �ʱ�ȭ
	*/
	void ResetList();
	/**
	*	@brief	�迭 ���� ���
	*	@return m_Length
	*/
	int GetLength();
	/**
	*	@brief	�迭�� ��á���� Ȯ��
	*/
	bool IsFull();
	/**
	*	@brief	�迭�� ������� Ȯ��
	*/
	bool IsEmpty();
	/**
	*	@brief	�迭�� ���� �߰�
	*	@param	data	���ο� ������
	*	@return ����� �߰� 1, �ƴϸ� 0
	*/
	int Add(T& data);
	/**
	*	@brief	�迭�� ���� ����
	*	@param	data	���ο� ������
	*	@return ����� ���� 1, �ƴϸ� 0
	*/
	int Delete(T& data);
	/**
	*	@brief	�迭�� ���� ����
	*	@param	data	���ο� ������
	*	@return ����� ���� 1, �ƴϸ� 0
	*/
	int Replace(T& data);
	/**
		*	@brief	�迭�� data�� primary key�� ���� ������ ���
		*	@param	data	primary key�� �´� ������
		*	@return	���� �۵� 1, �ƴϸ� 0
	**/
	int Retrieve(T& data);
	/**
	*	@brief	�迭�� ���� �� ���
	*	@param	data	�迭 ���� �� ������
	*	@return	���� �۵� 1, �ƴϸ� 0
	*/
	int GetNextItem(T& data);
	/**
	*	@brief	SortedList ������ = ����
	*/
	void operator=(SortedList<T> &s);

	T at(int index);

	int GetCur();

private:
	T* m_Array;
	int m_Length;
	int m_CurPointer;
	int m_MaxSize;
};
//������
template<typename T>
SortedList<T>::SortedList()
{
	m_MaxSize = INPUTSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}
//�Ҹ���
template<typename T>
SortedList<T>::~SortedList()
{
	delete[] m_Array;
}
//�迭 �ʱ�ȭ
template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}
//�迭 �������� �ʱ�ȭ
template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}
// �迭 ���� ���
template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}
//�迭 ��á���� Ȯ��
template<typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > m_MaxSize - 1)
	{
		return true;
	}
	return false;
}
//�迭 ������� Ȯ��
template<typename T>
bool SortedList<T>::IsEmpty()
{
	if (m_Length == 0)
	{
		return true;
	}
	return false;
}
//�迭 ���� �߰�
template<typename T>
int SortedList<T>::Add(T& data)
{
	if (IsFull())
	{
		T* tmp = new T[m_Length];
		for (int i = 0; i < m_Length; i++)
		{
			tmp[i] = m_Array[i];
		}
		delete[] m_Array;

		m_MaxSize += INPUTSIZE;
		m_Array = new T[m_MaxSize];
		for (int i = 0; i < m_Length; ++i)
		{
			m_Array[i] = tmp[i];
		}
		delete[] tmp;
	}

	bool found = false;
	int iPos = 0;

	if (IsEmpty())
	{
		m_Array[iPos] = data;
		m_Length++;
		return 1;
	}
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] < data) {
				if (i == m_Length - 1)
				{
					m_Array[m_Length] = data;
					m_Length++;
					return 1;
				}
			}
			else if (m_Array[i] > data) {
				for (int j = m_Length; j > i; j--)
				{
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[i] = data;
				m_Length++;
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	return 0;
}

//�迭 ���� ����
template<typename T>
int SortedList<T>::Delete(T& data)
{
	if (Retrieve(data))
	{
		if (m_Length == 1)
		{
			m_Length--;
			return 1;
		}
		else
		{
			for (int i = m_CurPointer + 1; i < m_Length; i++)
			{
				m_Array[i - 1] = m_Array[i];
			}
			m_Length--;
		}
		return 1;
	}
	return 0;
}

//�迭 ���� ����
template<typename T>
int SortedList<T>::Replace(T& data)
{
	m_CurPointer = 0;
	while (m_CurPointer < m_Length)
	{
		if (data == m_Array[m_CurPointer])
		{
			m_Array[m_CurPointer] = data;
			return 1;
		}
		m_CurPointer++;
	}
	return 0;
}
//�迭 ���� ã�� _ binary search
template<typename T>
int SortedList<T>::Retrieve(T &data)
{
	if (m_Length == 0)
	{
		return 0;
	}
	int start = 0;
	int end = m_Length - 1;
	int middle;
	while (start <= end)
	{
		middle = (start + end) / 2;

		if (data == m_Array[middle])
		{
			data = m_Array[middle];
			m_CurPointer = middle;
			return 1;
		}
		else if (data > m_Array[middle])
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	return 0;
}
//�迭 ������ ���
template<typename T>
int SortedList<T>::GetNextItem(T & data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}
//������ = �����ε�
template<typename T>
void SortedList<T>::operator=(SortedList<T>& s)
{
	MakeEmpty();

	if (s.GetLength())
	{
		s.ResetList();

		T data;
		for (int i = 0; i < s.GetLength(); i++)
		{
			s.GetNextItem(data);
			Add(data);
		}
	}
}

template<typename T>
inline T SortedList<T>::at(int index)
{
	T temp;
	ResetList();
	for (int i = 0; i <= index; i++)
		GetNextItem(temp);
	return temp;
}

template<typename T>
int SortedList<T>::GetCur()
{
	return m_CurPointer;
}

#endif