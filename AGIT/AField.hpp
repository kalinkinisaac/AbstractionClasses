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
class AbstractIntPoint{
    const int default_x = 0, default_y = 0;
public:
    int x, y;
    AbstractIntPoint();
    AbstractIntPoint(int x, int y);
    void Set(int x, int y);
    std::string ToString();
};
/*Parse section*/
unsigned int GetDec(char input);//Convert one symbol to decimal
unsigned int AlphToDec(const std::string& to_convert);//Convert str to dec
bool InputValidChecker(const std::string& input);
AbstractIntPoint Parse(const std::string& to_parse);

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
    int At(AbstractIntPoint point);
    void Fill();
    void Fill(int background);
    int GetWidth();
    int GetHeight();
    std::string ToString();
};
#endif /* AField_hpp */
