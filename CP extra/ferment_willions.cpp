// Little Fermet's Theorum states that if 
// p is a primr number, then 
// for any integer a 
// the number a^p-a is an 
// integral multiple of p

// a^p = a(mod p)
// a^(p-1) = 1(mod p)
// a^(p-2) = a^-1(mod p) ..... gives modulo inverse of a number
// nCr %p = (fact[n]* moduleinv(fact[r])%p * modulinverse(fact[n-r])%p)%p
// only if p>n

// Wilson's Theorum states that a positive integer n>1 is a prime if and only if 
// (n-1)! === -1(mod n) , or
// (n-1)! === n-1(mod n)
// 100! = 101k - 1
// 25! % 29 = [(-1)*inverse(28,29)*inverse(27,29)*inverse(26,29)] %29

#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

int main()
{	CLEAR;





    return 0;
}