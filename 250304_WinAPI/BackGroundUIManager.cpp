#include "BackGroundUIManager.h"
#include "BackGround.h"

UI* BackGroundUIManager::CreateUI()
{
    return new BackGround();
}
