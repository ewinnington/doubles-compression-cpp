#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{

    std::cout << argc << "\n"; 
    for(int i = 0; i < argc; i++)
    {
        std::cout << i << " : " << argv[i] << "\n";
    }

    double a = 12; 
    double b = 24; 

    uint64_t au = *(uint64_t*)&a;
    uint64_t bu = *(uint64_t*)&b;

    std::cout << a << " ptr " << &a << "  " << au << "\n";
    std::cout << b << " ptr " << &b << "  " << bu << "\n";
    std::cout << (au^bu) << "\n";

    std::bitset<64> at(au);
    std::bitset<64> bt(bu);
    std::bitset<64> abtt(au^bu);

    std::cout << at << "\n";
    std::cout << bt << "\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n";
    std::cout << abtt << "\n";


    double v[] = {16,16.5}; 
    au = *(uint64_t*)&v[0];
    bu = *(uint64_t*)&v[1];

    std::cout << v[0] << " ptr " << &v[0] << "  " << au << "\n";
    std::cout << v[1] << " ptr " << &v[1] << "  " << bu << "\n";
    std::cout << (au^bu) << "\n";

    std::bitset<64> vat(au);
    std::bitset<64> vbt(bu);
    std::bitset<64> vabtt(au^bu);

    std::cout << vat << "\n";
    std::cout << vbt << "\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n";
    std::cout << vabtt << "\n";

    std::cout << *(double*)&au << "\n"; 
    std::cout << *(double*)&bu << "\n"; 

    return 0; 
}