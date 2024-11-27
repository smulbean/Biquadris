#include "subject.h"
#include "observer.h"
#include <vector>

void Subject::attach(std::shared_ptr<Observer> o) {
    observers.emplace_back(o);  // Add the shared pointer to the observers list
}

void Subject::detach(std::shared_ptr<Observer> o) {
    // Remove the observer from the list if it matches
    observers.erase(std::remove_if(observers.begin(), observers.end(),
        [&o](const std::shared_ptr<Observer>& observer) { return observer == o; }), 
        observers.end());
}

void Subject::notifyObservers() {
    for (const auto& o : observers) {
        o->notify();  // Notify each observer
    }
}

