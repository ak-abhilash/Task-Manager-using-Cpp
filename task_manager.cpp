#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Task {
    string title;
    string description;
    string dueDate;
    int priority;
    bool completed;
    string category;
};

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task title: ";
    getline(cin, newTask.title);
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, newTask.dueDate);
    cout << "Enter priority (1-5): ";
    cin >> newTask.priority;
    cin.ignore();
    newTask.completed = false;
    cout << "Enter category: ";
    getline(cin, newTask.category);
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void markCompleted(vector<Task>& tasks, int index) {
    tasks[index].completed = true;
    cout << "Task marked as completed!\n";
}

void deleteTask(vector<Task>& tasks, int index) {
    tasks.erase(tasks.begin() + index);
    cout << "Task deleted successfully!\n";
}

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "-------------------\n";
    cout << setw(5) << "ID" << setw(20) << "Title" << setw(15) << "Due Date"
         << setw(10) << "Priority" << setw(15) << "Completed" << setw(15) << "Category\n";
    cout << "-------------------\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(5) << i + 1 << setw(20) << tasks[i].title << setw(15) << tasks[i].dueDate
             << setw(10) << tasks[i].priority << setw(15) << (tasks[i].completed ? "Yes" : "No")
             << setw(15) << tasks[i].category << endl;
    }
    cout << "-------------------\n";
}

void saveTasksToFile(const vector<Task>& tasks, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const Task& task : tasks) {
            outputFile << task.title << "," << task.description << "," << task.dueDate << ","
                       << task.priority << "," << task.completed << "," << task.category << endl;
        }
        outputFile.close();
        cout << "Tasks saved to file successfully!\n";
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}

void loadTasksFromFile(vector<Task>& tasks, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        Task task;
        while (getline(inputFile, task.title, ',') && getline(inputFile, task.description, ',') &&
               getline(inputFile, task.dueDate, ',') && inputFile >> task.priority &&
               inputFile.ignore() && inputFile >> task.completed && inputFile.ignore() &&
               getline(inputFile, task.category)) {
            tasks.push_back(task);
        }
        inputFile.close();
        cout << "Tasks loaded from file successfully!\n";
    } else {
        cout << "No existing task file found.\n";
    }
}

void sortByDueDate(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.dueDate < b.dueDate;
    });
    cout << "Tasks sorted by due date!\n";
}

void sortByPriority(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
    });
    cout << "Tasks sorted by priority!\n";
}

void editTask(vector<Task>& tasks, int index) {
    Task& task = tasks[index];
    cout << "Editing Task " << index + 1 << ":\n";
    cout << "1. Title: " << task.title << endl;
    cout << "2. Description: " << task.description << endl;
    cout << "3. Due Date: " << task.dueDate << endl;
    cout << "4. Priority: " << task.priority << endl;
    cout << "5. Category: " << task.category << endl;
    cout << "Enter field number to edit (1-5): ";
    int field;
    cin >> field;
    cin.ignore();
    switch (field) {
        case 1:
            cout << "Enter new title: ";
            getline(cin, task.title);
            break;
        case 2:
            cout << "Enter new description: ";
            getline(cin, task.description);
            break;
        case 3:
            cout << "Enter new due date (YYYY-MM-DD): ";
            getline(cin, task.dueDate);
            break;
        case 4:
            cout << "Enter new priority (1-5): ";
            cin >> task.priority;
            break;
        case 5:
            cout << "Enter new category: ";
            getline(cin, task.category);
            break;
        default:
            cout << "Invalid field number!\n";
            break;
    }
    cout << "Task edited successfully!\n";
}

int main() {
    vector<Task> tasks;
    const string filename = "tasks.txt";
    
    loadTasksFromFile(tasks, filename);
    
    int choice;
    do {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Delete Task\n";
        cout << "4. View All Tasks\n";
        cout << "5. Sort Tasks by Due Date\n";
        cout << "6. Sort Tasks by Priority\n";
        cout << "7. Save Tasks to File\n";
        cout << "8. Edit Task\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2: {
                int index;
                cout << "Enter task ID to mark as completed: ";
                cin >> index;
                cin.ignore();
                if (index > 0 && index <= tasks.size()) {
                    markCompleted(tasks, index - 1);
                } else {
                    cout << "Invalid task ID!\n";
                }
                break;
            }
            case 3: {
                int index;
                cout << "Enter task ID to delete: ";
                cin >> index;
                cin.ignore();
                if (index > 0 && index <= tasks.size()) {
                    deleteTask(tasks, index - 1);
                } else {
                    cout << "Invalid task ID!\n";
                }
                break;
            }
            case 4:
                displayTasks(tasks);
                break;
            case 5:
                sortByDueDate(tasks);
                break;
            case 6:
                sortByPriority(tasks);
                break;
            case 7:
                saveTasksToFile(tasks, filename);
                break;
            case 8:
                int editIndex;
                cout << "Enter task ID to edit: ";
                cin >> editIndex;
                cin.ignore();
                if (editIndex > 0 && editIndex <= tasks.size()) {
                    editTask(tasks, editIndex - 1);
                } else {
                    cout << "Invalid task ID!\n";
                }
                break;
            case 9:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9.\n";
                break;
        }
    } while (choice != 9);
    
    return 0;
}