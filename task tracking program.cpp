#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, int& nextId) {
    string desc;
    cout << "Enter the description" << endl;
    getline(cin >> ws, desc);

    Task newTask;
    newTask.id = nextId;
    newTask.description = desc;
    newTask.completed = false;
    nextId++;

    tasks.push_back(newTask);

    cout << "TASK ADDED SUCCESSFULLY" << endl;
}

void listTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "NO TASKS" << endl;
        return;
    }

    cout << "--- TASK LIST ---" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        Task task = tasks[i];

        cout << "ID: " << task.id
            << " | Description: " << task.description
            << " | Status: " << (task.completed ? "Completed" : "Not Completed")
            << endl;
    }
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file.is_open()) {
        cout << "FILE COULDN'T OPEN" << endl;
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        Task task = tasks[i];
        file << task.id << " " << task.description << " " << task.completed << "\n";
    }

    file.close();
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "NO TASKS TO MARK" << endl;
        return;
    }
    int id;
    cout << "Enter the ID of the task to mark as completed: ";
    cin >> id;
    bool found = false;
    for (Task& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Task ID " << id << " marked as completed" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task with ID " << id << " not found" << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    cout << "ENTER THE ID FOR DELETE" << endl;
    int id;
    cin >> id;
    bool found = false;
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            cout << "Task ID " << id << " deleted successfully" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Task with ID " << id << " not found" << endl;
    }
}

int main() {
    cout << "WELCOME TO TASK TRACKING PROGRAM :" << endl;

    vector<Task> tasks;
    int nextId = 1;
    int choice;
    string answer;

    do
    {
        cout << "MENU" << endl;
        cout << "1. ADD TASKS" << endl;
        cout << "2. List Tasks" << endl;
        cout << "3. Save" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. DELETE THE TASK" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            addTask(tasks, nextId);
        }
        else if (choice == 2) {
            listTasks(tasks);
        }
        else if (choice == 3) {
            saveTasks(tasks);
            cout << "Tasks saved to tasks.txt successfully." << endl;

            cout << "DO U WANNA CONTINUE TO TASKS? (yes/no): ";
            cin >> answer;

            if (answer == "yes" || answer == "y") {
                cout << "Continuing..." << endl;
            }
            else {
                cout << "Exiting program. See you!" << endl;
                break;
            }
        }
        else if (choice == 4) {
            markTaskCompleted(tasks);
        }

        else if (choice == 5) {
            deleteTask(tasks);
        }
        else if (choice == 6) {
            cout << "Thank you for using me, see you next time ;)))" << endl;
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }

    } while (true);

    return 0;
}
