#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : deq(), vec() {}

PmergeMe::PmergeMe(const PmergeMe& value) : deq(value.deq), vec(value.vec) {}

PmergeMe&   PmergeMe::operator=(const PmergeMe& val) {
    if (this != &val) {
        this->deq = val.deq;
        this->vec = val.vec;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool    PmergeMe::isValidNumber(const std::string& value) {
    size_t i = 0;
    if (value.empty())
        return false;
    if (value[0] == '-' || value[0] == '+')
       return false;
    for (i; i < value.length(); ++i) {
        if (value[i] < '0' || value[i] > '9')
            return false;
    }
    return true;
} 

bool    PmergeMe::parseInput(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Error: bad input." << std::endl;
        return false;
    }
    for (int i = 1; i < argc; ++i) {
        std::stringstream s(argv[i]);
        std::string token;
        while (s >> token) {
            if (!isValidNumber(token)) {
                std::cout << "Error: bad input." << std::endl;
                return false;
            }
            int value = std::atoi(token.c_str());
            origin.push_back(value);
        }
    }
    if (origin.empty()) {
        std::cout << "Error" << std::endl;
        return false;
    }
    return true;
}

void    PmergeMe::pairElementDeque() {
    for (size_t i = 0; i < deq.size(); i += 2) {
        if (i + 1 < deq.size()) {
            int first = deq[i];
            int second = deq[i + 1];
            if (first > second) {
                winnersDeque.push_back(first);
                losersDeque.push_back(second);
            } else {
                winnersDeque.push_back(second);
                losersDeque.push_back(first);
            }
        }
    }
    if (deq.size() % 2 == 1)
        losersDeque.push_back(deq[deq.size() - 1]);
}

void    PmergeMe::recursiveSortElementDeque() {
    if (winnersDeque.size() < 2)
        return;
    std::deque<int> originalDeq = deq;
    std::deque<int> originalWinners = winnersDeque;
    std::deque<int> originalLosers = losersDeque;

    deq = winnersDeque;
    winnersDeque.clear();
    losersDeque.clear();

    fordJohnsonSortDeque();

    winnersDeque = deq;
    deq = originalDeq;
    losersDeque = originalLosers;
}

void    PmergeMe::insertElementDeque() {
    if (losersDeque.empty())
        return;
    std::vector<size_t> order = generateInsertionOrder(losersDeque.size());
    for (size_t i = 0; i < order.size(); ++i) {
        size_t  idx = order[i];
        int elem = losersDeque[idx];
        std::deque<int>::iterator pos = std::upper_bound(winnersDeque.begin(), winnersDeque.end(), elem);
        winnersDeque.insert(pos, elem);
    }
    deq = winnersDeque;
}

void    PmergeMe::fordJohnsonSortDeque() {
    if (deq.size() < 2)
        return;
    pairElementDeque();

    recursiveSortElementDeque();

    insertElementDeque();
}

void    PmergeMe::sortWithDeque() {
    for (size_t i = 0; i < origin.size(); ++i)
        deq.push_back(origin[i]);
    fordJohnsonSortDeque();
}

void    PmergeMe::pairElementVector() {
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            int first = vec[i];
            int second = vec[i + 1];
            if (first > second) {
                winnersVector.push_back(first);
                losersVector.push_back(second);
            } else {
                winnersVector.push_back(second);
                losersVector.push_back(first);
            }
        }
    }
    if (vec.size() % 2 == 1)
        losersVector.push_back(vec[vec.size() - 1]);
}

void    PmergeMe::recursiveSortElementVector() {
    if (winnersVector.size() < 2)
        return;

    std::vector<int>    originalVec = vec;
    std::vector<int>    originalWinners = winnersVector;
    std::vector<int>    originalLosers = losersVector;

    vec = winnersVector;
    winnersVector.clear();
    losersVector.clear();

    fordJohnsonSortVector();

    winnersVector = vec;
    vec = originalVec;
    losersVector = originalLosers;
}

void    PmergeMe::insertElementVector() {
    if (losersVector.empty())
        return;
    std::vector<size_t> order = generateInsertionOrder(losersVector.size());
    for (size_t i = 0; i < order.size(); ++i) {
        size_t idx = order[i];
        int elem = losersVector[idx];
        std::vector<int>::iterator pos = std::upper_bound(winnersVector.begin(), winnersVector.end(), elem);
        winnersVector.insert(pos, elem);
    }
    vec = winnersVector;
}

void    PmergeMe::fordJohnsonSortVector() {
    if (vec.size() < 2)
        return;

    pairElementVector();

    recursiveSortElementVector();

    insertElementVector();
}

void    PmergeMe::sortWithVector() {
    for (size_t i = 0; i < origin.size(); ++i)
        vec.push_back(origin[i]);
    fordJohnsonSortVector();
}