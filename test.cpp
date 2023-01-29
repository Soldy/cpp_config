#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "config.hpp"


TEST_CASE("simple test") {
    SUBCASE("preparation") {
        cppConfig::set("one", "1");
    };
    SUBCASE("get string") {
        CHECK(cppConfig::get("one") == "1");
    };
    SUBCASE("get integer") {
        CHECK(cppConfig::getInt("one") == 1);
    };
};
