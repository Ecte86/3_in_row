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

int find(string str, char c) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}