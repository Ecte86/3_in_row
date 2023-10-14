#include "../include/utilities.hpp"
#include <opp/iostream.h>
#include <opp/string.h>
#include <assert.h>
using namespace opp;

void msg_assert(bool condition, string message) {
    if (!condition) {
        cout << message << endl;
        assert(condition);
    }
}