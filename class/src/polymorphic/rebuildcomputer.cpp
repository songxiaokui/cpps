//
// Created by austsxk on 2024/1/16.
//

#include "rebuildcomputer.h"

namespace RebuildComputer {


    void Computer::work() {
        this->cpu->calculate();
        this->vc->display();
        this->am->storage();
    }

    Computer::~Computer() {
        if (this->cpu) {
            delete this->cpu;
            this->cpu = nullptr;
        }
        if (this->vc) {
            delete this->vc;
            this->vc = nullptr;
        }
        if (this->am) {
            delete this->am;
            this->am = nullptr;
        }
    }

    Computer::Computer(AbstractCPU *c, AbstractVideoCard *v, AbstractMemory *m) {
        this->cpu = c;
        this->vc = v;
        this->am = m;
    }


    // 定义实现的厂商
    // Inter
    void InterCPU::calculate() {
        cout << "Inter CPU 正在计算..." << endl;
    }

    void InterVC::display() {
        cout << "Inter 显卡 正在渲染..." << endl;
    }

    void InterMem::storage() {
        cout << "Inter 内存 正在存储..." << endl;
    }

    // 华硕
    void ASUSCPU::calculate() {
        cout << "华硕 CPU 正在计算..." << endl;
    }

    void ASUSVC::display() {
        cout << "华硕 显卡 正在渲染..." << endl;
    }

    void ASUSMem::storage() {
        cout << "华硕 内存 正在存储..." << endl;
    }

    void testRebuildComputer() {
        // 组装全Inter
        Computer *c = new Computer(new InterCPU, new InterVC, new InterMem);
        c->work();
        delete c;

        // 组装全华硕
        Computer *c1 = new Computer(new ASUSCPU, new ASUSVC, new ASUSMem);
        c1->work();
        delete c1;

        // 组装混合
        Computer *c2 = new Computer(new ASUSCPU, new InterVC, new ASUSMem);
        c2->work();
        delete c2;
    }
}