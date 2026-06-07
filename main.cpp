#include <cstdio> /*printf*/
#include <vector> /*список задач*/
#include <string>
using namespace std; /*чтобы не писать std: перед стандартными объектами*/



/*наборы готовых значений*/
enum Status { TODO, IN_PROGRESS, DONE }; /*удобнее вместо 0 1 и 2 юзать*/
enum Priority { LOW, MEDIUM, HIGH };



//просто задачи
class Task { // базовый класс, то есть основа для всех задач
protected: /*внутри класса и у дочерних элеменнтов*/
    string title;
    Priority priority;
    Status status;



public: /*конструктор*/
    Task(string t, Priority p, Status s = TODO) {
        title = t;
        priority = p;
        status = s;
    }



    virtual void print() { /* virtual  - в дочернем можно переопределить*/
        printf("Task: %s, priority = %d, status = %d\n",
               title.c_str(), priority, status);
    }


    //статус
    Status getStatus() {
        return status;
    }


    //приоритет
    Priority getPriority() {
        return priority;
    }


    //у нас у обычных задач просрочки нет
    virtual bool isOverdue() {
        return false;
    }


  // вызывается когда объект удаляют, если не виртуальный при удалении дочернего элемента класс мог бы работать неверно
    virtual ~Task() {}
};


//задачи с делайном
class DeadlineTask : public Task { // наследование, DeadlineTask берёт всё из Task и добавляет своё поле deadline


private:
    string deadline;  // дедлайн задачи


public:
 // конструктор задачи с дедлайном
    DeadlineTask(string t, Priority p, string d, Status s = TODO)
        : Task(t, p, s) { // вызываем конструктор родительского класса
        deadline = d;
    }



    void print() override { // override значит заменяем функцию print из родительского класса своей версией
        printf("DeadlineTask: %s, priority = %d, status = %d, deadline = %s",
               title.c_str(), priority, status, deadline.c_str());
               // .c_str() нужно чтобы вернуть указатель на символы строки, чтобы printf понял



        if (isOverdue()) { // если задача просрочена
            printf(" OVERDUE");
        }



        printf("\n");
    }



    bool isOverdue() override { // тут уже своя проверка просрочки для задач с дедлайном
        if (status == DONE) return false; // если задача выполнена, просроченной не считаем
        if (deadline < "08-06-2026") return true; // если дедлайн раньше этой даты, значит просрочена
        return false;
    }
};



int main() {
    vector<Task*> tasks; // список указателей на задачи, сюда можно класть и Task и DeadlineTask



    tasks.push_back(new Task("Read", LOW)); // создаём обычную задачу и добавляем в список
    tasks.push_back(new Task("Code", HIGH, IN_PROGRESS));
    tasks.push_back(new DeadlineTask("Math", HIGH, "05-06-2026")); 
    tasks.push_back(new DeadlineTask("Essay", MEDIUM, "12-06-2026")); 
    tasks.push_back(new DeadlineTask("Lab", HIGH, "01-06-2026", DONE)); 



    printf("All tasks:\n");
    for (int i = 0; i < tasks.size(); i++) { // идём по всем задачам
        tasks[i]->print(); // -> потому что tasks[i] это указатель, вызываем print у объекта
    }



    printf("\nDone tasks:\n");
    for (int i = 0; i < tasks.size(); i++) { // снова идём по всем задачам
        if (tasks[i]->getStatus() == DONE) { // проверяем, выполнена ли задача
            tasks[i]->print(); // если да, печатаем
        }
    }



    printf("\nHighest priority task:\n");
    int imax = 0; // тут будем хранить индекс задачи с самым высоким приоритетом
    for (int i = 1; i < tasks.size(); i++) {
        if (tasks[i]->getPriority() > tasks[imax]->getPriority()) { // если нашли приоритет выше
            imax = i; // запоминаем индекс
        }
    }
    tasks[imax]->print(); // печатаем задачу с максимальным приоритетом



    printf("\nOverdue tasks:\n");
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i]->isOverdue()) { // проверяем, просрочена ли задача
            tasks[i]->print(); // если да, выводим
        }
    }



    for (int i = 0; i < tasks.size(); i++) {
        delete tasks[i]; // удаляем объект из памяти, потому что создавали через new
    }



    return 0;
}
