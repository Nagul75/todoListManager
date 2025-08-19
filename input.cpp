//
// Created by regal on 8/19/25.
//
#include <iostream>
#include <string>
#include <limits>
#include "input.h"

int input::getChoice()
{
    int choice{};
    while (true)
    {
        std::cout << "Enter index (1 - 6): ";
        std::cin >> choice;
        if (!std::cin)
        {
            std::cout << "Invalid input! \n";
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice < 1 || choice > 6)
        {
            std::cout << "Invalid bounds! Try again! \n";
            continue;
        }
        return choice;
    }
}

std::size_t input::getIndex(const std::size_t size)
{
    std::size_t index{};
    while (true)
    {
        std::cout << "Enter index of task: ";
        std::cin >> index;
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(0);
            std::cout << "Invalid input! try again! \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (index >= size)
        {
            std::cout << "Invalid bounds! Try again! \n";
            continue;
        }
        return index;
    }
}

bool input::getTaskCompletion()
{
    char completed{};
    while (true)
    {
        std::cout << "Task completed (y/n)? ";
        std::cin >> completed;
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Try again! \n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (completed == 'y' || completed == 'n')
        {
            return completed == 'y';
        }
        std::cout << "Please enter 'y' or 'n' \n";
    }
}

std::string input::getTaskName()
{
    std::string taskName{};
    std::cout << "Enter task name: ";
    std::getline(std::cin >> std::ws, taskName);
    return taskName;
}

std::string input::getTaskDescription()
{
    std::string description{};
    std::string line{};
    std::cout << "Enter task description: (Enter END on a newline to stop) \n";
    while (true)
    {
        std::getline(std::cin >> std::ws, line);
        if (line == "END")
        {
            break;
        }
        line.push_back('\n');
        description += line;
    }
    if (!description.empty()) description.pop_back();
    return description;
}
