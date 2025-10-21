#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : origin(), deq(), vec(), timeDeque(), timeVector(), winnersDeque(), losersDeque(), losersVector(), winnersVector() {}

PmergeMe::PmergeMe(const PmergeMe& value) : origin(value.origin), deq(value.deq), vec(value.vec), timeDeque(value.timeDeque), timeVector(value.timeVector), winnersDeque(value.winnersDeque), losersDeque(value.losersDeque), losersVector(value.losersVector), winnersVector(value.winnersVector) {}

PmergeMe&   PmergeMe::operator=(const PmergeMe& val) {
    if (this != &val) {
        this->origin = val.origin;
        this->deq = val.deq;
        this->vec = val.vec;
        this->timeDeque = val.timeDeque;
        this->timeVector = val.timeVector;
        this->winnersDeque = val.winnersDeque;
        this->losersDeque = val.losersDeque;
        this->losersVector = val.losersVector;
        this->winnersVector = val.winnersVector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::displayTime() {
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
}

void    PmergeMe::displayBefore() {
    std::cout << "Before: ";
    for (size_t i = 0; i < origin.size(); ++i) {
        if (i == origin.size() - 1)
            std::cout << origin[i] << std::endl;
        else
            std::cout << origin[i] << " ";
    }
}

void    PmergeMe::displayAfter() {
    std::cout << "After: ";
     if (vec.empty()) {
        for (size_t i = 0; i < deq.size(); ++i) {
            if (i == deq.size() - 1)
                std::cout << deq[i] << std::endl;
            else
                std::cout << deq[i] << " ";
        }
    } else {
         for (size_t i = 0; i < vec.size(); ++i) {
            if (i == vec.size() - 1)
                std::cout << vec[i] << std::endl;
            else
                std::cout << vec[i] << " ";
        }
    }
}

std::vector<size_t>		PmergeMe::generateJacobsthalSequence(size_t maxElements) {
	std::vector<size_t>	jacobsthal;

	if (maxElements == 0)
		return jacobsthal;
	jacobsthal.push_back(1);
	if (maxElements == 1)
		return jacobsthal;
	jacobsthal.push_back(1);
	if (maxElements == 2)
		return jacobsthal;
	size_t	previous1 = 1;
	size_t	previous2 = 1;
	while (true) {
		size_t	next = previous1 + 2 * previous2;
		if (next > maxElements)
			break;
		jacobsthal.push_back(next);
		previous2 = previous1;
		previous1 = next;
	}
	return jacobsthal;
}

std::vector<size_t>		PmergeMe::generateInsertionOrder(size_t count) {
	std::vector<size_t>	order;

	if (count == 0)
		return order;
	std::vector<size_t>	jacobsthal = generateJacobsthalSequence(count);

	std::vector<bool>	inserted(count, false);

	if (count > 0) {
		order.push_back(0);
		inserted[0] = true;
	}
	for (size_t i = 1; i < jacobsthal.size(); ++i) {
		size_t	jacobsCurrent = jacobsthal[i];
		size_t	jacobsPrevious = jacobsthal[i - 1];
		if (jacobsCurrent >= count)
			jacobsCurrent = count - 1;
		for(size_t j = jacobsCurrent; j > jacobsPrevious; --j) {
			if (j < count && !inserted[j]) {
				order.push_back(j);
				inserted[j] = true;
			}
		}
	}
	for (size_t i = 0; i < count; ++i) {
		if (!inserted[i])
			order.push_back(i);
	}
	return order;
}

bool    PmergeMe::isValidNumber(const std::string& value) {
    if (value.empty())
        return false;
    if (value[0] == '-' || value[0] == '+')
       return false;
    for (size_t i = 0; i < value.length(); ++i) {
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
    clock_t start = clock();
    for (size_t i = 0; i < origin.size(); ++i)
        deq.push_back(origin[i]);
    fordJohnsonSortDeque();
    clock_t end = clock();
    timeDeque = ((double) end - start) / CLOCKS_PER_SEC * 1000.0;
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
    clock_t start = clock();
    for (size_t i = 0; i < origin.size(); ++i)
        vec.push_back(origin[i]);
    fordJohnsonSortVector();
    clock_t end = clock();    
    timeVector = ((double) end - start) / CLOCKS_PER_SEC * 1000.0;
}