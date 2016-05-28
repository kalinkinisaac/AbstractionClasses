//
//  AField.hpp
//  Abstractions
//
//  Created by Исаак Калинкин  on 28.05.16.
//  Copyright © 2016 fourteam. All rights reserved.
//

#ifndef AField_hpp
#define AField_hpp

#include <stdio.h>
#include <iostream> /*for string*/
class AbstractField
{
private:
    const unsigned int default_width = 0, default_height = 0;
    const int default_background = 0;
    unsigned int width, height;
    int** essence;
    void BuildEssence();
public:
    AbstractField();
    AbstractField(int width, int height);
    ~AbstractField();
    int* operator[](int index);
    void Fill();
    void Fill(int background);
    int GetWidth();
    int GetHeight();
    std::string ToString();
};
#endif /* AField_hpp */
