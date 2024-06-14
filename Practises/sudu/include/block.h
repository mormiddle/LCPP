#pragma once

#include "common.h"

//数独网格类
class CBlock 
{
        static const int MAX_COUNT = 9;

    public:
        CBlock();
        bool isVisied() const;
        bool isFull() const;
        void print() const;

    private:
        int _count;
        point_value_t* _number[MAX_COUNT];
};