#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构体
typedef struct Student {
    int id;                  // 学生编号
    char className[50];      // 班级
    char name[50];           // 姓名
    int age;                 // 年龄
    char gender[10];         // 性别
    float chinese;           // 语文成绩
    float math;              // 数学成绩
    float english;           // 英语成绩
    struct Student* next;    // 下一个节点指针
} Student;

// 全局变量
Student* head = NULL;        // 链表头指针
int studentCount = 0;        // 学生计数

// 函数声明
void showMenu();
void addStudent();
void deleteStudent();
void modifyStudent();
void queryStudent();
void displayAllStudents();
void calculateAverage();
void saveToFile();
void loadFromFile();
void freeMemory();

// 显示菜单
void showMenu() {
    printf("\n========== 学生管理系统 ==========\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 修改学生信息\n");
    printf("4. 查询学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 计算平均成绩\n");
    printf("7. 保存数据到文件\n");
    printf("8. 从文件加载数据\n");
    printf("0. 退出系统\n");
    printf("==================================\n");
    printf("请选择操作: ");
}

// 创建新学生节点
Student* createStudent(int id, char* className, char* name, int age, char* gender,
    float chinese, float math, float english) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("内存分配失败!\n");
        return NULL;
    }
    newStudent->id = id;
    strcpy(newStudent->className, className);
    strcpy(newStudent->name, name);
    newStudent->age = age;
    strcpy(newStudent->gender, gender);
    newStudent->chinese = chinese;
    newStudent->math = math;
    newStudent->english = english;
    newStudent->next = NULL;
    return newStudent;
}

// 添加学生
void addStudent() {
    int id, age;
    char className[50], name[50], gender[10];
    float chinese, math, english;

    printf("\n--- 添加学生信息 ---\n");

    // 检查是否已存在该编号
    printf("请输入学生编号: ");
    scanf("%d", &id);

    // 检查编号是否重复
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("该编号已存在，请使用其他编号!\n");
            return;
        }
        temp = temp->next;
    }

    printf("请输入班级: ");
    scanf("%s", className);
    printf("请输入姓名: ");
    scanf("%s", name);
    printf("请输入年龄: ");
    scanf("%d", &age);
    printf("请输入性别: ");
    scanf("%s", gender);
    printf("请输入语文成绩: ");
    scanf("%f", &chinese);
    printf("请输入数学成绩: ");
    scanf("%f", &math);
    printf("请输入英语成绩: ");
    scanf("%f", &english);

    Student* newStudent = createStudent(id, className, name, age, gender, chinese, math, english);
    if (newStudent == NULL) {
        return;
    }

    // 插入到链表末尾
    if (head == NULL) {
        head = newStudent;
    }
    else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    studentCount++;
    printf("学生添加成功!\n");
}

// 删除学生
void deleteStudent() {
    if (head == NULL) {
        printf("链表为空，没有学生可以删除!\n");
        return;
    }

    int id;
    printf("\n--- 删除学生信息 ---\n");
    printf("请输入要删除的学生编号: ");
    scanf("%d", &id);

    Student* current = head;
    Student* prev = NULL;

    // 查找要删除的节点
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("未找到编号为 %d 的学生!\n", id);
        return;
    }

    // 确认删除
    char confirm;
    printf("确定要删除学生 %s 吗? (y/n): ", current->name);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        if (prev == NULL) {
            // 删除头节点
            head = current->next;
        }
        else {
            prev->next = current->next;
        }
        free(current);
        studentCount--;
        printf("学生删除成功!\n");
    }
    else {
        printf("取消删除。\n");
    }
}

// 修改学生信息
void modifyStudent() {
    if (head == NULL) {
        printf("链表为空，没有学生可以修改!\n");
        return;
    }

    int id;
    printf("\n--- 修改学生信息 ---\n");
    printf("请输入要修改的学生编号: ");
    scanf("%d", &id);

    Student* current = head;
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("未找到编号为 %d 的学生!\n", id);
        return;
    }

    printf("\n当前学生信息:\n");
    printf("编号: %d\n", current->id);
    printf("班级: %s\n", current->className);
    printf("姓名: %s\n", current->name);
    printf("年龄: %d\n", current->age);
    printf("性别: %s\n", current->gender);
    printf("语文: %.1f\n", current->chinese);
    printf("数学: %.1f\n", current->math);
    printf("英语: %.1f\n", current->english);

    printf("\n请输入新信息 (直接回车保持原值):\n");

    char tempStr[50];
    int tempInt;
    float tempFloat;

    printf("新班级 [%s]: ", current->className);
    scanf("%s", tempStr);
    if (strlen(tempStr) > 0) {
        strcpy(current->className, tempStr);
    }

    printf("新姓名 [%s]: ", current->name);
    scanf("%s", tempStr);
    if (strlen(tempStr) > 0) {
        strcpy(current->name, tempStr);
    }

    printf("新年龄 [%d]: ", current->age);
    scanf("%d", &tempInt);
    if (tempInt > 0) {
        current->age = tempInt;
    }

    printf("新性别 [%s]: ", current->gender);
    scanf("%s", tempStr);
    if (strlen(tempStr) > 0) {
        strcpy(current->gender, tempStr);
    }

    printf("新语文成绩 [%.1f]: ", current->chinese);
    scanf("%f", &tempFloat);
    if (tempFloat >= 0) {
        current->chinese = tempFloat;
    }

    printf("新数学成绩 [%.1f]: ", current->math);
    scanf("%f", &tempFloat);
    if (tempFloat >= 0) {
        current->math = tempFloat;
    }

    printf("新英语成绩 [%.1f]: ", current->english);
    scanf("%f", &tempFloat);
    if (tempFloat >= 0) {
        current->english = tempFloat;
    }

    printf("学生信息修改成功!\n");
}

// 查询学生
void queryStudent() {
    if (head == NULL) {
        printf("链表为空，没有学生可以查询!\n");
        return;
    }

    int choice;
    printf("\n--- 查询学生信息 ---\n");
    printf("1. 按编号查询\n");
    printf("2. 按姓名查询\n");
    printf("3. 按班级查询\n");
    printf("请选择查询方式: ");
    scanf("%d", &choice);

    Student* current = head;
    int found = 0;

    switch (choice) {
    case 1: {
        int id;
        printf("请输入学生编号: ");
        scanf("%d", &id);
        while (current != NULL) {
            if (current->id == id) {
                found = 1;
                printf("\n查询结果:\n");
                printf("编号: %d | 班级: %s | 姓名: %s | 年龄: %d | 性别: %s\n",
                    current->id, current->className, current->name,
                    current->age, current->gender);
                printf("语文: %.1f | 数学: %.1f | 英语: %.1f | 总分: %.1f | 平均分: %.1f\n",
                    current->chinese, current->math, current->english,
                    current->chinese + current->math + current->english,
                    (current->chinese + current->math + current->english) / 3);
                break;
            }
            current = current->next;
        }
        break;
    }
    case 2: {
        char name[50];
        printf("请输入学生姓名: ");
        scanf("%s", name);
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                found = 1;
                printf("\n查询结果:\n");
                printf("编号: %d | 班级: %s | 姓名: %s | 年龄: %d | 性别: %s\n",
                    current->id, current->className, current->name,
                    current->age, current->gender);
                printf("语文: %.1f | 数学: %.1f | 英语: %.1f | 总分: %.1f | 平均分: %.1f\n",
                    current->chinese, current->math, current->english,
                    current->chinese + current->math + current->english,
                    (current->chinese + current->math + current->english) / 3);
            }
            current = current->next;
        }
        break;
    }
    case 3: {
        char className[50];
        printf("请输入班级名称: ");
        scanf("%s", className);
        printf("\n查询结果:\n");
        while (current != NULL) {
            if (strcmp(current->className, className) == 0) {
                found = 1;
                printf("编号: %d | 班级: %s | 姓名: %s | 年龄: %d | 性别: %s\n",
                    current->id, current->className, current->name,
                    current->age, current->gender);
                printf("语文: %.1f | 数学: %.1f | 英语: %.1f | 总分: %.1f | 平均分: %.1f\n",
                    current->chinese, current->math, current->english,
                    current->chinese + current->math + current->english,
                    (current->chinese + current->math + current->english) / 3);
            }
            current = current->next;
        }
        break;
    }
    default:
        printf("无效的选择!\n");
        return;
    }

    if (!found) {
        printf("未找到符合条件的学生!\n");
    }
}

// 显示所有学生
void displayAllStudents() {
    if (head == NULL) {
        printf("链表为空，没有学生信息!\n");
        return;
    }

    printf("\n--- 所有学生信息 ---\n");
    printf("编号\t班级\t\t姓名\t年龄\t性别\t语文\t数学\t英语\t总分\t平均分\n");
    printf("-----------------------------------------------------------------------------------------\n");

    Student* current = head;
    int count = 0;
    float totalChinese = 0, totalMath = 0, totalEnglish = 0;

    while (current != NULL) {
        float total = current->chinese + current->math + current->english;
        float average = total / 3;

        printf("%d\t%s\t\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",
            current->id, current->className, current->name,
            current->age, current->gender,
            current->chinese, current->math, current->english,
            total, average);

        totalChinese += current->chinese;
        totalMath += current->math;
        totalEnglish += current->english;
        count++;
        current = current->next;
    }

    printf("-----------------------------------------------------------------------------------------\n");
    printf("共有 %d 名学生\n", count);
    if (count > 0) {
        printf("全班平均成绩 - 语文: %.1f | 数学: %.1f | 英语: %.1f\n",
            totalChinese / count, totalMath / count, totalEnglish / count);
    }
}

// 计算平均成绩
void calculateAverage() {
    if (head == NULL) {
        printf("链表为空，没有学生信息!\n");
        return;
    }

    float totalChinese = 0, totalMath = 0, totalEnglish = 0;
    float maxChinese = 0, maxMath = 0, maxEnglish = 0;
    float minChinese = 100, minMath = 100, minEnglish = 100;
    char maxCName[50], maxMName[50], maxEName[50];
    char minCName[50], minMName[50], minEName[50];
    int count = 0;

    Student* current = head;
    while (current != NULL) {
        totalChinese += current->chinese;
        totalMath += current->math;
        totalEnglish += current->english;

        if (current->chinese > maxChinese) {
            maxChinese = current->chinese;
            strcpy(maxCName, current->name);
        }
        if (current->math > maxMath) {
            maxMath = current->math;
            strcpy(maxMName, current->name);
        }
        if (current->english > maxEnglish) {
            maxEnglish = current->english;
            strcpy(maxEName, current->name);
        }

        if (current->chinese < minChinese) {
            minChinese = current->chinese;
            strcpy(minCName, current->name);
        }
        if (current->math < minMath) {
            minMath = current->math;
            strcpy(minMName, current->name);
        }
        if (current->english < minEnglish) {
            minEnglish = current->english;
            strcpy(minEName, current->name);
        }

        count++;
        current = current->next;
    }

    printf("\n--- 成绩统计信息 ---\n");
    printf("共有 %d 名学生\n", count);
    printf("\n平均成绩:\n");
    printf("语文: %.1f | 数学: %.1f | 英语: %.1f\n",
        totalChinese / count, totalMath / count, totalEnglish / count);
    printf("\n最高分:\n");
    printf("语文: %.1f (%s) | 数学: %.1f (%s) | 英语: %.1f (%s)\n",
        maxChinese, maxCName, maxMath, maxMName, maxEnglish, maxEName);
    printf("\n最低分:\n");
    printf("语文: %.1f (%s) | 数学: %.1f (%s) | 英语: %.1f (%s)\n",
        minChinese, minCName, minMath, minMName, minEnglish, minEName);
}

// 保存数据到文件
void saveToFile() {
    if (head == NULL) {
        printf("没有数据可以保存!\n");
        return;
    }

    FILE* file = fopen("students.dat", "w");
    if (file == NULL) {
        printf("无法打开文件进行写入!\n");
        return;
    }

    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%d %s %s %d %s %.1f %.1f %.1f\n",
            current->id, current->className, current->name,
            current->age, current->gender,
            current->chinese, current->math, current->english);
        current = current->next;
    }

    fclose(file);
    printf("数据已保存到 students.dat 文件!\n");
}

// 从文件加载数据
void loadFromFile() {
    FILE* file = fopen("students.dat", "r");
    if (file == NULL) {
        printf("无法打开文件或文件不存在!\n");
        return;
    }

    // 清空现有数据
    freeMemory();

    int id, age;
    char className[50], name[50], gender[10];
    float chinese, math, english;

    while (fscanf(file, "%d %s %s %d %s %f %f %f",
        &id, className, name, &age, gender,
        &chinese, &math, &english) != EOF) {
        Student* newStudent = createStudent(id, className, name, age, gender,
            chinese, math, english);
        if (newStudent != NULL) {
            if (head == NULL) {
                head = newStudent;
            }
            else {
                Student* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newStudent;
            }
            studentCount++;
        }
    }

    fclose(file);
    printf("数据已从 students.dat 文件加载! 共加载 %d 名学生\n", studentCount);
}

// 释放内存
void freeMemory() {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    studentCount = 0;
}

// 主函数
int main() {
    int choice;

    printf("欢迎使用学生管理系统!\n");

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            modifyStudent();
            break;
        case 4:
            queryStudent();
            break;
        case 5:
            displayAllStudents();
            break;
        case 6:
            calculateAverage();
            break;
        case 7:
            saveToFile();
            break;
        case 8:
            loadFromFile();
            break;
        case 0:
            saveToFile();
            freeMemory();
            printf("感谢使用学生管理系统，再见!\n");
            break;
        default:
            printf("无效的选择，请重新输入!\n");
        }
    } while (choice != 0);

    return 0;
}