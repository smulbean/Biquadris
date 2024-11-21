#include "block.h"
#include <iostream>

Block::Block(Board* base) : base(base) {}
Block::~Block() { delete base; }
