#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void addTask();
void viewAllTasks();
void markTaskAsCompleted();
void deleteTask();
void saveTasksToFile();
void loadtasks();//load tasks from file when app starts
void exitTheApp();

struct Task {
    string name;
    bool completed;
};
vector<Task> tasks;

int choice;
int main() {
    do {
        cout << "\n===========================\n";
        cout << "        TO-DO LIST\n";
        cout << "===========================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5.save tasks  to file\n";
        cout<<"6. exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number 1–5.\n";
            continue;
        }

        switch (choice) {
            case 1: addTask(); 
            break;
            case 2: viewAllTasks(); 
            break;
            case 3: markTaskAsCompleted();
             break;
            case 4: deleteTask(); 
            break;
            case 5: saveTasksToFile();
                cout << "Tasks saved! Exiting...\n";
                break;
            case 6:loadtasks();
                 break;
            default: 
                cout << "Invalid choice! Enter 1–5.\n";
        }

    } while (choice != 5);

    return 0;
}

void addTask(){   
    cin.ignore();  
    string taskName;

    cout << "Enter task name: ";
    getline(cin, taskName);

    Task newTask;
    newTask.name = taskName;
    newTask.completed = false;

    tasks.push_back(newTask);

    cout << "Task added successfully!\n";



}
void viewAllTasks(){

    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYOUR TASKS:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name 
             << " [" << (tasks[i].completed ? "Done" : "Not Done") << "]\n";
    }

}
void markTaskAsCompleted(){

    viewAllTasks();

    int choice;
    cout << "Enter task number to mark as completed: ";
    cin >> choice;

    if (choice < 1 || choice > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[choice - 1].completed = true;
    cout << "Task marked as completed!\n";



}
void deleteTask(){
viewAllTasks();

    int choice;
    cout << "Enter task number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (choice - 1));
    cout << "Task deleted.\n";

}
void saveTasksToFile(){
fstream file("tasks.txt");

    for (Task &t : tasks) {
        file << t.name << "|" << t.completed << "\n";


}
}
void loadtasks(){

    ifstream file("tasks.txt");

    if (!file.is_open()) {
        return; // no file yet
    }

    tasks.clear();
    string line;

    while (getline(file, line)) {
        size_t pos = line.find("|");
        string name = line.substr(0, pos);
        bool status = stoi(line.substr(pos + 1));

        tasks.push_back({name, status});
    }

    file.close();




}
void exitTheApp(){



}