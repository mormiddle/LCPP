#include "block.h"

#include <iostream>

#include "display_symbol.h"

CBlock::CBlock() {}

bool CBlock::isVisied() const {
    return false;
}

bool CBlock::isFull() const {
    return false;
}

void CBlock::print() const {
    std::cout << PIPE << " ";
    
}
