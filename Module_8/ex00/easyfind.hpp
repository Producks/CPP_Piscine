#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int value) {
  return find(container.begin(), container.end(), value);
}

template <typename T> bool duplicate(T &container, int value) {
  if (easyfind(container, value) != container.end())
    return true;
  else
    return false;
}

class InvalidInput : public std::exception{
public:
	const char *what() const throw() { return "Invalid input"; }
};