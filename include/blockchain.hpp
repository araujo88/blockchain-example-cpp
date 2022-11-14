#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP
#include <cstdint>
#include <vector>
#include "block.hpp"

class Blockchain
{
public:
    Blockchain();
    Blockchain(uint32_t difficulty);

    void addBlock(Block new_block);

private:
    uint32_t difficulty;
    std::vector<Block> chain;

    Block getLastBlock() const;
};

#endif