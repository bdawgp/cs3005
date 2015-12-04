//
//  bar.cpp
//  foo namespace
//
//  Created by Bradyn Poulsen on 2/24/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include <stdio.h>
#include "bar.h"

Bar::Bar() : mFoo(5)
{
    
}

int Bar::foo()
{
    return this->mFoo;
}

int Bar::foo(int a)
{
    this->mFoo = a;
    return this->mFoo;
}