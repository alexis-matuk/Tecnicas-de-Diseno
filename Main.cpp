//
//  Main.cpp
//  Tarea_3_Tecnicas_Diseno
//
//  Created by alexis matuk on 10/8/15.
//  Copyright (c) 2015 alexis matuk. All rights reserved.
//

#include "Parejas.h"
#include "Parrafos.h"
#include "Subsequences.h"
#include "Camionero.h"

int main(int argc, const char * argv[])
{
    int choice;
    bool done = false;
    while(!done)
    {
        std::cout << "===== Técnicas de Diseño ===== " << std::endl;
        std::cout << "1) Problema del camionero" << std::endl;
        std::cout << "2) División en párrafos" << std::endl;
        std::cout << "3) Subsecuencia máxima" << std::endl;
        std::cout << "4) Parejas estables" << std::endl;
        std::cout << "5) Salir" << std::endl;
        std::cout << "Elige una opción: ";
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intenta otra vez: ";
        }
        switch(choice)
        {
            case 1:{
                camionero();
                break;}
            case 2:{
                parrafos();
                break;}
            case 3:{
                subsequences();
                break;}
            case 4:{
                parejas();
                break;}
            case 5:{
                std::cout << "Adios!" << std::endl;
                done = true;
                break;}
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}