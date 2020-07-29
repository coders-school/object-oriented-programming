#pragma once

struct IDelegate
{
    virtual ~IDelegate() = default;
    virtual void PayCrew(size_t money) = 0;
};
