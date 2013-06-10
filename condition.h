#pragma once

//typedef std::function<bool()> CondFn;
typedef bool (*CondFn)();
class AICond
{
public:
	AICond(){}
	~AICond(){}
	void setfn(CondFn fn)
	{
		fn_ = fn;
	}
	bool operator()()
	{
		return fn_();
	}
private:
	CondFn fn_;
};