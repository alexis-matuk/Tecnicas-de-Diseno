////
////  Camionero.cpp
////  Tarea_3_Tecnicas_Diseno
////
////  Created by alexis matuk on 10/4/15.
////  Copyright (c) 2015 alexis matuk. All rights reserved.
////
///*
// Complejidad del algoritmo es O(n)
// */
//#include <iostream>
//#include <vector>
//
//std::vector<int> calculateDistance(int maxKilometers, std::vector<int> distances)
//{
//    std::vector<int> solution;//crear conjunto solución
//    int j = 0;//elemento x
//    int currentKilometers = 0;//condición
//    while(j != distances.size()-1)
//    {
//        //el candidato siempre va a ser la distancia j+1
//        if(currentKilometers + distances[j+1] > maxKilometers)//determinar si el candidato es prometedor para el conjunto solución
//        {
//            solution.push_back(j);
//            currentKilometers = 0;
//        }
//        else//si no es prometedor, saltárselo
//        {
//            j++;
//            currentKilometers+=distances[j];
//        }
//    }
//    return solution;
//}
//
//int main(int argc, const char * argv[])
//{
//    std::vector<int> distances = {1000, 1500, 500, 700, 2000, 3000};
//    int maxKilometers = 3000;
//    std::vector<int> solution = calculateDistance(maxKilometers, distances);
//    for(int i=0; i<solution.size(); i++)
//    {
//        std::cout << "El camión debe recargar gasolina en la parada " << solution[i]+1 << std::endl;
//    }
//    return 0;
//}