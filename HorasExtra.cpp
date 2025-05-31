#include "HorasExtra.h"

// Constructor
HorasExtra::HorasExtra(HorasExtra* base) : base(base) {}

// Destructor
HorasExtra::~HorasExtra() {
    if (base) delete base;
}
