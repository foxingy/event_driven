#include <iostream>

#include "AIUnit.h"
#include "AIUser.h"
#include "event.h"
#include "trigger.h"
using namespace std;

void registerUnitEvent(AITrigger* t, AIUnit* u, int eid)
{
	UnitEvent e(eid, u);
	t->addEvent(e);
	u->addEvent(e, t);
}
void registerPlayerUnitEvent(AITrigger* t, AIUser* u, int eid)
{
	PlayerUnitEvent e(eid, u);
	t->addEvent(e);
	u->addEvent(e, t);
}

void registerCondition(AITrigger* t, CondFn fn)
{
	t->setCond(fn);
}

void registerAction(AITrigger* t, ActionFn fn)
{
	t->setAction(fn);
}

bool check()
{
	cout<<"condition check true!"<<endl;
	return true;
}

void action()
{
	cout<<"action!"<<endl;
}

int main()
{
	AITrigger* trig = new AITrigger;
	AIUser* user = new AIUser;
	AIUnit* unit1 = new AIUnit;
	AIUnit* unit2 = new AIUnit;

	unit2->setOwner(user);
	registerUnitEvent(trig, unit1, DEATH);
	registerPlayerUnitEvent(trig,user,DEATH);
	registerCondition(trig, check);
	registerAction(trig, action);
	unit1->todie();
	unit2->todie();

	system("pause");
	return 1;
}