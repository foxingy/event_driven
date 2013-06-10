#pragma once
#include "event.h"
#include "event_trigger.h"

class AIUser;
class AIUnit : public EventTrigger<UnitEvent>
{
public:
	AIUnit():owner(NULL){}
	~AIUnit(){}
	void onEvent(int eid);
	
	void setOwner(AIUser* user)
	{
		owner = user;
	}
	void todie()
	{
		this->onEvent(DEATH);
	}
private:
	AIUser* owner;
};