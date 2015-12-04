//
//  main.cpp
//  foo namespace
//
//  Created by Bradyn Poulsen on 2/24/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include <iostream>
#include "bar.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Bar a;
    
    std::cout << a.foo() << std::endl;
    std::cout << a.foo(1) << std::endl;
    
    return 0;
}
