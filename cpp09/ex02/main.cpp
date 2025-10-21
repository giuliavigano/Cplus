#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    PmergeMe    jaco;
	if (jaco.parseInput(argc, argv)) {
        jaco.displayBefore();
        jaco.sortWithDeque();
        jaco.sortWithVector();
        jaco.displayAfter();
        jaco.displayTime();
    }
    return 0;
}