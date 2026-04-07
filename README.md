# Problem 113 - T3 链表栈队列

**ACMOJ Problem ID**: 1468

## Table of Contents

- [Problem 113 - T3 链表栈队列](#problem-113-t3-链表栈队列)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [Submission Format](#submission-format)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1468. T3 链表栈队列** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/113/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

这个学期，小k要学习数据结构了。学习了最基础的两种线性数据结构栈和队列之后，他发现这两种数据结构都可以使用程序设计课程中学到的链表来实现，但是他忘记了链表怎么写，也不记得继承与派生的内容了。你能帮帮他吗？

在本题中，你需要实现一个模板链表类`LinkedList`，并在其基础上派生两个类：`Stack`与`Queue`。

**注意：**你能够使用的头文件**只有cstdio与iostream**，我们将人工后台检查代码，如果出现其他头文件直接判零分。

具体要求如下：

## LinkedList

实现一个**模板**链表类，需要支持以下函数：（假设模板参数为T）

| 函数名       | 功能                                                         | 返回值                                                       |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| pushFront    | 在链表头插入一个元素                                         | void                                                         |
| pushBack     | 在链表尾插入一个元素                                         | void                                                         |
| popFront     | 在链表头删除一个元素                                         | 被删除的元素内保存的值，若链表为空则返回T默认构造函数产生的值 |
| popBack      | 在链表尾删除一个元素                                         | 被删除的元素内保存的值，若链表为空则返回T默认构造函数产生的值 |
| size         | 返回链表长度                                                 | int                                                          |
| 析构函数     | 保证不存在内存泄漏                                           | 无                                                           |
| 默认构造函数 | 构造一个空链表                                               | 无                                                           |
| 拷贝构造函数 | 构造一个与给定链表相同的链表                                 | 无                                                           |
| print        | 输出链表，元素间用一个空格隔开，最后输出换行符（使用cout完成输出） | void                                                         |

以及声明以下**虚函数**：（保证不会调用`LinkedList`类的虚函数）

保证`peak`函数调用时数据结构不会为空。

| 函数名 | 返回值类型   | 参数表 |
| ------ | ------------ | ------ |
| name   | const char * | 无     |
| peak   | T            | 无     |
| pop    | T            | 无     |
| push   | void         | T val  |

## Stack

关于栈：

<img src="https://acm.sjtu.edu.cn/OnlineJudge-pic/20220211-145307-432984.png" style="width: 60%">

栈是一种简单的线性数据结构，特殊之处在于，栈对数据 "存" 和 "取" 的过程有特殊的要求：

1. 栈只能从表的一端存取数据，另一端是封闭的，如图中所示；
2. 在栈中，无论是存数据还是取数据，都必须遵循"先进后出"的原则，即最先进栈的元素最后出栈。拿图中的栈来说，从图中数据的存储状态可判断出，元素 1 是最先进的栈。因此，当需要从栈中取出元素 1 时，根据"先进后出"的原则，需提前将元素 4 、元素 3 和元素 2 依次从栈中取出，然后才能成功取出元素 1。

因此，可以看出，栈是一种只能从表的一端存取数据且遵循 "先进后出" 原则的线性存储结构。通常，栈的开口端被称为栈顶；相应地，封口端被称为栈底。因此，栈顶元素指的就是距离栈顶最近的元素，拿图中的栈来说，栈顶元素为元素 4；同理，栈底元素指的是位于栈最底部的元素，图中的栈底元素为元素 1。

要求：

不能在类内定义变量。

虚函数实现：

| 函数名 | 功能             |
| ------ | ---------------- |
| name   | 返回"Stack"      |
| peak   | 返回栈顶元素的值 |
| pop    | 弹出栈顶元素     |
| push   | 将一个元素压入栈 |

## Queue

关于队列：

队列，和栈一样，也是一种对数据的"存"和"取"有严格要求的线性存储结构。与栈结构不同的是，队列的两端都"开口"，要求数据只能从一端进，从另一端出，如图所示：

<img src="https://acm.sjtu.edu.cn/OnlineJudge-pic/20220211-150416-795038.png" style="width: 60%">

通常，称进数据的一端为 "队尾"，出数据的一端为 "队头"，数据元素进队列的过程称为 "入队"，出队列的过程称为 "出队"。不仅如此，队列中数据的进出要遵循 "先进先出" 的原则，即最先进队列的数据元素，同样要最先出队列。拿图中的队列来说，从数据在队列中的存储状态可以分析出，元素 1 最先进队，其次是元素 2，最后是元素 3。此时如果要将元素 3 出队，根据队列 "先进先出" 的特点，元素 1 要先出队列，元素 2 再出队列，最后才轮到元素 3 出队列。

要求：

不能在类内定义变量。

虚函数实现：

| 函数名 | 功能               |
| ------ | ------------------ |
| name   | 返回"Queue"        |
| peak   | 返回队首元素的值   |
| pop    | 在队首删除一个元素 |
| push   | 在队尾加入一个元素 |

### Input Format



### Output Format



### Samples

#### Sample 1

**Input:**
```
int main() {
    LinkedList<int> * list = new LinkedList<int>;
    LinkedList<int> * stack = new Stack<int>;
    LinkedList<int> * queue = new Queue<int>;
    
    cout << "LinkedList" << endl;
    list->pushFront(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushFront(4);
    list->print();
    list->popFront();
    list->popBack();
    list->print();
    cout << list->size() << endl;
    
    cout << stack->name() << endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    cout << stack->peak() << endl;
    stack->pop();
    cout << stack->pop() << endl;
    cout << stack->peak() << endl;
    
    cout << queue->name() << endl;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    cout << queue->peak() << endl;
    queue->pop();
    cout << queue->pop() << endl;
    cout << queue->peak() << endl;
    
    delete list;
    delete stack;
    delete queue;

    return 0;
}
```

**Output:**
```
LinkedList
4 1 2 3 
1 2 
2
Stack
4
3
2
Queue
1
2
3
```

### Data Constraints

保证模板参数`T`有默认构造函数、拷贝构造函数，支持流输出运算符

**由于模板参数T有可能仅支持通过流输出运算符进行输出，你的 print() 函数应当使用cout进行输出。**

数据点：

| 数据点 | 特殊性质                        |
| ------ | ------------------------------- |
| 1-2    | 仅测试`LinkedList`的非虚函数    |
| 3      | 仅测试`Queue`                   |
| 4      | 仅测试`Stack`                   |
| 5      | 无限制                          |
| 6-10   | 与1-5相同，但增加内存泄漏的检查 |

## Resource Limits

- **Time Limit**: 10000 ms
- **Memory Limit**: 488 MiB

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 10000 ms
- **Memory Limit (per test case)**: 488 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/113/data_test/`.

## Submission Requirements

### Submission Format

Submit a single C++ source file to the Online Judge. The OJ provides its own `main.cpp` which `#include "src.hpp"`. Your submission will be written to `src.hpp` and compiled together with the OJ's driver code.

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
