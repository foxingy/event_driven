#pragma once
#include <functional>

//typedef std::function<void()> ActionFn;
typedef void (*ActionFn)();
class AIAction
{
public:
	AIAction()
	{
	}
	~AIAction()
	{
	}
	void setfn(ActionFn fn)
	{
		fn_ = fn;
	}
	void operator()()
	{
		fn_();
	}
private:
	ActionFn fn_;
};