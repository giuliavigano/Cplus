#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <ctime>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& value);
    PmergeMe&   operator=(const PmergeMe& val);
    ~PmergeMe();

    bool    parseInput(int argc, char *argv[]);
    void    sortWithDeque();
    void    sortWithVector();
    void    displayTime();
    void    displayAfter();
    void    displayBefore();
    void    fordJohnsonSortDeque();
    void    fordJohnsonSortVector();

private:
    std::vector<int>    origin;
    std::deque<int>     deq;
    std::vector<int>    vec;

    double              timeDeque;
    double              timeVector;

    std::deque<int>     winnersDeque;
    std::deque<int>     losersDeque;
    std::vector<int>    losersVector;
    std::vector<int>    winnersVector;

    void    pairElementDeque();
    void    pairElementVector();
    void    recursiveSortElementDeque();
    void    recursiveSortElementVector();
    void    insertElementDeque();
    void    insertElementVector();

    bool                isValidNumber(const std::string& str);
    std::vector<size_t> generateJacobsthalSequence(size_t maxElements);
    std::vector<size_t> generateInsertionOrder(size_t count);
};

#endif