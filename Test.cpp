#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>


using namespace ariel;
using namespace std;


ifstream units_file{"units.txt"};




TEST_CASE("bools operators "){
    NumberWithUnits::read_units(units_file);

    CHECK_LT(NumberWithUnits{3.5, "km"}  , NumberWithUnits{5000, "m"});
    CHECK_GT(NumberWithUnits{7000, "m"}, NumberWithUnits{6.7, "km"});
    CHECK_NE(NumberWithUnits{10, "km"}  , NumberWithUnits{9999, "m"});
    CHECK_NE(NumberWithUnits{9999, "m"}, NumberWithUnits{10, "km"});
    CHECK_LT(NumberWithUnits{199, "cm"} , NumberWithUnits{1000, "m"});
    CHECK_GT(NumberWithUnits{1000, "m"}, NumberWithUnits{199, "cm"});
    CHECK_NE(NumberWithUnits{770, "cm"} , NumberWithUnits{2040, "m"});
    CHECK_NE(NumberWithUnits{2021, "m"}, NumberWithUnits{21, "cm"});
    CHECK_EQ(NumberWithUnits{1500, "cm"}, NumberWithUnits{15, "m"});
    CHECK_EQ(NumberWithUnits{7.5, "m"}, NumberWithUnits{750, "cm"});

}

TEST_CASE("Multiplication"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits x{1.2, "km"};
    CHECK((x*0.5) == NumberWithUnits{0.6, "km"});
    
    CHECK((x*=2.5) == NumberWithUnits{3, "km"});
    CHECK(x == NumberWithUnits{3, "km"});
}
TEST_CASE("Adding operators check"){
    NumberWithUnits::read_units(units_file);

    NumberWithUnits x{7.5, "km"};
    NumberWithUnits y{1313, "m"};
    
    CHECK_EQ(x+y , NumberWithUnits{8.813, "km"});
    CHECK_EQ(y+x , NumberWithUnits{8813, "m"});
    
}

TEST_CASE("Throw exception check"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits n1{2, "km"};
    NumberWithUnits n2{2500, "cm"};
    NumberWithUnits n3{2500, "kg"};
    CHECK_NOTHROW(  n1+n2);
    CHECK_THROWS(n1+n3);
}
TEST_CASE("--and ++"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits x{42424, "cm"};
    CHECK(x++ == NumberWithUnits{42424, "cm"});
    CHECK(x == NumberWithUnits{42425, "cm"});
    CHECK(++x == NumberWithUnits{42426, "cm"});
    CHECK(x == NumberWithUnits{42426, "cm"});
    CHECK(x-- == NumberWithUnits{42426, "cm"});
    CHECK(x == NumberWithUnits{42425, "cm"});
    CHECK(--x == NumberWithUnits{42424, "cm"});
    CHECK(x == NumberWithUnits{42424, "cm"});
}
