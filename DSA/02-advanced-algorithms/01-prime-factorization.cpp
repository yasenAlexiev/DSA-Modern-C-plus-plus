#include <iostream>

void PrintPrimeFactorization( uint64_t num )
{
    for ( uint64_t div = 2; div * div <= num; div++ )
    {
        while ( num % div == 0 )
        {
            std::cout << div << " ";
            num /= div;
        }
    }
    
    if ( num > 1 )
    {
        std::cout << num;
    }
}


void PrintFactorizeBy( uint64_t& num, uint64_t factor )
{
    while ( num % factor == 0 )
    {
        std::cout << factor << " ";
        num /= factor;
    }
}


void PrintPrimeFactorization2( uint64_t num )
{
    uint64_t div = 2;
    PrintFactorizeBy( num, div );
    
    for ( div = 3; div * div <= num; div += 2 )
    {
        PrintFactorizeBy( num, div );
    }
    
    if ( num > 1 )
    {
        std::cout << num;
    }
}


int main()
{
    uint64_t inputNum;
    std::cout << "Enter a whole positive number: ";
    std::cin >> inputNum;
    PrintPrimeFactorization2( inputNum );

    return 0;
}
