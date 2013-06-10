#pragma once
#include <map>
#include <vector>
#include "trigger.h"

template <typename Key>
class EventTrigger
{
public:
	EventTrigger(){}
	~EventTrigger(){}
	void addEvent(const Key& e, AITrigger* t)
	{
		e_t_[e].push_back(t);
	}
	void catchEvent(const Key& e);

private:
	typedef std::map<Key, std::vector<AITrigger*> > EventTriggerMap;
	typedef typename EventTriggerMap::iterator EventTriggerMapIt;
	EventTriggerMap e_t_;
};

template <typename Key>
void EventTrigger<Key>::catchEvent(const Key& e)
{
	EventTriggerMapIt it = e_t_.find(e);
	if (it != e_t_.end())
	{
		std::vector<AITrigger*>& ll = it->second;
		std::vector<AITrigger*>::iterator it2 = ll.begin();
		for (; it2 != ll.end(); it2++)
		{
			(*it2)->catchEvent(e);
		}
	}
}