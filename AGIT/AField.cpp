//
//  AField.cpp
//  Abstractions
//
//  Created by Исаак Калинкин  on 28.05.16.
//  Copyright © 2016 fourteam. All rights reserved.
//

#include "AField.hpp"
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




