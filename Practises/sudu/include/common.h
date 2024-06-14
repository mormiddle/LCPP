#pragma once

static const unsigned int UNSELECTED = 0;

enum class State : int {
    INITED = 0,
    ERASED,
};

using point_vlaue_t = struct point_value_t {
    int value;
    State state;
};