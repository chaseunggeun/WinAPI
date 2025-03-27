#pragma once
#include "UiManager.h"

class BackGroundUIManager : UiManager
{
public:
	virtual UI* CreateUI() override;

	BackGroundUIManager() {};
	virtual ~BackGroundUIManager() {};
};

