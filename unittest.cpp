#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lab3.h"


TEST_CASE("Test Array") {
    int array[] = {0};
    int array1[] = {-1, 1, 1, -1};
    int array2[] = {1,-1,-1,1};
    int array3[] = {-1,-1,1,1,1,1,1};

    SUBCASE("Check Depth"){
        CHECK(lowest_depth(array, 0) == 0);
        CHECK(lowest_depth(array1, 4) == 0);
	CHECK(lowest_depth(array2, 4) == 2);
	CHECK(lowest_depth(array3, 7) == 1);

    }

}
