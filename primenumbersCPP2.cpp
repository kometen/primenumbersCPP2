//
//  main.cpp
//  primenumbersCPP2
//
//  Created by Claus Guttesen on 14/12/14.
//  Copyright (c) 2014 Claus Guttesen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    clock_t begin = clock();
    
    auto b = 0;
    auto tmp = 0;
    auto is_prime = true;
    
    vector<long int> primes;
    map<int, int> square_primes;
    
    unsigned long int psize = 0;
    
    for (auto a = 2; a < 10000000; ) {
        is_prime = true;
        
        // If primes vector has elements check whether number being validated
        // is divisible or not by each element in vector.
        // If it is divisible is hence not a prime and we can move on to next number.
        
        if ((psize = square_primes.size()) > 0) {
            for (auto z = square_primes.begin(); z != square_primes.end(); z++) {
                if (a % z->second == 0) {
                    is_prime = false;
                }
            }
        }

        if (is_prime) {
            b = static_cast<int>(sqrt(a));
            
            for (auto j = 2; j <= b; j++) {
                if (a % j == 0) {
                    is_prime = false;
                }
            }
            
            if (is_prime) {
                primes.push_back(a);
                tmp = static_cast<int>(sqrt(a));
                if (tmp > 1) {
                    int s_tmp = static_cast<int>(sqrt(tmp));
                    auto is_map_prime = true;
                    for (auto js = 2; js <= s_tmp; js++) {
                        if (tmp % js == 0) {
                            is_map_prime = false;
                        }
                    }
                    if (is_map_prime) {
                        square_primes[tmp] = tmp;
                    }
                }
            }
        }

        // Increment
        if (a % 2 != 0) {
            a += 2;
        } else {
            a++;
        }
        
    }

    psize = primes.size();
    clock_t end = clock();
    double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
    double elements_pr_sec = psize / elapsed_secs;
    
    cout << "Latest prime: " << primes[psize-1] << endl;
    
    cout << "Seconds: " << elapsed_secs << endl;
    cout << "Elements: " << primes.size() << endl;
    cout << "Pr. sec: " << elements_pr_sec << endl;
    cout << "Squareprimes: " << square_primes.size() << endl;

    return 0;
}
