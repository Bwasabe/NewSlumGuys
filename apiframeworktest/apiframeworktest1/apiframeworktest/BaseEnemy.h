#pragma once
#include "Object.h"
class FaceObj;
class Image;
class BaseEnemy :
    public Object
{
public:
    BaseEnemy(class PlayerManager* mgr);
    virtual ~BaseEnemy();

private:
    CLONE(BaseEnemy);

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther) override;

public:
    virtual void ExecutePattern();

public:
    void        SetPattern(int pattern) { m_iPattern = pattern; }
    int         GetPattern() { return m_iPattern; }
    void        SetHP(int hp) { m_hp = hp; }
    int         GettHP() { return m_hp; }
    
private:
    Image*      m_gasiImage;
    int         m_iPattern = 0;
    int         m_hp;
    bool        m_bIsCanChangePattern = true;
    bool        m_bIsRemove;
    
private:
    FaceObj*    m_FaceObject;

    PlayerManager* m_pPlayerMgr;

    vector<class BaseCircle*> m_vPatternObjs;
};

