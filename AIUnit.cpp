#include "AIUnit.h"
#include "AIUser.h"

void AIUnit::onEvent(int eid)
{
	UnitEvent e(eid, this);
	this->catchEvent(e);

	if (owner)
	{
		owner->onUnitEvent(eid);
	}
}