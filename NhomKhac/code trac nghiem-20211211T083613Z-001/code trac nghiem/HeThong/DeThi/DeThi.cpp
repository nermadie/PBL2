#pragma once
#include "DeThi.h"

DeThi::DeThi()
{

}

DeThi::DeThi(int soCau, string id, string* cauHoi, string* dapAnA, string* dapAnB, string* dapAnC, string* dapAnD, char* dapAn)
{
    this->soCau = soCau;
    this->id = id;
    this->cauHoi = cauHoi;
    this->dapAnA = dapAnA;
    this->dapAnB = dapAnB;
    this->dapAnC = dapAnC;
    this->dapAnD = dapAnD;
    this->dapAn = dapAn;
}

DeThi::~DeThi()
{

}

int DeThi::getSoCau()
{
    return this->soCau;
}

string DeThi::getId()
{
    return this->id;
}

string* DeThi::getCauHoi()
{
    return this->cauHoi;    
}

string* DeThi::getDapAnA()
{
    return this->dapAnA;
}

string* DeThi::getDapAnB()
{
    return this->dapAnB;
}

string* DeThi::getDapAnC()
{
    return this->dapAnC;
}

string* DeThi::getDapAnD()
{
    return this->dapAnD;
}

char* DeThi::getDapAn()
{
    return this->dapAn;
}

string DeThi::getCauHoi(int vt)
{
    return this->cauHoi[vt];
}

string DeThi::getDapAnA(int vt)
{
    return this->dapAnA[vt];
}

string DeThi::getDapAnB(int vt)
{
    return this->dapAnB[vt];
}

string DeThi::getDapAnC(int vt)
{
    return this->dapAnC[vt];
}

string DeThi::getDapAnD(int vt)
{
    return this->dapAnD[vt];
}

char DeThi::getDapAn(int vt)
{   
    return this->dapAn[vt];
}

void DeThi::setCauHoi(string* cauHoi)
{
    this->cauHoi = cauHoi;
}

void DeThi::setDapAnA(string* dapAnA)
{
    this->dapAnA = dapAnA;
}

void DeThi::setDapAnB(string* dapAnB)
{
    this->dapAnB = dapAnB;
}

void DeThi::setDapAnC(string* dapAnC)
{
    this->dapAnC = dapAnC;
}

void DeThi::setDapAnD(string* dapAnD)
{
    this->dapAnD = dapAnD;
}

void DeThi::setDapAn(char* dapAn)
{
    this->dapAn = dapAn;
}

void DeThi::setCauHoi(string cauHoi, int vt)
{
    this->cauHoi[vt] = cauHoi;
}

void DeThi::setDapAnA(string dapAnA, int vt)
{
    this->dapAnA[vt] = dapAnA;
}

void DeThi::setDapAnB(string dapAnB, int vt)
{
    this->dapAnB[vt] = dapAnB;
}

void DeThi::setDapAnC(string dapAnC, int vt)
{
    this->dapAnC[vt] = dapAnC;
}

void DeThi::setDapAnD(string dapAnD, int vt)
{
    this->dapAnD[vt] = dapAnD;
}

void DeThi::setDapAn(char dapAn, int vt)
{
    this->dapAn[vt] = dapAn;
}

