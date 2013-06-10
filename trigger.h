#pragma once
#include <set>
#include "boost/variant.hpp"
#include "action.h"
#include "condition.h"

struct UnitEvent;
struct PlayerUnitEvent;
struct AnyUnitEvent;

typedef boost::variant<UnitEvent, PlayerUnitEvent, AnyUnitEvent> EventVar;
typedef std::set<EventVar> EventList;

class AITrigger
{
public:
	template <typename T>
	void addEvent(const T& e)
	{
		events_.insert(e);
	}
	template <typename T>
	void catchEvent(const T& e)
	{
		events_.erase(e);
		if (events_.empty())
		{
			if (cond_())
			{
				action_();
			}
		}
	}
	void setAction(ActionFn fn)
	{
		action_.setfn(fn);
	}
	void setCond(CondFn fn)
	{
		cond_.setfn(fn);
	}
	EventList	events_;
	AIAction	action_;
	AICond		cond_;
};