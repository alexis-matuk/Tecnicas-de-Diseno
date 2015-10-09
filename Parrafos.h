//
//  Parrafos.h
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/8/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//
/*
 
 La técnica utilizada para este algoritmo es de un algoritmo ávido
 En cada punto se checa si la línea actual se pasa del tamaño máximo por línea, si se pasa se debe tomar una decisión local, que es reducir la línea actual o ampliar la línea y pasar la siguiente palabra a la siguiente línea. La opción que se va a escoger es la que tenga el menor costo, dada la función cost()
 
 La complejidad del algoritmo es O(n) ya que se va a tener que recorrer todo el arreglo de palabras
 
 */

#ifndef Tarea_3_Tecnicas_Diseno_Parrafos_h
#define Tarea_3_Tecnicas_Diseno_Parrafos_h

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
float cost(float bPrime, float b, int j, int i, int offset)
{
    return (fabs(bPrime-b)*(j-i-offset));
}

void parrafos()
{
    std::vector<std::string> words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    std::vector<float> lengths;
    std::vector<std::string> line;
    float maxLength=10;
    float idealSize=1;
    float totalWordsLength=0;
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
            totalWordsLength=0;
        }
        
        totalWordsLength+=lengths[j];
        lineLen=totalWordsLength + ((j-i)*idealSize);
        if(lineLen>maxLength){
            sobra=lineLen-maxLength;
            bReduce = idealSize-(sobra/(j-i));
            bAmplia = idealSize+ (maxLength-((totalWordsLength-lengths[j])+(idealSize*(j-i-1))))/(j-i-1);
            
            if(cost(bAmplia,idealSize,j,i,1)>cost(bReduce,idealSize,j,i,0) && bReduce > 0)
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

#endif
