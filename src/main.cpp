#include "../inc/linkedList.hh"
#include"../inc/fileFunctions.hh"
#include"../inc/stack.hpp"
#include"../inc/table.hh"
#include"../inc/queue.hh"
#include"../inc/listaSasiedztwa.hh"
#include"../inc/quickSort.hh" 

#include<algorithm>

#include<fstream>
#include<chrono>



int main()
{

   
    std::ifstream myFileRead;
    std::ofstream myFileWrite;

    int const ile = 10000;
    int tablica[ile];
    
    myFileWrite.open("test.txt");
    if(myFileWrite.is_open())
        generateFile(&myFileWrite, ile);
    
    myFileWrite.close();
    
    myFileRead.open("test.txt");

    int number;
    int i = 0;

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            tablica[i] = number;
            ++i;
        }
    }

    auto begin = std::chrono::high_resolution_clock::now();


    // Tutaj wstawcie sortowanie i w cout zmiencie nazwe sortowanie i zapiszcie wyniki dla poszczegolnych sortowan

    quicksort(tablica,0,i-1);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "Sortowanie quick sortem: " << elapsed.count() << "ms" << std::endl;
    //printArray(tablica,i);

    myFileRead.close();

    return 0;
}