#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

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