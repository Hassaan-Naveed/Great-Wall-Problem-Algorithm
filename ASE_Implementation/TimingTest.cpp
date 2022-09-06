#include <chrono>
#include <utility>
#include <map>

#include "GreatWall.h"

using std::chrono::steady_clock;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

nanoseconds timingTest(std::ifstream& file)
{
    //Returns amount of time in milliseconds to load entries from text file into memory and complete algorithm

    GreatWall greatWall = GreatWall();
    

    steady_clock::time_point startTime = steady_clock::now();
    greatWall.loadBricks(file);
    greatWall.buildSequence();

    steady_clock::time_point finishTime = steady_clock::now();

    return duration_cast<nanoseconds>(finishTime - startTime);
}


int main(int argc, char* argv[])
{
    //Map of all filepaths for ease of running
    const std::map<std::string, std::string> filePaths
    { {"20", "Great_Wall_Problem-test_data/20/input-pairs-20.txt"}, 
      {"50", "Great_Wall_Problem-test_data/50/input-pairs-50.txt"},
      {"100", "Great_Wall_Problem-test_data/100/input-pairs-100.txt"}, 
      {"200", "Great_Wall_Problem-test_data/200/input-pairs-200.txt"}, 
      {"500", "Great_Wall_Problem-test_data/500/input-pairs-500.txt"}, 
      {"1K", "Great_Wall_Problem-test_data/1K/input-pairs-1K.txt"}, 
      {"2K", "Great_Wall_Problem-test_data/2K/input-pairs-2K.txt"}, 
      {"5K", "Great_Wall_Problem-test_data/5K/input-pairs-5K.txt"}, 
      {"10K", "Great_Wall_Problem-test_data/10K/input-pairs-10K.txt"}, 
      {"20K", "Great_Wall_Problem-test_data/20K/input-pairs-20K.txt"}, 
      {"50K", "Great_Wall_Problem-test_data/50K/input-pairs-50K.txt"}, 
      {"100K", "Great_Wall_Problem-test_data/100K/input-pairs-100K.txt"}, 
      {"200K", "Great_Wall_Problem-test_data/200K/input-pairs-200K.txt"}, 
      {"500K", "Great_Wall_Problem-test_data/500K/input-pairs-500K.txt"}, 
      {"1M", "Great_Wall_Problem-test_data/1M/input-pairs-1M.txt"}, 
      {"2M", "Great_Wall_Problem-test_data/2M/input-pairs-2M.txt"}, 
      {"3M", "Great_Wall_Problem-test_data/3M/input-pairs-3M.txt"} };

    //Check that filepath has been given in command line arguments
    if (argc != 2)
    {
        std::cout << "Error, please provide file location" << std::endl;
    }
    else
    {
        //Check that file exists
        std::ifstream file(filePaths.at(argv[1]));
        if (!file.is_open())
        {
            std::cout << "Error, could not open the file" << std::endl;
        }
        else
        {
            //Run tests and output time taken in nanoseconds
            nanoseconds timeTaken = timingTest(file);

            std::cout << "Entries: " << argv[1] << " entries in map." << std::endl;
            std::cout << "Time taken: " << timeTaken.count() << " nanoseconds." << std::endl;

            return 0;
        }
    }
}