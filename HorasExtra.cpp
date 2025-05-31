#include "HorasExtra.h"
// ConstructorAdd commentMore actions
HorasExtra::HorasExtra(HorasExtra* base) : base(base) {}

// Destructor
HorasExtra::~HorasExtra() {
    if (base) delete base;
}