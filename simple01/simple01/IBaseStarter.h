#pragma once
class IBaseStarter
{
public:
	IBaseStarter();
	virtual ~IBaseStarter();
	virtual void run() = 0;
};

