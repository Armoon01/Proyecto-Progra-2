#pragma once
#include <string>
using namespace std;

class IObjecto {
public:
    virtual string toString() const = 0;
    virtual bool equals(IObjecto*) = 0;
    virtual string getType() const = 0;
};