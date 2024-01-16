//
// Created by austsxk on 2024/1/16.
//

#ifndef CLASS_REBUILDCOMPUTER_H
#define CLASS_REBUILDCOMPUTER_H

#endif //CLASS_REBUILDCOMPUTER_H

// 组装电脑案例进行多态练习
// 需求: 有三种类型的组件CPU、内存、显卡
//      可以由多个厂商生产上面的组件
//      可自由组合组件
//      电脑正常工作

#include <string>
#include <iostream>
using namespace std;

namespace RebuildComputer
{
    // 由于组件可以由多个厂商生产,所以可以是抽象类
    class AbstractCPU
    {
    public:
        virtual void calculate() = 0;
    };

    class AbstractVideoCard
    {
    public:
        virtual void display() = 0;
    };

    class AbstractMemory
    {
    public:
        virtual void storage() = 0;
    };

    // 定义一个计算机类 由三个抽象组成
    class Computer {
    private:
        AbstractCPU* cpu;
        AbstractVideoCard* vc;
        AbstractMemory* am;
    public:
        void work();
        ~Computer();
        Computer(AbstractCPU* c, AbstractVideoCard* v, AbstractMemory* m);
    };

    // 定义实现的厂商
    // Inter
    class InterCPU: public AbstractCPU
    {
    public:
        virtual void calculate() override;
    };

    class InterVC: public AbstractVideoCard
    {
    public:
        virtual void display() override;
    };

    class InterMem: public AbstractMemory
    {
    public:
        virtual void storage() override;
    };

    // ASUS
    class ASUSCPU: public AbstractCPU
    {
    public:
        virtual void calculate() override;
    };

    class ASUSVC: public AbstractVideoCard
    {
    public:
        virtual void display() override;
    };

    class ASUSMem: public AbstractMemory
    {
    public:
        virtual void storage() override;
    };

    void testRebuildComputer();
}