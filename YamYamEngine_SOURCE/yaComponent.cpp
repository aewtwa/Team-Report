#include "yaComponent.h"


namespace ya
{
    Component::Component(COMPONENTTYPE type)
        : mType(type)
        , mOwner(nullptr)
        , isActivate(true)
    {
    }

    Component::~Component()
    {
    }
}
