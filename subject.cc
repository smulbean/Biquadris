#include "subject.h"
#include "observer.h"
#include <vector>

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o); 
}

void Subject::detach(std::shared_ptr<Observer> o) {
    observers.erase(std::remove_if(observers.begin(), observers.end(),
        [&o](const std::shared_ptr<Observer>& observer) { return observer == o; }), 
        observers.end());
}

void Subject::notifyObservers() {
    for (const auto& o : observers) {
        o->notify(); 
    }
}


