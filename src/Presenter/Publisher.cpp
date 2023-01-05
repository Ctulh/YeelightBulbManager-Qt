#include "Publisher.hpp"
#include "Subscriber.hpp"

void Publisher::attach(SubscriberPtr subscriber) {
    m_subscribers.push_back(subscriber);
}

void Publisher::detach(SubscriberPtr subscriber) {
    m_subscribers.remove(subscriber);
}

void Publisher::notify(const std::string &message) {
    for(auto& subscriber: m_subscribers) {
        subscriber->update(message);
    }
}
