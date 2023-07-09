#include <exception>

template <typename T> class Array {
public:
  /* Constructor */
  Array() : array_(NULL), size_(0) {}
  Array(const int &n) {
    if (n < 0)
      throw NegativeArraySize();
		size_ = n;
		array_ = new T[size_];
  }
  Array(const Array &rhs){ *this = rhs; }
  ~Array() {
    if (size_ != 0)
      delete[] array_;
  }

  /* Operator */
  Array &operator=(const Array &rhs) {
		if (this == &rhs)
			return *this;
    // if (array_ != NULL){ // would have been smart if they didn't delete their mirror
		// 	delete[] array_;
		// }
    size_ = rhs.size();
    array_ = new T[size_];
    for (int index = 0; index < size_; index++)
      array_[index] = rhs[index];
    return *this;
  }
  T &operator[](int index) const {
    if (index < 0 || index > (size_ - 1))
      throw OutOfRange();
    return array_[index];
  }

  /* Methods */
  unsigned int size() const { return size_; }

  /* Exception */
  class OutOfRange : public std::exception {
  public:
    virtual const char *what() const throw() { return "Out of range Error"; }
  };
  class NegativeArraySize : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "The size for the array is negative";
    }
  };

private:
  T *array_;
  int size_;
};