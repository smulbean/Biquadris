#include "block.h"
#include <iostream>
#include <memory>

Block::Block(std::shared_ptr<Board> base) : base(std::move(base)) {}

Block::~Block(){}


