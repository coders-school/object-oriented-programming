

struct IDelegate
{
    virtual ~IDelegate(){};
    virtual void PayCrew(size_t money) = 0;
};
