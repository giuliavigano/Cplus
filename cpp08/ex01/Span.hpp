#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>
#include <algorithm>
#include <exception>

class  Span {
public:
	Span(unsigned int N);
	Span(const Span& value);
	Span&	operator=(const Span& val);
	~Span();

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class SpanTooShort : std::exception {
	public:
		virtual const char* what() const throw() {
			return "There are not enought element in the span";
		}
 	};

	class SpanAlreadyFull : std::exception {
	public:
		virtual const char* what() const throw() {
			return "There are altredy maxSize numbers in the span!";
		}
	};
	
	class NotAValidSizeOfElements : std::exception {
	public:
		virtual const char* what() const throw() {
			return "Parameter passed to the constructor must be valid, NOT a negative number!";
		}
	};

	template<typename It>
	void	addNumbers(It first, It last) {
		for (; first != last; ++first) {
			if (_span.size() >= _maxSize)
				throw SpanAlreadyFull();
			_span.push_back(*first);
		}
	}

	unsigned int	verifyN(unsigned int n);

private:
	unsigned int		_maxSize;
	std::vector<int>	_span;
};


#endif