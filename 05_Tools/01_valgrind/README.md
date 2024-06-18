<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-06-18 14:13:56
 * @LastEditors: Clark
 * @LastEditTime: 2024-06-18 14:23:14
 * @Description: file content
-->

# Valgrind

# 官网
https://valgrind.org/

# 官网文档
https://valgrind.org/docs/manual/manual-core.html#manual-core.suppress

suppressions 参数告诉valgrind忽略指定的错误
{
    ignore_cond_libs
    Memcheck:Cond    ...
    fun:nginx_main    ...
}
{
    ignore_leak_libs
    Memcheck:Leak    ...
    fun:nginx_main    ...
}

第一行为过滤描述，随便写
第二行为忽略的类型，Memcheck有7中类型，分别为Cond，Jump, Param, Free, Overlap, Leak, Value1~16, Addr1~16。
最后一部分为忽略条件。

# valgrind包括工具如下：

memcheck ：检查程序中的内存问题，如泄漏、越界、非法指针等。能够侦测到如下问题。 ①使用未初始化的内存  ②读/写已经被释放的内存  ③读/写内存越界  ④读/写不恰当的内存栈空间  ⑤内存泄漏  ⑥使用 malloc 和 free 不匹配 等。

callgrind：检测程序代码的运行时间和调用过程，以及分析程序性能。和gprof不同，它不需要在编译源代码时附加特殊选项，但加上调试选项是推荐的。Callgrind收集程序运行时的一些数据，建立函数调用关系图，还可以有选择地进行cache模拟。在运行结束时，它会把分析数据写入一个文件。callgrind_annotate可以把这个文件的内容转化成可读的形式。

cachegrind：cache分析器；分析CPU的cache命中率、丢失率，用于进行代码优化。它模拟CPU中的一级缓存和二级缓存，能够精确地指出程序中cache的丢失和命中。如果需要，它还能够为我们提供cache丢失次数、内存引用次数、以及每行代码、每个函数、每个模块、整个程序产生的指令数。这对优化程序有很大的帮助。

helgrind：用于检查多线程程序的竞态条件。Helgrind寻找内存中被多个线程访问，而又没有加锁的区域，这些区域往往是线程之间失去同步的地方，而且会导致难以发掘的错误。Helgrind实现了名为“Eraser”的竞争检测算法，并做了进一步改进，减少了报告错误的次数。不过，Helgrind仍然处于实验阶段。

DRD：另一个线程错误检测器。和helgrind类似但是使用了不同的技术，所以或许能找到helgrind找不到的问题。

massif：堆栈分析器，指示程序中使用了多少堆内存等信息。

DHAT：另一个堆分析器。它有助于理解块(block)的生命周期、块的使用和布局的低效等问题。
