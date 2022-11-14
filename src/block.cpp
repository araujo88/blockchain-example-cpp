#include "block.hpp"
#include "../include/sha256.hpp"

Block::Block(uint32_t index_in, const std::string &data_in)
{
    this->index = index_in;
    this->data = data_in;
    this->nonce = -1;
    this->timestamp = time(nullptr);
}

std::string Block::getHash()
{
    return this->hash;
}

void Block::mineBlock(uint32_t difficulty)
{
    char cstr[difficulty + 1];

    for (uint32_t i = 0; i < difficulty; i++)
    {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    std::string str(cstr);

    do
    {
        this->nonce++;
        this->hash = calculateHash();
    } while (this->hash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << this->hash << std::endl;
}

inline std::string Block::calculateHash() const
{
    std::stringstream ss;
    ss << this->index << this->timestamp << this->data << this->nonce << this->previous_hash;

    return sha256(ss.str());
}