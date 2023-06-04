#include "MagicalContainer.hpp"

namespace ariel {
    // SideCrossIterator
    // Constructors & Destructors
    MagicalContainer::SideCrossIterator::SideCrossIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, int index) : container(container), index(index){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index){}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        this->container = other.container;
        this->index = other.index;
        return *this;
    }
    
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        //return this->index == other.index;
        return false;

    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        //return !(*this == other);
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return 0;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        ++this->index;
        return *this;
    }

    // Begin & End
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(this->container, this->container.size());
    }
}