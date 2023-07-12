#include <vector>

class Span{
public:
	Span(unsigned int N);
	Span(const Span &rhs);
	~Span();

	Span &operator=(const Span &rhs);

	void addNumber(int number);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();

	void printContainer();

	const std::vector<int>::iterator getBegin();
	const std::vector<int>::iterator getEnd();

	class MaxSize : public std::exception{
		const char *what() const throw();
	};

	class NoSpan : public std::exception{
		const char *what() const throw();
	};
private:
	Span();
	unsigned int size_;
	std::vector<int> vector_;
};