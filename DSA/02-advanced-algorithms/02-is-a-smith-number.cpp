#include <iostream>

const int MAX = 100;
uint64_t primeFactorsArr[100];
size_t count;

void FactorizeBy( uint64_t& num, uint64_t factor )
{
    while ( num % factor == 0 )
    {
        primeFactorsArr[ count++ ] = factor;
        num /= factor;
    }
}


void PrimeFactorization2( uint64_t num )
{
    count = 0;
    uint64_t div = 2;
    FactorizeBy( num, div );
    
    for ( div = 3; div * div <= num; div += 2 )
    {
        FactorizeBy( num, div );
    }
    
    if ( num > 1 )
    {
        primeFactorsArr[ count++ ] = num;
    }
}


size_t digitsSum( uint64_t num )
{
    size_t result = 0;
    while ( num > 0 )
    {
        result += num % 10;
        num /= 10;
    }
    return result;
}


bool IsASmithNumber( uint64_t num )
{
    size_t  numDigitsSum     = digitsSum( num );
    size_t  factorsDigitsSum = 0;

    PrimeFactorization2( num );

    for ( size_t i = 0; i < count; i++ )
    {
        factorsDigitsSum += digitsSum( primeFactorsArr[ i ] );
    }
    
    return numDigitsSum == factorsDigitsSum;
}


int main()
{
    uint64_t inputNum;
    std::cout << "Enter a whole positive number: ";
    std::cin >> inputNum;
    std::cout << inputNum << " is " << (IsASmithNumber( inputNum ) ? "" : "not ") << "a Smith number.\n";

    return 0;
}
