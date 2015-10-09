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

float cost(float bPrime, float b, int j, int i, int offset)
{
    return (fabs(bPrime-b)*(j-i-offset));
}

#include <iostream>
#include <vector>
#include <math.h>

int main(int argc, const char * argv[]) {
    std::vector<std::string> words = {"The", "quick", "brown", "fox", "has", "over", "the", "lazy", "og"};
    std::vector<float> lengths;
    std::vector<std::string> line;
    float maxLength=20;
    float idealSize=1;
    float wordLength=0;
    float lineLen=0;
    float sobra;
    int i=0;
    int j;
    bool finishedLine=true;
    float bAmplia;
    float bReduce;
    
    for(auto i : words)
        lengths.push_back(i.length());
    
    for(j=0; j<words.size(); j++){
        if(finishedLine){
            i=j;
            finishedLine = false;
            line.clear();
            wordLength=0;
        }
        
        wordLength+=lengths[j];
        lineLen=wordLength + ((j-i)*idealSize);
        if(lineLen>maxLength){
            sobra=lineLen-maxLength;
            bReduce = idealSize-(sobra/(j-i));
            bAmplia = idealSize+ (maxLength-((wordLength-lengths[j])+(idealSize*(j-i-1))))/(j-i-1);
            
            if(cost(bAmplia,idealSize,j,i,1)>cost(bAmplia,idealSize,j,i,0) && bReduce > 0)
            {
                line.push_back(words[j]);
                for(auto v : line)
                    std::cout<<v<<" ";
                std::cout<<"| Space size: " << bReduce;
                std::cout<<std::endl;
                finishedLine=true;
            }
            else
            {
                for(auto v : line)
                    std::cout<<v<<" ";
                std::cout<<"| Space size: " << bAmplia;
                std::cout<<std::endl;
                j--;
                finishedLine=true;
            }
        }
        line.push_back(words[j]);
    }
    if(!line.empty())
    {
        for(auto v : line)
            std::cout<<v<<" ";
    }
    std::cout<<"| Space size: " << idealSize;
    std::cout<<std::endl;
}