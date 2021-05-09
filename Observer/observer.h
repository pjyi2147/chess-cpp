#ifndef _OBSERVER_H_
#define _OBSERVER_H_
template <typename StateType>
class Subject;

template <typename StateType>
class Observer {
public:
    virtual void notify(Subject<StateType>
                                &whoFrom) = 0; // pass the Subject that called
    // the notify method
    virtual ~Observer() = default;
};

#endif
