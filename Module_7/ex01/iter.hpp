#include <iostream>

template <typename T>
void iter(T *array, unsigned int length, void func(T &content)) {
  for (unsigned int index = 0; index < length; index++) {
    func(array[index]);
  }
}

template <typename T> void incrementationFunc(T &content) { content++; }

template <typename T> void print(T &content) {
  std::cout << content << " ";
}