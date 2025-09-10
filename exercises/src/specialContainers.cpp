#include "specialContainters.hpp"

void PairExamples::example(void){
    std::pair<int, int> p1(1,1);
    std::pair<int, int> p2 = {2,2};
    std::pair<int, int> p3;
    std::pair<int, int> p4;
    std::pair<int, int> p5(1,2);
    std::pair<int, int> p6(2,1);

    p3.first = 3;
    p3.second = 3;

    std::cout << "p1:(" << p1.first << "," << p1.second <<")" << std::endl;
    std::cout << "is p2 equal to p3?:" << (p2 == p3) << std::endl;

    p4 = p3;
    std::cout << "is p4 equal to p3?:" << (p4 == p3) << std::endl;

    std::cout << "is p2 greater than p1?:" << (p2 > p1) << std::endl;
    std::cout << "is p1 greater than p3?:" << (p1 > p3) << std::endl;
    std::cout << "is p5 greater than p1?:" << (p5 > p1) << std::endl;
    std::cout << "is p6 greater than p1?:" << (p6 > p1) << std::endl;
}

void TupleExamples::example(void){
    std::tuple<int, int> t1(1,1);
    std::tuple<int, int, std::string> t2(1,2, "3");
    
    std::cout << "t1:" << std::get<0>(t1) << "," << std::get<1>(t1) << std::endl;
    std::cout << "t2:" << std::get<0>(t2) << "," << std::get<1>(t2) << "," << std::get<2>(t2) << std::endl;
    auto [a, b, c] = t2;
    std::cout << "t2:" << a << "," << b << "," << c << std::endl;
}

std::optional<std::string> OptionalExamples::create(bool b){
    if(b)
        return "cppreference_Example";

    return {};
}

void OptionalExamples::example(void){
    std::optional<std::string> name;

    std::cout << name.value_or("Unknown") << "\n";

    if(!name){
        name = "Angel";
    }
    std::cout << name.value_or("Unknown") << "\n";

    auto returned = OptionalExamples::create(true);
    if(returned.has_value())
        std::cout << returned.value() << std::endl;

    returned = OptionalExamples::create(false);
    if(returned.has_value())
        std::cout << returned.value() << std::endl;

    returned.emplace("1");
}

void VariantExamples::example(void){
    std::variant<int, float, char> v1;
    v1 = 'c';
    if(auto access_variant = std::get_if<int>(&v1)){
        std::cout << "variant stores an integer!" << std::endl;
    }
    else if(auto access_variant = std::get_if<float>(&v1)){
        std::cout << "variant stores a float!" << std::endl;
    }
    else if(auto access_variant = std::get_if<char>(&v1)){
        std::cout << "variant stores a char!" << std::endl;
    }
    else;

    std::cout << "variant index: " << v1.index() << std::endl;
}

void AnyExamples::example(void){
    std::any a = 16.112;

    if(a.has_value())
        std::cout << a.type().name() << std::endl;
    
    a.reset();
    if(a.has_value())
        std::cout << a.type().name() << std::endl;
    
    a.emplace<char>('c');
    if(a.has_value())
        std::cout << a.type().name() << std::endl;
}