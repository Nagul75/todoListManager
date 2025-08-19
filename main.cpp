#include <iostream>
#include "TodoListManager.h"
#include "input.h"

void printMenu()
{
    std::cout << "What do you want to do? \n";
    std::cout << "1. View all tasks \n";
    std::cout << "2. Add a new task \n";
    std::cout << "3. Mark a task as complete \n";
    std::cout << "4. View specific task details \n";
    std::cout << "5. Remove a task \n";
    std::cout << "6. Save and quit \n";
}

void addTask(tdl::TodoListManager& manager)
{
    const bool complete{input::getTaskCompletion()};
    const std::string taskName{input::getTaskName()};
    const std::string taskDescription(input::getTaskDescription());
    manager.addTask({complete, taskName, taskDescription});
    std::cout << "Task added successfully! \n \n";
}

void markTaskComplete(tdl::TodoListManager& manager)
{
    if (manager.getTasksSize() == 0)
    {
        std::cout << "No tasks present! Hooray! \n \n";
        return;
    }
    const std::size_t index{input::getIndex(manager.getTasksSize())};
    manager.markTaskComplete(index);
}

void removeTask(tdl::TodoListManager& manager)
{
    if (manager.getTasksSize() == 0)
    {
        std::cout << "No tasks present! Hooray! \n \n";
        return;
    }
    const std::size_t index{input::getIndex(manager.getTasksSize())};
    manager.removeTask(index);
    std::cout << "Task removed successfully! \n \n";
}

void viewTaskDetails(tdl::TodoListManager& manager)
{
    if (manager.getTasksSize() == 0)
    {
        std::cout << "No tasks present! Hooray! \n \n";
        return;
    }
    const tdl::Task task{manager.viewTask(input::getIndex(manager.getTasksSize()))};
    std::cout << "Status: " << (task.m_isCompleted ? "Completed" : "Incomplete :( ") << '\n';
    std::cout << "Task Name: " << task.m_taskName << '\n';
    std::cout << "Task description: \n" << task.m_taskDescription << "\n \n";
}

int main()
{
    tdl::TodoListManager manager{};
    std::cout << "Todo List \n";
    std::cout << "Don't forget to save before exiting! \n \n";
    while (true)
    {
        printMenu();
        const int choice{input::getChoice()};
        std::cout << '\n';
        if (choice == 6)
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
        case 4: viewTaskDetails(manager);
                break;
        case 5: removeTask(manager);
                break;
        default: std::cout << "Invalid choice! \n";
                break;
        }
    }
    std::cout << "Thank you! Happy completing tasks! \n";
    return 0;
}