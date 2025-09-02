#include <associativeContainers.hpp>

void SetExamples::example(void) {
    std::set<int> s;

    std::cout << "sizeof:" << sizeof(s) << std::endl;
    std::cout << "size:" << s.size() << std::endl;

    s.insert({1,1,2,3,3,3,4});

    for(auto i = s.begin(); i != s.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    s.insert(499);
    
    for(auto i = s.begin(); i != s.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    s.clear();
    std::string st = "Hello world";
    s.insert(st.begin(), st.end());
    
    std::cout << "String to set of int:" << std::endl;
    for(auto i = s.begin(); i != s.end(); i++)
        printf("%c ", *i);
    std::cout << std::endl;

    std::set<char> sc(st.begin(), st.end());
    std::cout << "String to set of char:" << std::endl;
    for(auto i = s.begin(); i != s.end(); i++)
        std::cout << static_cast<char>(*i) << " ";
    std::cout << std::endl;
}

void MapExamples::example(void) {
    std::map<int, int> m = {
        std::pair<int, int>(44, 1),
        std::pair<int, int>(99, 2),
        std::pair<int, int>(1, 3),
        std::pair<int, int>(16, 4)
    };

    std::cout << "sizeof: " << sizeof(m) << std::endl;
    std::cout << "size: " << m.size() << std::endl;

    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    m.erase(44);

    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    auto ret = m.try_emplace(88);
    std::cout << "Operation status: " << ret.second << std::endl;
    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    ret = m.try_emplace(88);
    std::cout << "Operation status: " << ret.second << std::endl;
    std::cout << "Just accessing try_emplace return: " << ret.first->first << "," << ret.first->second << std::endl;
    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;
}

void USetExamples::example(void) {
    std::unordered_set<int> us;

    std::cout << "sizeof:" << sizeof(us) << std::endl;
    std::cout << "size:" << us.size() << std::endl;

    us.insert({1,1,2,3,3,3,4});

    for(auto i = us.begin(); i != us.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    us.insert(45);
    for(auto i = us.begin(); i != us.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    us.clear();
    std::string st = "Hello world";
    us.insert(st.begin(), st.end());
    
    std::cout << "String to set of int:" << std::endl;
    for(auto i = us.begin(); i != us.end(); i++)
        printf("%c ", *i);
    std::cout << std::endl;

    std::set<char> sc(st.begin(), st.end());
    std::cout << "String to set of char:" << std::endl;
    for(auto i = us.begin(); i != us.end(); i++)
        std::cout << static_cast<char>(*i) << " ";
    std::cout << std::endl;
}

void UMapExamples::example(void) {
    std::map<int, int> m = {
        std::pair<int, int>(44, 1),
        std::pair<int, int>(99, 2),
        std::pair<int, int>(1, 3),
        std::pair<int, int>(16, 4)
    };

    std::cout << "sizeof: " << sizeof(m) << std::endl;
    std::cout << "size: " << m.size() << std::endl;

    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    m.erase(44);

    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    auto ret = m.try_emplace(88);
    std::cout << "Operation status: " << ret.second << std::endl;
    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    ret = m.try_emplace(88);
    std::cout << "Operation status: " << ret.second << std::endl;
    std::cout << "Just accessing try_emplace return: " << ret.first->first << "," << ret.first->second << std::endl;
    for(auto i = m.begin(); i != m.end(); i++)
        std::cout << "(" << i->first << "," << i->second << ") ";
    std::cout << std::endl;

    std::cout << "m[88]=" << m[88] << std::endl;
    m[88] = 512;
    std::cout << "m[88]=" << m[88] << std::endl;
    std::cout << m.at(512) << std::endl;
}