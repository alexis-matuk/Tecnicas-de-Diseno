//
//  Parrafos.cpp
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
float bPrime(int maxLength, int totalWordsLength, int numberOfSpaces)
{
    if(numberOfSpaces == 0) return 0.0;
    return (float)((float)(maxLength - totalWordsLength)/(float)(numberOfSpaces));
}

void reset(std::vector<std::string> &currentLine, int & totalWordsLength, int & numberOfSpaces, int & currentLineLength, int & i)
{
    for(auto i : currentLine)
        std::cout << i << std::flush;
    std::cout << std::endl;
    currentLine.clear();
    totalWordsLength = 0;
    numberOfSpaces = 0;
    currentLineLength = 0;
    if(i%2 == 0)
        i--;
}

int main(int argc, const char * argv[])
{
    std::vector<std::string> words = {"The", " ", "quick", " ", "brown", " ", "fox", " ", "has", " ", "over", " ", "the", " ", "lazy", " ", "og"};
    std::vector<size_t>wordLengths;
    std::string space = " ";
    for (auto i : words)
        wordLengths.push_back(i.length());
    std::vector<std::string> currentLine;
    std::vector<int> spacePositions;
    int maxLength =  20;
    float idealSize = 1;
    int numberOfSpaces = 0;
    int totalWordsLength = 0;
    int currentLineLength = 0;
    int i = 0;
    while( i < words.size())
    {
        if(totalWordsLength+numberOfSpaces*idealSize > maxLength)//Si la línea se pasa del máximo
        {
            if(currentLine[currentLine.size()-1] == " ")//Si se pasa por un espacio
            {
                numberOfSpaces--;//Quitar ese espacio del cálculo
            }
            else
            {
                totalWordsLength-=currentLine[currentLine.size()-1].length();
                currentLine.pop_back();
                i--;
            }
            //Si la palabra ya no cabe hay dos opciones.
            //Primero se quita la palabra para manejar la línea
            if(numberOfSpaces*idealSize >= words[i].length())//Si cabe quitando todos los espacios
            {
                //Si cabe, se tiene la opción de reducir la línea o pasar la palabra a la siguiente
                float costReduce = 0;
                float costExtend = 0;
                /*Reducir*/
                totalWordsLength+=wordLengths[i];
                int initialSpaces = numberOfSpaces;
                int initialWordsLength = totalWordsLength;
                while(totalWordsLength+numberOfSpaces*idealSize > maxLength)
                {
                    numberOfSpaces--;
                }
                costReduce = fabs(bPrime(maxLength, totalWordsLength, numberOfSpaces) - (float)idealSize)*(numberOfSpaces);
                totalWordsLength = initialWordsLength;
                numberOfSpaces = initialSpaces;
                /*Extender*/
                costExtend = fabs(bPrime(maxLength, totalWordsLength, numberOfSpaces) - (float)idealSize)*(numberOfSpaces);
                if(costReduce < costExtend)
                {
                    //Reducir cuesta menos
                    currentLine.push_back(words[i]);
                    //Saltar a la siguiente línea
                    reset(currentLine, totalWordsLength, numberOfSpaces, currentLineLength, i);
                }
                else
                {
                    //Extender cuesta menos
                    //Saltar a la siguiente línea
                    reset(currentLine, totalWordsLength, numberOfSpaces, currentLineLength, i);
                }
            }
            else//Si no cabe, se debe pasar a la siguiente línea
            {
                reset(currentLine, totalWordsLength, numberOfSpaces, currentLineLength, i);
            }
        }
        else if(totalWordsLength+numberOfSpaces*idealSize == maxLength)
        {
            reset(currentLine, totalWordsLength, numberOfSpaces, currentLineLength, i);
        }
        else
        {
            currentLine.push_back(words[i]);//agregar la palabra y ver que pasaría después
            if(words[i] != " ")
                totalWordsLength += wordLengths[i];
            else
                numberOfSpaces++;
        }
        i++;
    }
    if(!currentLine.empty())
    {
        for(auto i : currentLine)
            std::cout << i << std::flush;
        std::cout << std::endl;
    }
    return 0;
}