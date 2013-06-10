#include "AIUser.h"

void AIUser::onUnitEvent(int eid)
{
	PlayerUnitEvent e(eid, this);
	this->catchEvent(e);
}