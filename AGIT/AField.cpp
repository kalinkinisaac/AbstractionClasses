//
//  AField.cpp
//  Abstractions
//
//  Created by Исаак Калинкин  on 28.05.16.
//  Copyright © 2016 fourteam. All rights reserved.
// мде кек лол

#include "AField.hpp"
//=-AbstractIntPoint-=============================
AbstractIntPoint::AbstractIntPoint()
{
    Set(this->default_x, this->default_y);
}
AbstractIntPoint::AbstractIntPoint(int x, int y)
{
    Set(x, y);
}
void AbstractIntPoint::Set(int x, int y)
{
    this->x = x;
    this->y = y;
}
std::string AbstractIntPoint::ToString()
{
    return ("(" + std::to_string(this->x) +
         "," + std::to_string(this->y) + ")");
    
}
//=-Parse-========================================
bool InputValidChecker(const std::string& input)
{
    return true;
}
unsigned int GetDec(char input)
{
    return (toupper(input) - 'A') + 1;
}
unsigned int AlphToDec(const std::string& to_convert)
{
    unsigned int result = 0;
    for(int i = 0; i < to_convert.length(); i++)
        result = result*26 + GetDec(to_convert[i]);
    return result;
}
AbstractIntPoint Parse(const std::string& to_parse)
{
    if(!InputValidChecker(to_parse))
        return *new AbstractIntPoint;
    /*dividing input*/
    std::string digit_part, char_part;
    
    bool tmp = isdigit(to_parse[0]);
    int i = 0;
    while(tmp == isdigit(to_parse[i]))
    {
        i++;
    }
    
    if(tmp)
    {
        digit_part.append(to_parse.begin(), to_parse.begin() + i);
        char_part.append(to_parse.begin() + i, to_parse.end());
    }
    else
    {
        digit_part.append(to_parse.begin() + i, to_parse.end());
        char_part.append(to_parse.begin(), to_parse.begin() + i);
    }
    
    return *new AbstractIntPoint(std::stoi(digit_part),
                                 AlphToDec(char_part));
}
//=-AbstractField-================================
void AbstractField::BuildEssence()
{
    this->essence = new int*[this->height];
    for(int i = 0; i < this->height; i++)
        this->essence[i] = new int[this->width];
}
AbstractField::AbstractField()
{
    this->width = this->default_width;
    this->height = this->default_height;
    BuildEssence();
    this->Fill();
}
AbstractField::AbstractField(int width, int height)
{
    this->width = width;
    this->height = height;
    this->BuildEssence();
    this->Fill();
}
AbstractField::~AbstractField()
{
    for(int i = 0; i < this->height; i++)
        delete [] this->essence[i];
    delete [] this->essence;
}

int* AbstractField::operator[](int index)
{
    return this->essence[index];
}

void AbstractField::Fill()
{
    this->Fill(this->default_background);
}
void AbstractField::Fill(int background)
{
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
            this->essence[i][j] = background;
}

int AbstractField::GetWidth()
{
    return this->width;
}
int AbstractField::GetHeight()
{
    return this->height;
}

std::string AbstractField::ToString()
{
    std::string render = "";
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width; j++)
            render += std::to_string(this->essence[i][j]);
        render += "\n";
    }
    return render;
}




