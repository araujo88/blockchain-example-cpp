#include "../include/blockchain.hpp"

Blockchain::Blockchain()
{
    this->chain.emplace_back(Block(0, "Genesis BLock"));
    this->difficulty = 6;
}

Blockchain::Blockchain(uint32_t difficulty)
{
    this->chain.emplace_back(Block(0, "Genesis BLock"));
    this->difficulty = difficulty;
}

void Blockchain::addBlock(Block new_block)
{
    new_block.previous_hash = getLastBlock().getHash();
    new_block.mineBlock(this->difficulty);
    this->chain.push_back(new_block);
}

Block Blockchain::getLastBlock() const
{
    return this->chain.back();
}