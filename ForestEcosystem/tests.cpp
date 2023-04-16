#include <sstream>
#include <cstring>
#include "catch.hpp"
#include "Agent.hpp"
#include "Carpenter.hpp"
#include "Lumberjack.hpp"

TEST_CASE("Agent") {
    REQUIRE( Agent().getSleep()         == 100      );
    REQUIRE( Agent().getState()         == waiting  );
    REQUIRE( Agent(working).getState()  == working  );
    Agent a;
    a.decreaseSleep(50);
    REQUIRE( a.getSleep()               == 50       );
    a.increaseSleep(20);
    REQUIRE( a.getSleep()               == 70       );
    Agent b;
    b.increaseSleep(20);
    REQUIRE( b.getSleep()               == 100      );
}

TEST_CASE("Carpenter") {
    REQUIRE( Carpenter().getSleep() == 100      );
    REQUIRE( Carpenter().getState() == waiting  );
}

TEST_CASE("Lumberjack") {
    REQUIRE( Lumberjack().getSleep() == 100      );
    REQUIRE( Lumberjack().getState() == waiting  );
}