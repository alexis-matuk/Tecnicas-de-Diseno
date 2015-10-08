////
////  Subsequences.cpp
////  Tarea_3_Tecnicas_Diseno
////
////  Created by alexis matuk on 10/4/15.
////  Copyright (c) 2015 alexis matuk. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <stack>
///*
// la función recursiva sería: 
// calcSubset(0,j) = 0;
// calcSubset(i,0) = 0;
// calcSubset(i,j) = 1 +  calcSubset(i-1,j-1) si x[i] == y[j];
// por ejemplo 101 y 111
// A == A, entonces la longitud del subset más largo sería 1 +  calcSubset(1,1), pero B!=C
// Si x[i] != y[j]
// calcSubset(i,j) = max(calcSubset(i-1,j), calcSubset(i,j-1))
// dado que B!=C, se calcularía max(calcSubset(0,1), calcSubset(1,0)), que al final de la llamada recursiva evaluaría a 1
// Por lo tanto el subset más grande es de longitud 2
// 
// El método de programación dinámica usa estas mismas condiciones pero las guarda en una matriz de m x n
// para evitar repetir cálculos innecesarios y solamente hacer accesos a memoria en tiempo constante
// 
// Complejidad de generar la matriz es de O(nxm)
// Complejidad de recorrer la matriz por el camino obtenido es O(n+m)
// */
//void printSubsequenceMatrix(std::vector<std::vector<int>> subsequenceMatrix)
//{
//    for(int i=0; i<subsequenceMatrix.size(); i++)
//    {
//        for(int j=0; j<subsequenceMatrix[0].size(); j++)
//        {
//            std::cout << subsequenceMatrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//template <class T>
//std::vector<std::vector<int>> buildSubsequenceMatrix(std::vector<T> firstSet, std::vector<T> secondSet)
//{
//    std::vector<std::vector<int>> subsequenceMatrix(firstSet.size()+1, std::vector<int>(secondSet.size()+1));
//    for(int i=1; i<=firstSet.size(); i++)
//    {
//        for(int j=1; j<=secondSet.size(); j++)
//        {
//            if(firstSet[i-1] == secondSet[j-1])
//            {
//                subsequenceMatrix[i][j] = 1 + subsequenceMatrix[i-1][j-1];
//            }
//            else
//            {
//                subsequenceMatrix[i][j] = std::max(subsequenceMatrix[i-1][j], subsequenceMatrix[i][j-1]);
//            }
//        }
//    }
//    return subsequenceMatrix;
//}
//
//template <class T>
//void getLargestSubsequence(std::vector<std::vector<int>> subsequenceMatrix, std::vector<T> firstSet, std::vector<T> secondSet)
//{
//    size_t currentRow = firstSet.size();
//    size_t currentColumn = secondSet.size();
//    std::stack<T> resultStack;
//    while(currentRow != 0 && currentColumn != 0)
//    {
//        if(subsequenceMatrix[currentRow-1][currentColumn] == subsequenceMatrix[currentRow][currentColumn-1])
//        {
//            resultStack.push(firstSet[currentRow-1]);
//            currentRow--;
//            currentColumn--;
//        }
//        else
//        {
//            if(subsequenceMatrix[currentRow-1][currentColumn] > subsequenceMatrix[currentRow][currentColumn-1])
//                currentRow--;
//            else
//                currentColumn--;
//        }
//    }
//    while(!resultStack.empty())
//    {
//        std::cout << resultStack.top() << " " << std::flush;
//        resultStack.pop();
//    }
//    std::cout << std::endl;
//}
//
//int main(int argc, const char * argv[])
//{
////    std::vector<char> first = {'a','b','a','c','e','b'};
////    std::vector<char> second = {'a','d','b','a','v','c','e','b'};
////    std::vector<char> first = {'1','0','0','1','0','1','0','1'};
////    std::vector<char> second = {'0','1','0','1','1','0','1','1','0'};
//    std::vector<char> first = {'g','a','c','a','c','g','g','g','a','t','t','a','g'};
//    std::vector<char> second = {'g','g','a','c','a','t','c','g','g','a','a','t','a','g'};
//    
//    std::vector<std::vector<int>> matrix = buildSubsequenceMatrix(first, second);
//    printSubsequenceMatrix(matrix);
//    std::cout << "La subsecuencia más larga es: ";
//    getLargestSubsequence(matrix, first, second);
//    
//    return 0;
//}