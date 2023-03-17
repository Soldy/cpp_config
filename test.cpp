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
    SUBCASE("get string with default") {
        CHECK(cppConfig::get("one", 2) == "1");
    };
    SUBCASE("get string not exist") {
        CHECK(cppConfig::get("not exist") == "");
    };
    SUBCASE("get string not exist with default") {
        CHECK(cppConfig::get("not exist", "2") == "2");
    };
    SUBCASE("get integer") {
        CHECK(cppConfig::getInt("one") == 1);
    };
    SUBCASE("get integer with default") {
        CHECK(cppConfig::getInt("one", 2) == 1);
    };
    SUBCASE("get integer not exist") {
        CHECK(cppConfig::getInt("not exist") == 0);
    };
    SUBCASE("get integer not exist with default") {
        CHECK(cppConfig::getInt("not exist", 2) == 2);
    };
};
