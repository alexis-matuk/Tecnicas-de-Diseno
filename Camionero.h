//
//  Camionero.h
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/8/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#ifndef Tarea_3_Tecnicas_Diseno_Camionero_h
#define Tarea_3_Tecnicas_Diseno_Camionero_h

/*
 La técnica utilizada para el algoritmo es de un algoritmo ávido
 En cada parada, el camión tiene que determinar si va a llegar a la siguiente parada sin tener que recargar gasolina en la parada actual. La decisión que se tiene que tomar en cada parada es recargar o no recargar, intentando minimizar el número máximo de paradas que realiza el camión
 
 La complejidad del algoritmo es O(n)
 */
#include <iostream>
#include <vector>

std::vector<int> calculateDistance(int maxKilometers, std::vector<int> distances, bool & err)
{
    std::vector<int> solution;//crear conjunto solución
    int j = 0;//elemento x
    int currentKilometers = 0;//condición
    while(j != distances.size()-1)
    {
        //el candidato siempre va a ser la distancia j+1
        if(currentKilometers + distances[j+1] > maxKilometers)//determinar si el candidato es prometedor para el conjunto solución
        {
            if(distances[j+1] > maxKilometers)
            {
                std::vector<int> error;
                std::cerr << "No es posible completar el recorrido con la capacidad máxima del tanque" << std::endl;
                err = true;
                return error;
            }
            solution.push_back(j);
            currentKilometers = 0;
        }
        else//si no es prometedor, saltárselo
        {
            j++;
            currentKilometers+=distances[j];
        }
    }
    return solution;
}

void camionero()
{
    std::vector<int> distances = {0,1000, 1500, 500, 700, 2000, 3000};
    int maxKilometers = 3000;
    bool error = false;
    std::vector<int> solution = calculateDistance(maxKilometers, distances,error);
    if(!solution.empty())
    {
        for(int i=0; i<solution.size(); i++)
            std::cout << "El camión debe recargar gasolina en la parada " << solution[i] << std::endl;
    }
    else if(!error) std::cout << "El camión no tiene que hacer paradas" << std::endl;
}
#endif
