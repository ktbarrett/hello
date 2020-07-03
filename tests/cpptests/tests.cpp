#include <catch2/catch.hpp>
#include "hello/hello.hpp"


TEST_CASE("Tests")
{
    REQUIRE( hello::hello() == "Hello, World!" );
    REQUIRE( hello::hello("Dad") == "Hello, Dad!");

    REQUIRE( hello::return_answer_to_life() == 42 );
}
