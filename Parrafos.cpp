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
float bPrime(int maxLength, int totalWordsLength, int i, int j)
{
    if(j-1 == 0) return 0.0;
    return (float)((float)(maxLength - totalWordsLength)/(float)(j-i));
}

int main(int argc, const char * argv[])
{
    std::vector<std::string> words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    std::vector<size_t>wordLengths;
    std::string space = " ";
    for (auto i : words)
        wordLengths.push_back(i.length());
    std::vector<std::string> currentLine;
    std::vector<int> spacePositions;
    int maxLength = 20;
    float idealSize = 1.0;
    int numberOfSpaces = 0;
    int totalWordsLength = 0;
    int startingWord = 0;
    int currentWord = -1;
    for(int i=0; i<words.size(); i++)
    {
        currentLine.push_back(words[i]);//agregar la palabra y ver que pasaría después
        currentLine.push_back(space);
        numberOfSpaces++;
        totalWordsLength += wordLengths[i];
        currentWord++;
        spacePositions.push_back(currentWord+1);
        if(totalWordsLength+numberOfSpaces*idealSize > maxLength)//Si la línea se pasa del máximo
        {
            numberOfSpaces--;
            currentLine.pop_back();
            //Si la palabra ya no cabe hay dos opciones.
            //Primero se quita la palabra para manejar la línea
            if(numberOfSpaces*idealSize >= words[i].length())//Si cabe quitando todos los espacios
            {
                //Si cabe, se tiene la opción de reducir la línea o pasar la palabra a la siguiente
                float costReduce = 0;
                float costExtend = 0;
                /*Reducir*/
                costReduce = fabs(bPrime(maxLength, totalWordsLength, startingWord, currentWord) - (float)idealSize)*(currentWord-startingWord);
                currentLine.pop_back();
                totalWordsLength -= wordLengths[i];
                currentWord--;
                /*Extender*/
                costExtend = fabs(bPrime(maxLength, totalWordsLength, startingWord, currentWord) - (float)idealSize)*(currentWord-startingWord);
                if(costReduce < costExtend)
                {
                    //Reducir cuesta menos
                    int neededSize = words[i].length();
                    int aux=0;
                    while(neededSize != 0)
                    {
                        currentLine.erase(currentLine.begin() + spacePositions[aux]);
                        //currentLine[spacePositions[aux]].pop_back();
                        aux++;
                        neededSize--;
                    }
                    currentLine.push_back(words[i]);
                    totalWordsLength+=wordLengths[i];
                    //Saltar a la siguiente línea
                    for(auto i : currentLine)
                        std::cout << i << std::flush;
                    currentLine.clear();
                    startingWord = currentWord;
                    numberOfSpaces = 0;
                    totalWordsLength = 0;
                    std::cout << std::endl;
                }
                else
                {
                    //Extender cuesta menos
                    //Saltar a la siguiente línea
                    for(auto i : currentLine)
                        std::cout << i << std::flush;
                    currentLine.clear();
                    currentLine.push_back(words[i]);
                    startingWord = currentWord;
                    numberOfSpaces = 0;
                    totalWordsLength = 0;
                    std::cout << std::endl;
                }
            }
            else//Si no cabe, se debe pasar a la siguiente línea
            {
                totalWordsLength-=wordLengths[i];
                currentLine.pop_back();
                for(auto i : currentLine)
                    std::cout << i << std::flush;
                currentLine.clear();
                currentLine.push_back(words[i]);
                currentLine.push_back(space);
                startingWord = currentWord;
                numberOfSpaces = 0;
                totalWordsLength = wordLengths[i];
                numberOfSpaces++;
                std::cout << std::endl;
            }
        }
        else if(totalWordsLength+numberOfSpaces*idealSize == maxLength)//Las palabras caben exactamente en la línea
        {
            
        }
    }
    for(auto i : currentLine)
        std::cout << i << std::flush;
    return 0;
}