#pragma once

class AIUnit;
class AIUser;

enum UnitEventType
{
	DEATH,
};

enum EventType
{
	UNIT_EVENT,
	PLAYER_UNIT_EVENT,
	ANY_UNIT_EVENT,
};
struct AIEvent
{
	int eid;
	int etype;
	AIEvent(int id, int etype):eid(id),etype(etype){}
	bool operator<(const AIEvent& e) const
	{
		return eid<e.eid && etype<e.etype;
	}
};

struct UnitEvent : public AIEvent
{
	AIUnit* unit;
	UnitEvent(int id, AIUnit* u)
		:AIEvent(id,UNIT_EVENT),
		unit(u)
	{
	}

	bool operator<(const UnitEvent& e) const
	{
		return AIEvent::operator <(e) && unit < e.unit;
	}
};

struct PlayerUnitEvent : public AIEvent
{
	AIUser* user;
	PlayerUnitEvent(int id, AIUser* user)
		:AIEvent(id, PLAYER_UNIT_EVENT),
		user(user)
	{
	}
	bool operator<(const PlayerUnitEvent& e) const
	{
		return AIEvent::operator <(e) && user < e.user;
	}
};

struct AnyUnitEvent : public AIEvent
{

};
