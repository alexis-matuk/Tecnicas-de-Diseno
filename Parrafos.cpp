//
//  Parrafos.cpp
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/5/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

// Checar que el coste esté bien calculado
// Probar con más casos
// Imprimir la palabra al final del for, no toda la línea

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
    std::vector<std::string> words = {"The", " ", "quick", " ", "brown", " ", "fox", " ", "jumps", " ", "over", " ", "the", " ", "lazy", " ", "dog"};
    std::vector<size_t>wordLengths;
    std::string space = " ";
    for (auto i : words)
        wordLengths.push_back(i.length());
    std::vector<std::string> currentLine;
    std::vector<int> spacePositions;
    int maxLength = 20;
    float idealSize = 1;
    int numberOfSpaces = 0;
    int totalWordsLength = 0;
    int startingWord = 0;
    int currentWord = -1;
    int currLinePos = -1;
    for(int i=0; i<words.size(); i++)
    {
        currentLine.push_back(words[i]);//agregar la palabra y ver que pasaría después
        currLinePos++;
        if(words[i] == " ")
        {
            numberOfSpaces++;
            spacePositions.push_back(currentWord);
        }
        else
        {
            totalWordsLength += wordLengths[i];
            currentWord++;
        }
        if(totalWordsLength+(numberOfSpaces*idealSize) > maxLength)//Si la línea se pasa del máximo
        {
            //numberOfSpaces--;
            //currentLine.pop_back();
            //Si la palabra ya no cabe hay dos opciones.
            //Primero se quita la palabra para manejar la línea
            if((numberOfSpaces*idealSize) >= words[i].length())//Si cabe quitando todos los espacios
            {
                //Si cabe, se tiene la opción de reducir la línea o pasar la palabra a la siguiente
                float costReduce = 0;
                float costExtend = 0;
                /*Reducir*/
                costReduce = fabs(bPrime(maxLength, totalWordsLength, startingWord, currentWord) - (float)idealSize)*(currentWord-startingWord);
                if(words[i] == " ")
                {
                    numberOfSpaces--;
                    currentLine.pop_back();
                    
                }
                else
                {
                    currentLine.pop_back();
                    totalWordsLength -= wordLengths[i];
                    currentWord--;
                }
                /*Extender*/
                costExtend = fabs(bPrime(maxLength, totalWordsLength, startingWord, currentWord) - (float)idealSize)*(currentWord-startingWord);
                if(costReduce < costExtend)//CHECAR ESTA FUNCIÓN COMPLETA
                {
                    //Reducir cuesta menos
                    int neededSize = words[i].length();
                    int aux=0;
                    while(neededSize > 0)
                    {
                        currentLine.erase(currentLine.begin() + spacePositions[aux]);
                        //currentLine[spacePositions[aux]].pop_back();
                        aux++;
                        neededSize-=idealSize;
                    }
                    currentLine.push_back(words[i]);
                    if(words[i] == " ")
                        numberOfSpaces++;
                    else
                        totalWordsLength+=wordLengths[i];
                    //Saltar a la siguiente línea
                    currentLine.clear();
                    startingWord = currentWord;
                    numberOfSpaces = 0;
                    totalWordsLength = 0;
                    std::cout << std::endl;
                }
                else//CHECAR ESTE PRINT
                {
                    //Extender cuesta menos
                    //Saltar a la siguiente línea
                    currentLine.push_back(words[i]);
                    if(words[i] == " ")
                        numberOfSpaces++;
                    else
                        totalWordsLength+=wordLengths[i];
                    //Saltar a la siguiente línea
                    currentLine.clear();
                    startingWord = currentWord;
                    numberOfSpaces = 0;
                    totalWordsLength = 0;
                    std::cout << std::endl;
                }
            }
            else//Si no cabe, se debe pasar a la siguiente línea
                //CHECAR ESTA CONDICIÓN
            {
                currentLine.push_back(words[i]);
                if(words[i] == " ")
                    numberOfSpaces++;
                else
                    totalWordsLength+=wordLengths[i];
                //Saltar a la siguiente línea
                currentLine.clear();
                startingWord = currentWord;
                numberOfSpaces = 0;
                totalWordsLength = 0;
                std::cout << std::endl;
            }
        }
        else if(totalWordsLength+numberOfSpaces*idealSize == maxLength)//Las palabras caben exactamente en la línea
        {
            
        }
        std::cout << currentLine[currLinePos] << std::flush;
    }
    return 0;
}
