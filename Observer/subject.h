#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

/* A note on InfoType and StateType:

   We have separated the collection of fields into two parts:  its Info
   and its State.

   Info is for the parts of the subjject inherent to what it is:  its position
   and its colour.

   State is for the parts of the subject that, when changed, trigger
   notifications.  This is the information that the Observer "gets" when it
   calls getState on the subject.  It comprises the type of state, a direction,
   and a colour.  For more details, see state.h.
*/

template <typename StateType>
class Observer;

template <typename StateType>
class Subject {
    std::vector<Observer<InfoType, StateType> *> observers;
    StateType state;

protected:
    void setState(StateType newS);

public:
    void attach(Observer<StateType> *o);
    void notifyObservers();
    virtual InfoType getInfo() const = 0;
    StateType getState() const;
};

template <typename StateType>
void Subject<StateType>::attach(Observer<StateType> *o) {
    observers.emplace_back(o);
}

template <typename StateType>
void Subject<StateType>::notifyObservers() {
    for (auto &ob : observers)
        ob->notify(*this);
}

template <typename StateType>
void Subject<StateType>::setState(StateType newS) {
    state = newS;
}

template <typename StateType>
StateType Subject<StateType>::getState() const {
    return state;
}
#endif
