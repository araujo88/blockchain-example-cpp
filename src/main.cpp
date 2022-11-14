#include "../include/blockchain.hpp"

int main(int argc, char *argv[])
{
    Blockchain test_chain;
    if (argc == 1)
    {
        test_chain = Blockchain();
    }
    else if (argc > 1)
    {
        uint32_t difficulty = atoi(argv[1]);
        test_chain = Blockchain(difficulty);
    }

    std::cout << "Mining block 1 ..." << std::endl;
    test_chain.addBlock(Block(1, "Block 1 test data"));

    std::cout << "Mining block 2 ..." << std::endl;
    test_chain.addBlock(Block(2, "Block 2 test data"));

    std::cout << "Mining block 3 ..." << std::endl;
    test_chain.addBlock(Block(3, "Block 3 test data"));

    return 0;
}