/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-05-20 13:49:49
 * @LastEditors: Clark
 * @LastEditTime: 2024-05-20 14:30:45
 * @Description: file content
 */


/*
OpenMP(Open Multi-Processing)是一种共享内存编程模式，多线程并行应用程序界面，使用C，C++和Fortran语言。
由两种形式实现并行功能：编译指导语句和运行时库函数。编译指导语句告诉程序何时开始并行，库函数用来设置线程数及实现其它并行功能。

OpenMP 是一种应用程序编程接口（API），用于创建和管理共享内存多线程并行程序。它允许程序员使用高层次的指令将并行性添加到应用程序中，而无需显式管理线程。

主要特性：

线程管理：OpenMP 提供指令来创建和管理线程，并行化循环、部分和区域。
数据共享：它支持共享内存编程模型，允许线程访问和修改同一内存空间。
同步机制：OpenMP 提供各种同步机制，例如锁、屏障和原子操作，以确保线程之间的正确执行。
负载平衡：它包含用于负载平衡的调度策略，以优化并行性能。
移植性：OpenMP 是一个跨平台的 API，可以在各种系统（包括 Linux、Windows 和 macOS）上使用。
优点：

易用性：OpenMP 使用简单的指令和注释，使并行编程变得容易。
性能提升：通过利用多核处理器的并行性，OpenMP 可以显着提高程序性能。
可移植性：跨平台兼容性允许在不同系统上部署 OpenMP 程序。
社区支持：OpenMP 有一个活跃的社区，提供文档、教程和支持。
缺点：

调试复杂度：由于并行性，调试 OpenMP 程序可能比调试串行程序更具挑战性。
数据竞争：在共享内存模型中，如果不使用适当的同步，可能会出现数据竞争。
可扩展性限制：OpenMP 主要适用于共享内存系统，并且在分布式内存系统上的可扩展性可能有限。
应用：

OpenMP 广泛用于各种并行应用程序，包括：

科学计算
数据分析
图形处理
机器学习

*/

#include <cstdio>
#include <iostream>
#include <omp.h>//调用Openmp库函数

int main(int argc, char *argv[])
{
    int index = 0;
    printf ("*Hello World! Thread: %d\n", omp_get_thread_num());

    // omp_set_num_threads(3);          // 设置线程数
    int pnum=omp_get_num_procs();       // 获取CPU核数
    std::cout << "Thread_pnum =" << pnum << std::endl;

    #pragma omp parallel for num_threads(3) // 指定线程数
    // #pragma omp parallel for // 默认使用全部线程数
    for (int i = 0; i < 100; ++i)
    {
        printf ("Hello World!  Thread: %d, i: %d index[%d]\n", omp_get_thread_num(), i, index++);
    }

    return 0;
}

// gcc -fopenmp Hello_World_omp.c -o hw_opmp

/*
schedule(type, size)

1.static
不用size参数时分配给每个程序的都是n/t次连续迭代，n为迭代次数，t为并行的线程数目。
#pragma omp parallel for schedule(static)

2.dynamic
动态调度模式是先到先得的方式进行任务分配，不用size参数的时候，先把任务干完的线程先取下一个任务，
以此类推，而不是一开始就分配固定的任务数。使用size参数的时候，分配的任务以size为单位，一次性分配size个。
虽然很智能，在任务难度不均衡的时候适合用dynamic，否则会引起过多的任务动态申请的开销。

3.guided
刚开始每个线程会分配到比较大的迭代块，后来分配到的迭代块逐渐递减，没有指定size就会降到1，否则降到size。

4.runtime
运行时调度策略允许 OpenMP 运行时在执行期间动态调整迭代分配，以优化性能。
运行时会根据系统负载、可用线程和循环特征（如迭代数）做出最佳调度决策。

*/
