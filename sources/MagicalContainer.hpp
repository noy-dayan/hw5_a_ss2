#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

#include <iostream>
#include <vector>
#include <algorithm>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> container;

    public:
        MagicalContainer(){}
        void addElement(int number);
        void removeElement(int number);
        size_t size() const;

        // Iterator classes
        class AscendingIterator {
        private:
            MagicalContainer& container;
            std::vector<int> sortedElements;
            int index;
            AscendingIterator(MagicalContainer& container, int index);

        public:
            AscendingIterator();
            AscendingIterator(MagicalContainer& container);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator();
            AscendingIterator& operator=(const AscendingIterator& other);

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();

            AscendingIterator begin() const;
            AscendingIterator end() const;
        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            std::vector<int> crossOrderedElements;
            int index;
            SideCrossIterator(MagicalContainer& container, int index);

        public:            
            SideCrossIterator();
            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator();
            SideCrossIterator& operator=(const SideCrossIterator& other);

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();

            SideCrossIterator begin() const;
            SideCrossIterator end() const;
        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            std::vector<int> primeElements;
            int index;
            PrimeIterator(MagicalContainer& container, int index);
            bool isPrime(int number) const;

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator();
            PrimeIterator& operator=(const PrimeIterator& other);

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();

            PrimeIterator begin() const;
            PrimeIterator end() const;

        };
    };
}

#endif // MAGICALCONTAINER_H
