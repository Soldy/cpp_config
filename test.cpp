#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include <map>
#include "doctest.h"
#include "config.hpp"


std::map<
    std::string, 
    std::string
> conf{{"two", "2"}, {"three", "3"}, {"four", "4"}};

std::map<
    std::string, 
    std::string
> conf_export;



TEST_CASE("simple test") {
    SUBCASE("preparation") {
        cppConfig::set("one", "1");
    };
    SUBCASE("get string") {
        CHECK(cppConfig::get("one") == "1");
    };

    SUBCASE("get string with default") {
        CHECK(cppConfig::get("one", "2") == "1");
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
    SUBCASE("import") {
        cppConfig::map(conf);
    };
    SUBCASE("get import two") {
        CHECK(cppConfig::get("two") == "2");
    };
    SUBCASE("get import three") {
        CHECK(cppConfig::get("three") == "3");
    };
    SUBCASE("get import four") {
        CHECK(cppConfig::get("four") == "4");
    };
    SUBCASE("export") {
        conf_export = cppConfig::map();
    };
    SUBCASE("get export one") {
        CHECK(conf_export["one"] == "1");
    };
    SUBCASE("get export two") {
        CHECK(conf_export["two"] == "2");
    };
    SUBCASE("get export three") {
        CHECK(conf_export["three"] == "3");
    };
    SUBCASE("get export four") {
        CHECK(conf_export["four"] == "4");
    };


};
