class Span{
public:
	Span(unsigned int N);
	Span(const Span &rhs);
	~Span();

	Span &operator=(const Span &rhs);
private:
	Span();
};