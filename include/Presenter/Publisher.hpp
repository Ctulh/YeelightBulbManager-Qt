
#pragma once

#include <memory>
#include <list>

class Subscriber;
using SubscriberPtr = std::shared_ptr<Subscriber>;

class Publisher {
public:
    virtual ~Publisher() = default;

public:
    virtual void attach(SubscriberPtr subscriber);
    virtual void detach(SubscriberPtr subscriber);
    virtual void notify(std::string const& message);

protected:
    std::list<SubscriberPtr> m_subscribers;
};
