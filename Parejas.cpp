////
////  Parejas.cpp
////  Tarea_3_Tecnicas_Diseno
////
////  Created by alexis matuk on 10/7/15.
////  Copyright (c) 2015 alexis matuk. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//
//
//int getWomanNotProposed(int man, std::vector<std::vector<int>> hombresPrefieren, std::vector<std::vector<bool>> proposedToWomen,int &womanProposedTo)
//{
//    for(int i = 0; i < proposedToWomen[man].size(); i++)
//    {
//        if(proposedToWomen[man][i] == false)
//        {
//            womanProposedTo = i;
//            return hombresPrefieren[man][i];
//        }
//    }
//    return -1;
//}
//
//bool existFreeMan(std::vector<bool> freeMen, int & m)
//{
//    int j = 0;
//    for(auto i : freeMen)
//    {
//        if(i == true)
//        {
//            m = j;
//            return true;
//        }
//        j++;
//    }
//    return false;
//}
//
//bool prefersNewMan(int woman, int man, std::vector<std::vector<int>> hombresPrefieren, std::vector<std::vector<int>> mujeresPrefieren,std::vector<int> matchedMen, int oldMan)
//{
//    int oldManPos = 0;
//    for(int i=0; i<mujeresPrefieren[woman].size(); i++)
//    {
//        if(mujeresPrefieren[woman][i] == oldMan)
//            oldManPos = i;
//    }
//    for(int i = 0; i < oldManPos; i++)
//    {
//        if(mujeresPrefieren[woman][i] == man)
//            return true;
//    }
//    return false;
//}
//
//int findOldMan(int woman, std::vector<int> matchedMen, std::vector<int> matchedWomen, std::vector<std::vector<int>> hombresPrefieren)
//{
//    for(int i=0; i<hombresPrefieren.size(); i++)
//    {
//        if(matchedWomen[i] == woman)
//            return matchedMen[i];
//    }
//    return -1;
//}
//
//int findWoman(int woman,std::vector<int> matchedWomen, std::vector<std::vector<int>> hombresPrefieren)
//{
//    for(int i=0; i<hombresPrefieren.size(); i++)
//    {
//        if(matchedWomen[i] == woman)
//            return i;
//    }
//    return -1;
//}
//
//int main(int argc, const char * argv[])
//{
//    std::vector<std::vector<int>> hombresPrefieren = {{2,1,0,3},//M
//                                                        {1,3,0,2},
//                                                        {2,0,3,1},
//                                                        {0,1,2,3}};
//    
//    std::vector<std::vector<int>> mujeresPrefieren = {{0,2,1,3},//H
//                                                        {2,3,1,0},
//                                                        {1,2,3,0},
//                                                        {3,1,0,2}};
//    std::vector<int> matchedMen;
//    std::vector<int> matchedWomen;
//    std::vector<bool> freeWomen(hombresPrefieren.size(), true);
//    std::vector<bool> freeMen(hombresPrefieren.size(), true);
//    std::vector<std::vector<bool>> proposedToWomen(hombresPrefieren.size(), std::vector<bool>(hombresPrefieren.size(), false));
//    int mRef = 0;
//    while(existFreeMan(freeMen, mRef))
//    {
//        int m = mRef;
//        int womanProposedTo = 0;
//        int woman = getWomanNotProposed(m, hombresPrefieren, proposedToWomen, womanProposedTo);
//        proposedToWomen[m][womanProposedTo] = true;
//        if(freeWomen[woman])
//        {
//            matchedMen.push_back(m);
//            matchedWomen.push_back(woman);
//            freeWomen[woman] = false;
//            freeMen[m] = false;
//        }
//        else
//        {
//            int oldMan = findOldMan(woman, matchedMen, matchedWomen, hombresPrefieren);
//            if(prefersNewMan(woman, m, hombresPrefieren, mujeresPrefieren, matchedMen, oldMan))
//            {
//                int womanPos = findWoman(woman, matchedWomen, hombresPrefieren);
//                matchedMen[womanPos] = m;
//                freeWomen[woman] = false;
//                freeMen[m] = false;
//                freeMen[oldMan] = true;
//            }
//        }
//    }
//    for(int i=0; i<hombresPrefieren.size(); i++)
//    {
//        std::cout << "Hombre " << matchedMen[i] << " con mujer " << matchedWomen[i] << std::endl;
//    }
//    return 0;
//}