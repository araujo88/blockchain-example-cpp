#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <iostream>
#include <cstdint>
#include <sstream>

class Block
{
public:
    std::string previous_hash;

    Block(uint32_t index_in, const std::string &data_in);

    std::string getHash();

    void mineBlock(uint32_t difficulty);

private:
    uint32_t index;
    int64_t nonce;
    std::string data;
    std::string hash;
    time_t timestamp;

    std::string calculateHash() const;
};

#endif