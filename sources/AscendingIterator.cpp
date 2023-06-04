#include "MagicalContainer.hpp"

namespace ariel {
    // AscendingIterator
    // Constructors & Destructors
    MagicalContainer::AscendingIterator::AscendingIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, int index) : container(container), index(index){}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), index(other.index) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        this->container = other.container;
        this->index = other.index;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        //return this->index == other.index;
        return false;

    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return 0;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        this->index++;
        return *this;
    }

    // Begin & End
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(this->container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(this->container, this->container.size());
    }
}