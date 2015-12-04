//
//  main.cpp
//  exponents
//
//  Created by Bradyn Poulsen on 2/12/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "exponent_quiz.h"

int main(int argc, const char * argv[]) {
    
    int *exponents = new int[50];
    generate_exponents(0, 49, exponents);
    
    std::time_t start = std::time(NULL);
    
    int i, misses = 0;
    bool correct;
    char *answer = new char[128];
    for(i = 0; i < 50; i++){
        do {
            std::cout << std::endl << "[" << (i+1) << " of 50] ";
            std::cout << "What is 2^" << exponents[i] << "? ";
            
            std::cin >> answer;
            correct = string_to_number(answer) == power_2(exponents[i]);
            
            if(correct){
                std::cout << "Correct!" << std::endl;
            }else{
                misses++;
                std::cout << "Incorrect... try again" << std::endl;
            }
        } while (!correct);
    }
    
    delete [] answer;
    delete [] exponents;
    
    std::cout << "You are finished with your test!" << std::endl;
    std::cout << "You missed " << misses << " time" << (misses != 1 ? "s." : ".") << std::endl;
    std::cout << "Final score: " << (std::time(NULL) - start + misses*5) << std::endl;
    
    return 0;
}
