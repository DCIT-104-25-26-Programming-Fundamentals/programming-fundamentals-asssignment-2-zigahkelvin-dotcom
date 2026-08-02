// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//   1. Add a Task
//   2. View All Tasks
//   3. Delete a Task
//   4. Quit
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addTask(vector<string>& tasks) {
    cin.ignore();
    string description;

    cout << "Enter task: ";
    getline(cin, description);

    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + (taskNumber - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Invalid choice. Please enter 1-4." << endl;
        }

        cout << endl;
    }

    return 0;
}
