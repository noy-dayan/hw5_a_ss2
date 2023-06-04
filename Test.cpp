#include "doctest.h"
#include "sources/MagicalContainer.hpp"

// constructors
TEST_CASE("Default constructor tests") {
    SUBCASE("MagicalContainer"){
        CHECK_NOTHROW(ariel::MagicalContainer container);
    }
    /*
    SUBCASE("AscendingIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::AscendingIterator iter1);
    }
    SUBCASE("SideCrossIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::SideCrossIterator iter2);
    }
    SUBCASE("PrimeIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::PrimeIterator iter3);
    }
    */
}

TEST_CASE("Constructor tests") {
    ariel::MagicalContainer container;

    SUBCASE("AscendingIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::AscendingIterator iter1(container));
    }
    SUBCASE("SideCrossIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::SideCrossIterator iter2(container));
    }
    SUBCASE("PrimeIterator"){
        CHECK_NOTHROW(ariel::MagicalContainer::PrimeIterator iter3(container));
    }
    
}

TEST_CASE("Copy constructor tests") {
    ariel::MagicalContainer container;

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator tmp1(container);
        CHECK_NOTHROW(ariel::MagicalContainer::AscendingIterator iter1(tmp1));
    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator tmp2(container);
        CHECK_NOTHROW(ariel::MagicalContainer::SideCrossIterator iter2(tmp2));
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator tmp3(container);
        CHECK_NOTHROW(ariel::MagicalContainer::PrimeIterator iter3(tmp3));
    }
    
}

// addElement
TEST_CASE("MagicalContainer addElement") {
    ariel::MagicalContainer container;
    
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
}

TEST_CASE("AscendingIterator addElement") {
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(3);
    container.addElement(1);

    ariel::MagicalContainer::AscendingIterator iter(container);
    CHECK(*iter == 1);
    ++iter;
    CHECK(*iter == 3);
    ++iter;
    CHECK(*iter == 5);
    ++iter;
}

TEST_CASE("SideCrossIterator addElement") {
    ariel::MagicalContainer container;

    container.addElement(4);
    container.addElement(2);
    container.addElement(6);

    ariel::MagicalContainer::SideCrossIterator iter(container);
    CHECK(*iter == 2);
    ++iter;
    CHECK(*iter == 4);
    ++iter;
    CHECK(*iter == 6);
    ++iter;
}

TEST_CASE("PrimeIterator addElement") {
    ariel::MagicalContainer container;

    container.addElement(7);
    container.addElement(4);
    container.addElement(13);

    ariel::MagicalContainer::PrimeIterator iter(container);
    CHECK(*iter == 7);
    ++iter;
    CHECK(*iter == 13);
    ++iter;
    
}

// removeElement
TEST_CASE("MagicalContainer removeElement") {
    ariel::MagicalContainer container;

    SUBCASE("Removing a single element") {
        container.addElement(10);
        container.removeElement(10);
        CHECK(container.size() == 0);
    }

    SUBCASE("Removing multiple elements") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.removeElement(2);
        container.removeElement(1);

        CHECK(container.size() == 1);
    }
}

TEST_CASE("AscendingIterator removeElement") {
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(3);
    container.addElement(1);
    container.removeElement(3);

    ariel::MagicalContainer::AscendingIterator iter(container);
    CHECK(*iter == 1);
    ++iter;
    CHECK(*iter == 5);
    ++iter;
}

TEST_CASE("SideCrossIterator removeElement") {
    ariel::MagicalContainer container;

    container.addElement(4);
    container.addElement(2);
    container.addElement(6);
    container.removeElement(2);

    ariel::MagicalContainer::SideCrossIterator iter(container);
    CHECK(*iter == 4);
    ++iter;
    CHECK(*iter == 6);
    ++iter;
}

TEST_CASE("PrimeIterator removeElement") {
    ariel::MagicalContainer container;

    container.addElement(7);
    container.addElement(4);
    container.addElement(13);
    container.removeElement(13);

    ariel::MagicalContainer::PrimeIterator iter(container);
    CHECK(*iter == 7);
    ++iter;
    
}

// = operator
TEST_CASE("= operator tests") {
    ariel::MagicalContainer container;

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator tmp1(container);
        CHECK_NOTHROW(ariel::MagicalContainer::AscendingIterator iter1 = tmp1);
        ariel::MagicalContainer::AscendingIterator iter1 = tmp1;
        CHECK(iter1 == tmp1);
    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator tmp2(container);
        CHECK_NOTHROW(ariel::MagicalContainer::SideCrossIterator iter2 = tmp2);
        ariel::MagicalContainer::SideCrossIterator iter2 = tmp2;
        CHECK(iter2 == tmp2);
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator tmp3(container);
        CHECK_NOTHROW(ariel::MagicalContainer::PrimeIterator iter3 = tmp3);
        ariel::MagicalContainer::PrimeIterator iter3 = tmp3;
        CHECK(iter3 == tmp3);
    }
    
}

// == operator
TEST_CASE("== operator tests") {
    ariel::MagicalContainer container;

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator tmp1(container);
        ariel::MagicalContainer::AscendingIterator iter1 = tmp1;
        ariel::MagicalContainer::AscendingIterator iter2(tmp1);

        CHECK(iter1 == tmp1);
        CHECK(iter2 == tmp1);

    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator tmp2(container);
        ariel::MagicalContainer::SideCrossIterator iter3 = tmp2;
        ariel::MagicalContainer::SideCrossIterator iter4(tmp2);

        CHECK(iter3 == tmp2);
        CHECK(iter4 == tmp2);

    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator tmp3(container);
        ariel::MagicalContainer::PrimeIterator iter5 = tmp3;
        ariel::MagicalContainer::PrimeIterator iter6(tmp3);

        CHECK(iter5 == tmp3);
        CHECK(iter6 == tmp3);    
    }
    
}

// != operator
TEST_CASE("!= operator tests") {
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(3);
    container.addElement(1);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        ariel::MagicalContainer::AscendingIterator iter2(container);

        CHECK_FALSE(iter1 != iter2);
        ++iter1;
        CHECK(iter1 != iter2);

    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter3(container);
        ariel::MagicalContainer::SideCrossIterator iter4(container);

        CHECK_FALSE(iter3 != iter4);
        ++iter3;
        CHECK(iter3 != iter4);
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter5(container);
        ariel::MagicalContainer::PrimeIterator iter6(container);

        CHECK_FALSE(iter5 != iter6);
        ++iter5;
        CHECK(iter5 != iter6);  
    }
}

// > operator
TEST_CASE("> operator tests") {
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(3);
    container.addElement(1);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        ariel::MagicalContainer::AscendingIterator iter2(container);

        CHECK_FALSE(iter1 > iter2);
        ++iter1;
        CHECK(iter1 > iter2);

    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter3(container);
        ariel::MagicalContainer::SideCrossIterator iter4(container);

        CHECK_FALSE(iter3 > iter4);
        ++iter3;
        CHECK(iter3 > iter4);
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter5(container);
        ariel::MagicalContainer::PrimeIterator iter6(container);

        CHECK_FALSE(iter5 > iter6);
        ++iter5;
        CHECK(iter5 > iter6);  
    }
}

// < operator
TEST_CASE("< operator tests") {
    ariel::MagicalContainer container;

    container.addElement(5);
    container.addElement(3);
    container.addElement(1);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        ariel::MagicalContainer::AscendingIterator iter2(container);

        CHECK(iter1 < iter2);
        ++iter1;
        CHECK_FALSE(iter1 < iter2);

    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter3(container);
        ariel::MagicalContainer::SideCrossIterator iter4(container);

        CHECK(iter3 < iter4);
        ++iter3;
        CHECK_FALSE(iter3 < iter4);
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter5(container);
        ariel::MagicalContainer::PrimeIterator iter6(container);

        CHECK(iter5 < iter6);
        ++iter5;
        CHECK_FALSE(iter5 < iter6);  
    }
}

// * operator
TEST_CASE("* operator tests") {
    ariel::MagicalContainer container;
    
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        CHECK(typeid(*iter1) == typeid(int));
    }
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter2(container);
        CHECK(typeid(*iter2) == typeid(int));
    }
    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter3(container);
        CHECK(typeid(*iter3) == typeid(int));
    }
    
}

// ++ operator
TEST_CASE("++ operator tests") {
    ariel::MagicalContainer container;
    
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        CHECK_NOTHROW(++iter1);
        ++iter1;
        CHECK(*iter1 != 3);
    }

    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter2(container);
        CHECK_NOTHROW(++iter2);
        ++iter2;
        CHECK(*iter2 != 3);
    }

    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter3(container);
        CHECK_NOTHROW(++iter3);
        ++iter3;
        CHECK(*iter3 != 3);
    }
    
}

// begin()
TEST_CASE("begin tests") {
    ariel::MagicalContainer container;
    
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        CHECK(iter1.begin() == iter1);
        ++iter1;
        CHECK_FALSE(iter1.begin() == iter1);

    }
    
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter2(container);
        CHECK(iter2.begin() == iter2);
        ++iter2;
        CHECK_FALSE(iter2.begin() == iter2);
    }

    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::PrimeIterator iter3(container);
        CHECK(*iter3.begin() == 3);
        ++iter3;
        CHECK_FALSE(iter3.begin() == iter3);

    }
    
}

// end()
TEST_CASE("end tests") {
    ariel::MagicalContainer container;
    
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);

    SUBCASE("AscendingIterator"){
        ariel::MagicalContainer::AscendingIterator iter1(container);
        ariel::MagicalContainer::AscendingIterator iter2(container);
        CHECK_FALSE(iter2.end() == iter1);
        ++iter1;
        ++iter1;
        ++iter1;
        CHECK(iter2.end() == iter1);
    }
    
    SUBCASE("SideCrossIterator"){
        ariel::MagicalContainer::SideCrossIterator iter3(container);
        ariel::MagicalContainer::SideCrossIterator iter4(container);
        CHECK_FALSE(iter4.end() == iter3);
        ++iter3;
        ++iter3;
        ++iter3;

        CHECK(iter4.end() == iter3);
    }

    SUBCASE("PrimeIterator"){
        ariel::MagicalContainer::SideCrossIterator iter5(container);
        ariel::MagicalContainer::SideCrossIterator iter6(container);
        CHECK_FALSE(iter6.end() == iter5);
        ++iter5;
        ++iter5;
        ++iter5;
        CHECK(iter6.end() == iter5);

    }
    
}