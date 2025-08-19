//
// Created by regal on 8/19/25.
//

#ifndef TODOLISTMANAGER_INPUT_H
#define TODOLISTMANAGER_INPUT_H

#include <string>
namespace input
{
    int getChoice();
    std::size_t getIndex(std::size_t);
    std::string getTaskName();
    std::string getTaskDescription();
    bool getTaskCompletion();
}

#endif //TODOLISTMANAGER_INPUT_H