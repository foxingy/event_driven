#include "event_trigger.h"
#include "trigger.h"

//template <typename Key>
//void EventTrigger<Key>::catchEvent(const Key& e)
//{
//	struct Exec
//	{
//		const Key& e_;
//		Exec(Key& e):e_(e){}
//		void operator()(const AITrigger* t)
//		{
//			t->catchEvent(e_);
//		}
//	};
//	if (EventTriggerMapIt it = e_t_.find(e) != e_t_.end())
//	{
//		Exec exe(e);
//		std::for_each(it->second.begin(), it->second.end(), exe);
//	}
//	
//}