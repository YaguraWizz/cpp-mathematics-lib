#include <iostream>
#include <iomanip>
//#include "cpp-combinatorics-lib.h"
#include "benchmark_test.h"



template<typename T>
std::ostream& operator<<(std::ostream& oss, const std::vector<T>& elements) {
    oss << "{ ";

    auto it = elements.begin();
    if (it != elements.end()) {
        oss << *it;
        ++it;
    }

    for (; it != elements.end(); ++it) {
        oss << ", " << *it;
    }

    oss << " }";
    return oss;
}

template <typename T>
void assertEqual(const T& result, const T& expected, const std::string& operation) {
    if (result != expected) {
        std::cerr << "Assertion failed: " << operation << " failed\n";
        std::cerr << "Expected: " << expected << "\nResult:   " << result << "\n";
        exit(1); // or handle error differently
    }
}

template <typename T>
void assertComparison(T condition, const std::string& operation) {
    if (!condition) {
        std::cerr << "Assertion failed: " << operation << " failed\n";
        std::cerr << "Expected: " << "true" << "\n";
        exit(1); // or handle error differently
    }
}


static void test_UnsignedInteger() {
    {
       
        UnsignedInteger value1(std::string(6, '9'));
        UnsignedInteger value2(std::string(6, '7'));
        assertEqual((value1 + value2).toLong(), 1777776ULL,  "test sum");
        assertEqual((value1 - value2).toLong(), 222222ULL,   "test subtract");
        assertEqual((value1 * value2).toLong(), 777776222223ULL, "test multiply");
        assertEqual((value1 / value2).toLong(), 1ULL,   "test divide");
        assertEqual((value1 % value2).toLong(), 222222ULL,   "test remainder");
        
        const int width = 20;
        std::cout << std::setw(width) << std::left << "test sum:" << value1 << " + " << value2 << " = " << std::right << (value1 + value2).toLong() << "\n";
        std::cout << std::setw(width) << std::left << "test subtract:" << value1 << " - " << value2 << " = "  << std::right << (value1 - value2).toLong() << "\n";
        std::cout << std::setw(width) << std::left << "test multiply:" << value1 << " * " << value2 << " = "  << std::right << (value1 * value2).toLong() << "\n";
        std::cout << std::setw(width) << std::left << "test divide:" << value1 << " / " << value2 << " = "  << std::right << (value1 / value2).toLong() << "\n";
        std::cout << std::setw(width) << std::left << "test remainder:" << value1 << " % " << value2 << " = "  << std::right << (value1 % value2).toLong() << "\n\n\n";
    }

    {
        UnsignedInteger value1(std::string(6, '9'));
        UnsignedInteger value2(std::string(6, '7'));
        assertComparison(!(value1 == value2),   "test operator ==");
        assertComparison(value1 != value2,      "test operator !=");
        assertComparison(!(value1 <= value2), "test operator <=");
        assertComparison(value1 >= value2,   "test operator >=");
        assertComparison(value1 > value2,    "test operator >");
        assertComparison(!(value1 < value2),       "test operator <");

        const int width = 20;
        std::cout << std::boolalpha;
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " == " << value2 << " = " << (value1 == value2) << "\n";
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " != " << value2 << " = " << (value1 != value2) << "\n";
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " <= " << value2 << " = " << (value1 <= value2) << "\n";
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " >= " << value2 << " = " << (value1 >= value2) << "\n";
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " >  " << value2 << " = " << (value1 > value2) << "\n";
        std::cout << std::setw(width) << std::left << "test operator" << value1 << " <  " << value2 << " = " << (value1 < value2) << "\n\n\n";
        std::cout << std::noboolalpha;
       
    }

    {
        {
            UnsignedInteger value(std::string(1, '9'));
            std::cout << "factorinal value: " << value << "! = " << factorial(value) << "\n";
        }
        
    }
}
static void test_Index() {
    {
        unsigned long long index = 20;
        Index Idx1(index);
        assertEqual(Idx1.get_fs_index(), std::vector<unsigned int> { 3, 1, 0, 0 }, "test factorial system");
        assertEqual(Idx1.get_index().toLong(), index, "test index");

        std::cout << "Idx1 fs: " << Idx1.get_fs_index() << " dec: " << Idx1.get_index()<<"\n";
    }

    {
        UnsignedInteger index = 2020;
        Index Idx1(index);
        assertEqual(Idx1.get_fs_index(), std::vector<unsigned int> { 2, 4, 4, 0, 2, 0, 0}, "test factorial system");
        assertEqual(Idx1.get_index(), index, "test index");
        
        std::cout << "Idx2 fs: " << Idx1.get_fs_index() << " dec: " << Idx1.get_index() << "\n";
    }
}
static void test_Permutations() {
    {
        std::vector<int> int_v = { 1,2,3,4,5,6,7,8,9,10 };
        Index Idx(20);
        Permutations<int> permVec(int_v);
        std::vector<int> permutedVec = permVec.FindPermutations(Idx);
        assertEqual(permutedVec, std::vector<int>{ 1, 2, 3, 4, 5, 6, 10, 8, 7, 9 }, "test find permutations int to index");
        
        std::cout << "\n\nIdx1 fs: " << Idx.get_fs_index() << " dec: " << Idx.get_index() << "\n";
        std::cout << "Permutations: " << permutedVec  << "\n";
    }

    {
        std::vector<char> char_v{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
        Index Idx(20);
        Permutations<char> permVec(char_v);
        std::vector<char> permutedVec = permVec.FindPermutations(Idx);
        assertEqual(permutedVec, std::vector<char> {  'a', 'b', 'c', 'd', 'e', 'f', 'j', 'h', 'g', 'i' }, "test find permutations char to index");
        
        std::cout << "Idx1 fs: " << Idx.get_fs_index() << " dec: " << Idx.get_index() << "\n";
        std::cout << "Permutations: " << permutedVec << "\n";
    }

}
static void test_Combinations() {
    // Test with integers
    {
        std::vector<int> int_v = { 1, 2, 3, 4 };
        unsigned long long r = 2;
        Combinations<int> comb(int_v, r);
        std::vector<std::vector<int>> result = comb.generateCombinations();
        assertEqual(result, std::vector<std::vector<int>> { 
            { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 3, 4 }
            
        }, "Test combinations of integers");

        std::cout << "\n\nOrigen: " << int_v << " r: "<< r << "\n";
        std::cout << "Combinations: " << result << "\n";
    }


    // Test with characters
    {
        std::vector<char> char_v = { 'a', 'b', 'c', 'd' };
        unsigned long long r = 2;
        Combinations<char> comb(char_v, r);
        std::vector<std::vector<char>> result = comb.generateCombinations();
        assertEqual(result, std::vector<std::vector<char>>{
            { 'a', 'b' }, { 'a', 'c' }, { 'a', 'd' },
            { 'b', 'c' }, { 'b', 'd' }, { 'c', 'd' }
        }, "Test combinations of characters");

        std::cout << "Origen: " << char_v << " r: " << r << "\n";
        std::cout << "Combinations: " << result << "\n";
    }
}
static void test_Arrangements() {
    // Test with integers
    {
        std::vector<int> int_v = { 1, 2, 3 };
        unsigned long long r = 2;
        Arrangements<int> comb(int_v, r);
        std::vector<std::vector<int>> result = comb.generateArrangements();
        assertEqual(result, std::vector<std::vector<int>>{
            { 1, 2 }, { 1, 3 }, { 2, 1 }, 
            { 2, 3 }, { 3, 1 }, { 3, 2 }
        }, "Test arrangements of integers");

        std::cout << "\n\nOrigen: " << int_v << " r: " << r << "\n";
        std::cout << "Combinations: " << result << "\n";
    }

    // Test with characters
    {
        std::vector<char> char_v = { 'a', 'b', 'c' };
        unsigned long long r = 2;
        Arrangements<char> comb(char_v, r);
        std::vector<std::vector<char>> result = comb.generateArrangements();
        assertEqual(result, std::vector<std::vector<char>>{
            { 'a', 'b' }, { 'a', 'c' }, { 'b', 'a' },
            { 'b', 'c' }, { 'c', 'a' }, { 'c', 'b' }
        }, "Test arrangements of characters");

        std::cout << "Origen: " << char_v << " r: " << r << "\n";
        std::cout << "Combinations: " << result << "\n";
    }
}


int main() {
    try {

       benchmark_test_UnsignedInteger();
       test_UnsignedInteger();
       test_Index();
       test_Permutations();
       test_Combinations();
       test_Arrangements();
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}


