// simple01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include "SimpleAnimation.h"

int main()
{
	auto mStarter = std::make_unique<SimpleAnimation>();
	mStarter->run();
    return 0;
}

