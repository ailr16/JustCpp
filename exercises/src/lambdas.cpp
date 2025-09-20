#include "lambdas.hpp"

void LambdasExamples::example(void) {
    /* 
      Syntax:
      [capture-clause] (parameters) -> return-type { 
        definition...
      }
      capture clauses:
        -& -> capture all external variables by reference
        -= -> capture all external variables by value
        -a,&b -> a by value and b by reference
    */

    std::vector<int> v1;
    std::vector<int> v2;

    auto byRef = [&] (int m) {
        v1.push_back(m);
        v2.push_back(m);
    };

    byRef(4);

    auto byVal = [=] () {
        std::cout << v1[0] << " " << v2[0] << std::endl;
    };

    byVal();

    std::vector<int> data = {0, 1, 2, 3, 4, 5};
    std::for_each(data.begin(), data.end(), [data](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

}

void LambdasExamples::example2(void) {
    std::vector<int> data = {5, 1, 878, 3, 32};

    std::sort(data.begin(), data.end(), [](const int& a, const int& b){
        return a > b;
    });

    for(int x : data)
        std::cout << x << " ";
    std::cout << std::endl;
}