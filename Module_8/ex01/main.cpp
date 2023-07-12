#include <iostream>
#include <iomanip>
#include "Span.hpp"

int main()
{
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try{
      Span sp = Span(10);
      Span sptwo = Span(10);
      sp.addNumber(1);
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      sp.addNumber(12);
      sp.addNumber(13);
      sp.addNumber(13);
      sp.addNumber(13);
      sptwo.addNumber(sp.getBegin(), sp.getEnd());
      sptwo.printContainer();
      std::cout << "Longest span " << sptwo.longestSpan() << std::endl;
      std::cout << "Shortest span " << sptwo.shortestSpan() << std::endl;
      sptwo.addNumber(15);
    } catch(std::exception &exception){
      std::cout << exception.what() << std::endl;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try{
      Span sp = Span(2);
      sp.addNumber(1);
      sp.addNumber(1);
      sp.longestSpan();
    } catch(std::exception &exception){
      std::cout << exception.what() << std::endl;
    }
  }
   std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  return 0;
}