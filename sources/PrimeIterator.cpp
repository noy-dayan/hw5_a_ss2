#include "MagicalContainer.hpp"

namespace ariel {
    // PrimeIterator
    // Constructors & Destructors
    MagicalContainer::PrimeIterator::PrimeIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, int index) : container(container), index(index){}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}


    // Operators
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        this->container = other.container;
        this->index = other.index;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        //return this->index == other.index;
        return false;

    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        //return *PrimeIterator(this->container, this->index);
        return 0;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++this->index;
        return *this;
    }

    // Begin & End
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return PrimeIterator(this->container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(this->container, this->container.size());
    }

    // IsPrime
    bool MagicalContainer::PrimeIterator::isPrime(int number) const {
        return false;
    }
}