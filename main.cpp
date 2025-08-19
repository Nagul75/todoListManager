#include <iostream>
#include "TodoListManager.h"
#include "input.h"

void printMenu()
{
    std::cout << "What do you want to do? \n";
    std::cout << "1. View all tasks \n";
    std::cout << "2. Add a new task \n";
    std::cout << "3. Mark a task as complete \n";
    std::cout << "4. Remove a task \n";
    std::cout << "5. Save and quit \n";
}

void addTask(tdl::TodoListManager& manager)
{
    const bool complete{input::getTaskCompletion()};
    const std::string taskName{input::getTaskName()};
    const std::string taskDescription(input::getTaskDescription());
    manager.addTask({complete, taskName, taskDescription});
    std::cout << "Task added successfully! \n";
}

void markTaskComplete(tdl::TodoListManager& manager)
{
    const std::size_t index{input::getIndex(manager.getTasksSize())};
    manager.markTaskComplete(index);
    std::cout << "Task completed successfully! \n";
}

void removeTask(tdl::TodoListManager& manager)
{
    const std::size_t index{input::getIndex(manager.getTasksSize())};
    manager.removeTask(index);
    std::cout << "Task removed successfully! \n";
}



int main()
{
    tdl::TodoListManager manager{};
    std::cout << "Todo List \n";
    while (true)
    {
        printMenu();
        const int choice{input::getChoice()};
        if (choice == 5)
        {
            manager.writeToFile();
            break;
        }
        switch (choice)
        {
        case 1: manager.viewAllTasks();
                break;
        case 2: addTask(manager);
                break;
        case 3: markTaskComplete(manager);
                break;
        case 4: removeTask(manager);
                break;
        default: std::cout << "Invalid choice! \n";
                break;
        }
    }
    std::cout << "Thank you! Happy completing tasks! \n";
    return 0;
}