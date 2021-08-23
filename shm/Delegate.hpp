#ifndef DELEGATE_HPP
#define DELEGATE_HPP

class Delegate {
public:
    virtual ~Delegate() = default;
    virtual void payCrew(size_t money) = 0;
};

#endif