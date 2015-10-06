//
//  Parrafos.cpp
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
float bPrime(int maxLength,int totalWordsLength, int i, int j)
{
    if(i-j == 0) return 0.0;
    return (float)(maxLength - totalWordsLength)/(float)(j-i);
}

int main(int argc, const char * argv[])
{
    std::vector<std::string> words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    std::vector<size_t>wordLengths;
    std::string space = " ";
    for (auto i : words)
        wordLengths.push_back(i.length());
    std::vector<std::string> currentLine;
    int maxLength = 20;
    int idealSize = 1;
    int numberOfSpaces = 0;
    int totalWordsLength = 0;
    int startingWord = 0;
    int currentWord = 0;
    for(int i=0; i<words.size(); i++)
    {
        currentLine.push_back(words[i]);//agregar la palabra y ver que pasaría después
        totalWordsLength += wordLengths[i];
        currentWord++;
        if(totalWordsLength+numberOfSpaces > maxLength)//Si la línea se pasa del máximo
        {
            currentLine.pop_back();//Quitar esa palabra y hacer operaciones
            totalWordsLength -= wordLengths[i];
            for(auto i : currentLine)
                std::cout << i;
            std::cout << std::endl;
            float bP = bPrime(maxLength, totalWordsLength, startingWord, currentWord);
            std::cout << "b prime is " << bP << std::endl;
        }
        else
        {
            currentLine.push_back(space);
            for(int i=0; i<idealSize; i++)
                numberOfSpaces++;
        }
    }
    return 0;
}
