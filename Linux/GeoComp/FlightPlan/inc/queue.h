// AUTHOR:		
// PROJECT:		Fun
// DOCUMENT:	None
// DESCRIPTION: This file defines queue

#ifndef _QUEUE_H
#define _QUEUE_H 

#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class Queue
{
	private:

		mutex m_mutex;
		condition_variable m_condition;
		queue<T> m_data;

	public:

		Queue()=default;
		Queue(const Queue&)=delete;
		Queue& operator=(const Queue&)=delete;

		void push(const T& value)
		{
			lock_guard<mutex> lock(m_mutex);
			m_data.push(value);
			m_condition.notify_one();
		}

		T pop( )
		{
			unique_lock<mutex> lock(m_mutex);

			// Check to see whether the queue is empty
			while (m_data.empty() == true)
			{
				m_condition.wait(lock);
			}

			T value = m_data.front();
			m_data.pop();

			return value;
		}

		size_t size() 
		{
			lock_guard<mutex> lock(m_mutex);
			return m_data.size();
		}
}; 

#endif