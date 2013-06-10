#pragma once
#include "event_trigger.h"
#include "event.h"
class AIUser : public EventTrigger<PlayerUnitEvent>
{
public:
	void onUnitEvent(int eid);
private:
};