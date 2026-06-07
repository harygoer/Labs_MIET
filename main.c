/*тут по факту лишь имитация ООП, если прям хотелось ООП, то нужно на плюсах писать, там есть классы, наследование и виртуал методы*/

#include <stdio.h>   /*printf*/
#include <stdlib.h>
#include <string.h>  /*strcpy*/


/*наборы готовых значений*/
enum Status { TODO, IN_PROGRESS, DONE }; /*удобнее вместо 0 1 и 2 юзать*/
enum Priority { LOW, MEDIUM, HIGH };


/*обычная задача*/
struct Task {
    char title[100];          /*название задачи*/
    enum Priority priority;   /*приоритет*/
    enum Status status;       /*статус*/
    int hasDeadline;          /*есть дедлайн или нет*/
    char deadline[20];        /*дата дедлайна если есть*/
};


/*печать одной задачи*/
void printTask(struct Task t) {
    if (t.hasDeadline == 1) { /*если у задачи есть дедлайн*/
        printf("Task: %s, priority = %d, status = %d, deadline = %s",
               t.title, t.priority, t.status, t.deadline);

        if (t.status != DONE && strcmp(t.deadline, "08-06-2026") < 0) {/*сравниваем строки*/
            printf(" OVERDUE");
        }

        printf("\n");
    } else { /*если дедлайна нет*/
        printf("Task: %s, priority = %d, status = %d\n",
               t.title, t.priority, t.status);
    }
}


/*проверка просрочки*/
int isOverdue(struct Task t) {
    if (t.hasDeadline == 0) return 0; /*если дедлайна нет то не просрочена*/
    if (t.status == DONE) return 0;   /*если выполнена то тоже не считаем просроченной*/
    if (strcmp(t.deadline, "08-06-2026") < 0) return 1; /*если дата меньше этой то просрочена, сравнение идёт 0 если одинаковые, меньше 0 первая меншье второй, больше -> наоборот*/
    return 0;
}


int main() {
    struct Task tasks[5]; /*массив задач*/


    /*обычные задачи*/
    strcpy(tasks[0].title, "Read"); /*копируем название в строку*/
    tasks[0].priority = LOW;
    tasks[0].status = TODO;
    tasks[0].hasDeadline = 0; /*дедлайна нет*/

    strcpy(tasks[1].title, "Code");
    tasks[1].priority = HIGH;
    tasks[1].status = IN_PROGRESS;
    tasks[1].hasDeadline = 0; /*дедлайна нет*/


    /*задачи с дедлайном*/
    strcpy(tasks[2].title, "Math");
    tasks[2].priority = HIGH;
    tasks[2].status = TODO;
    tasks[2].hasDeadline = 1; /*дедлайн есть*/
    strcpy(tasks[2].deadline, "05-06-2026");

    strcpy(tasks[3].title, "Essay");
    tasks[3].priority = MEDIUM;
    tasks[3].status = TODO;
    tasks[3].hasDeadline = 1; /*дедлайн есть*/
    strcpy(tasks[3].deadline, "12-06-2026");

    strcpy(tasks[4].title, "Lab");
    tasks[4].priority = HIGH;
    tasks[4].status = DONE;
    tasks[4].hasDeadline = 1; /*дедлайн есть*/
    strcpy(tasks[4].deadline, "01-06-2026");


    printf("All tasks:\n");
    for (int i = 0; i < 5; i++) { /*идём по всем задачам*/
        printTask(tasks[i]); /*печатаем задачу*/
    }


    printf("\nDone tasks:\n");
    for (int i = 0; i < 5; i++) {
        if (tasks[i].status == DONE) { /*если задача выполнена*/
            printTask(tasks[i]);
        }
    }


    printf("\nHighest priority task:\n");
    int imax = 0; /*индекс задачи с самым высоким приоритетом*/
    for (int i = 1; i < 5; i++) {
        if (tasks[i].priority > tasks[imax].priority) { /*если нашли приоритет выше*/
            imax = i; /*запоминаем индекс*/
        }
    }
    printTask(tasks[imax]);


    printf("\nOverdue tasks:\n");
    for (int i = 0; i < 5; i++) {
        if (isOverdue(tasks[i])) { /*если задача просрочена*/
            printTask(tasks[i]);
        }
    }


    return 0;
}