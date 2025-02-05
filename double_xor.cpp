#include <iostream>
#include <bitset>
#include <vector>
#include "gorilla_compression.h" 

int main(int argc, char *argv[])
{
    const int nInput = 30; 
    double a[nInput] = { 0.0, 0.1, 0.80566,  0.80566,  0.80567,  0.8061,  12, 24, 15, 15.5, 14.0, 14.0, 16.0, 16.5, 18, 18, 18, 18, 20, 18, 14.0, 16.0, 16.0, 16.5, 18, 18, 18, 18, 20, 18,  }; 

    std::vector<bool> bitvector = gorilla::compress(a, nInput); // updated call

    std::cout << "Length : " << bitvector.size() << "\n";
    for (std::vector<bool>::iterator it = bitvector.begin() ; it != bitvector.end(); ++it)
        std::cout << ( *it ? "1" : "0");
    std::cout << "\n";

    std::vector<double> output = gorilla::decompress(bitvector); // updated call

    // ouput points that don't match
    for (int i = 0; i < nInput; i++)
    {
        if(a[i] != output[i]) std::cout  << "Mismatch " << "i : " << i << " : " << a[i] << " = " << output[i] << "\n"; 
    }

    std::cout << "Compression factor: " << (double)(output.size() * sizeof(double) * 8 ) / bitvector.size() << "\n";
    std::cout << "Bits per double: " << (double)bitvector.size() / (double)nInput << "\n";
    return 0; 
}