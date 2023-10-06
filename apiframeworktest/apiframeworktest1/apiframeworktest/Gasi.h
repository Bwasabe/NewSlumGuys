#pragma once
#include "Object.h"

class Image;
class Gasi :
    public Object
{
private:
    Image* m_gasiImage;

public:
    // Object��(��) ���� ��ӵ�
    void Render(HDC _dc) override;
    virtual void Update() override;
    CLONE(Gasi);
public:
    Gasi();
    ~Gasi();
};

