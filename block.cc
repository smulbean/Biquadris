#include "block.h"
#include <iostream>

BlockDecorator::BlockDecorator(Board* base) : base(base) {}
BlockDecorator::~BlockDecorator() { delete base; }
