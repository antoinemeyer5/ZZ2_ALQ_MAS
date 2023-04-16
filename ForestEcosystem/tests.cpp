#include <sstream>
#include <cstring>
#include "catch.hpp"
#include "Carpenter.hpp"

TEST_CASE("Carpenter") {
    REQUIRE( Carpenter().getSleep() == 100      );
    REQUIRE( Carpenter().getState() == waiting  );
}
