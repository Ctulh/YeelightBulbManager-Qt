
#pragma once

template<typename T>
class Singleton {
public:
    virtual ~Singleton() = default;
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }

protected:
    Singleton() = default;
    Singleton(Singleton const&) = default;
    Singleton& operator =(Singleton const&) = default;
};
