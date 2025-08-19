//
// Created by regal on 8/18/25.
//

#ifndef TODOLISTMANAGER_TODOLISTMANAGER_H
#define TODOLISTMANAGER_TODOLISTMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace tdl
{
    struct Task
    {
        bool m_isCompleted{false};
        std::string m_taskName{};
        std::string m_taskDescription {};
    };
    class TodoListManager
    {
    public:
        TodoListManager();
        [[nodiscard]] std::size_t getTasksSize() const { return m_tasks.size();}
        void addTask(const Task& task){m_tasks.emplace_back(task);}
        void removeTask(const std::size_t taskIndex){m_tasks.erase(m_tasks.begin() + static_cast<int>(taskIndex));}
        Task& viewTask(const std::size_t taskIndex) {return m_tasks[taskIndex];}
        void markTaskComplete(const std::size_t taskIndex){m_tasks[taskIndex].m_isCompleted = true;}

        void viewAllTasks() const;
        void writeToFile();
        void loadTasks();
    private:
        std::vector<Task> m_tasks{};
    };
}

#endif //TODOLISTMANAGER_TODOLISTMANAGER_H