#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return team.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		team[person][TaskStatus::NEW]++;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
			const string& person, int task_count) {
                TasksInfo updated, old; //output containers
                TasksInfo some_tasks = team.at(person); //task list (map) for a person
                vector<TaskStatus> tasks = { // checking against all status values
                    TaskStatus::NEW, TaskStatus::IN_PROGRESS, 
                    TaskStatus::TESTING/*,  TaskStatus::DONE */};
                for (auto task : tasks) {
                    int& this_task_qty = some_tasks[task]; //qty of tasks of this type (status)
                    if (this_task_qty == 0) {
                        some_tasks.erase(task);
                    } 
                    while (task_count > 0 && this_task_qty) {
                        this_task_qty--;
                        updated[UpdateTask(task, team.at(person))]++;
                        task_count--;
                    }
                    for (int i = this_task_qty; i > 0; i --) {
                        old[task]++;
                    }
                }
                return {updated, old};
            }
private:
	map<string, TasksInfo> team;
    TaskStatus UpdateTask (const TaskStatus& task, TasksInfo& list) {
        TaskStatus value;
        switch (task)
        {
        case TaskStatus::NEW :
            list[TaskStatus::NEW]--;
            list[TaskStatus::IN_PROGRESS]++;
            value = TaskStatus::IN_PROGRESS;
            break;
        case TaskStatus::IN_PROGRESS :
            list[TaskStatus::IN_PROGRESS]--;
            list[TaskStatus::TESTING]++;
            value = TaskStatus::TESTING;
            break;
        case TaskStatus::TESTING :
            list[TaskStatus::TESTING]--;
            list[TaskStatus::DONE]++;
            value = TaskStatus::DONE;
            break;
        default:
            break;
        }
        return value;
    }
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW]         << " new tasks" <<
    ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
    ", " << tasks_info[TaskStatus::TESTING]     << " tasks are being tested" <<
    ", " << tasks_info[TaskStatus::DONE]        << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    // tasks.AddNewTask("Ilia");
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Ivan");
    }
    // cout << "Ilia's tasks: ";
    // PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    cout << "\nUpdating 5 tasks now:\n";
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 5);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    cout << "\nUpdating 5 tasks now:\n";
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 5);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    cout << "\nUpdating 1 tasks now:\n";
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 1);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "\n5 new tasks added\n";
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    cout << "\nUpdating 2 tasks now:\n";
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    cout << "\nUpdating 4 tasks now:\n";
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 4);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    return 0;
}
