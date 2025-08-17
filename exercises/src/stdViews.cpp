#include "stdViews.hpp"

void SpanExamples::example(void) {
    std::array<int, 4> arr = {0, 1, 2 ,3};
    std::span<int> arr_span(arr);
    
    auto last2 = arr_span.last(2);
    for(auto n : last2)
        std::cout << n << std::endl;
}

void StrviewExamples::example(void) {
    std::string str = "This is an example";
    std::string_view str_view = str;

    printf("string view first element address: %p\n", &str_view[0]);
    printf("string first element address: %p\n", str.data());
}

void ViewExamples::example(void){
    std::array<int, 4> arr = {0, 1, 2 ,3};
    
    auto checkOdd = [](int n) { return n % 2 != 0; };

    auto odds = arr | std::views::filter(checkOdd);

    for(auto n : odds){
        std::cout << n << std::endl;
    }
}