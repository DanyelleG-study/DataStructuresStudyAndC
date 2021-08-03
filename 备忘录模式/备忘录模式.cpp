#include <iostream>
using namespace std;

class RoleStateMemento
{
public:
	RoleStateMemento(unsigned iBlood, unsigned iAttack, unsigned iDefense) : m_iBlood(iBlood), m_iAttack(iAttack), m_iDefense(iDefense) {}

private:
	friend class GameRole;

	unsigned GetBloodValue() { return m_iBlood; }
	unsigned GetAttackValue() { return m_iAttack; }
	unsigned GetDefenseValue() { return m_iDefense; }
	void SetBloodValue(unsigned b) { m_iBlood = b; }
	void SetAttackValue(unsigned a) { m_iAttack = a; }
	void SetDefenseValue(unsigned d) { m_iDefense = d; }
	unsigned m_iBlood;   // 生命力
	unsigned m_iAttack;  // 攻击力
	unsigned m_iDefense; // 防御力
};

class GameRole
{
public:
	GameRole() : memento(new RoleStateMemento(100,100,100))
	{
	}
	// 存档
	RoleStateMemento *SaveState() { return new RoleStateMemento(memento->GetBloodValue(), memento->GetAttackValue(), memento->GetDefenseValue()); }

	// 恢复存档
	void RecoveryState(RoleStateMemento *pRoleState)
	{
		memento->SetBloodValue(pRoleState->GetBloodValue());
		memento->SetAttackValue(pRoleState->GetAttackValue());
		memento->SetDefenseValue(pRoleState->GetDefenseValue());
		cout << "Recovery..." << endl;
	}

	void ShowState()
	{
		cout << "Blood:" << memento->GetBloodValue() << endl;
		cout << "Attack:" << memento->GetAttackValue()<< endl;
		cout << "Defense:" << memento->GetDefenseValue() << endl;
	}

	void Fight()
	{
		memento->SetBloodValue(memento->GetBloodValue()-100);
		memento->SetAttackValue(memento->GetAttackValue()-10);
		memento->SetDefenseValue(memento->GetDefenseValue()-20);

		if (memento->GetBloodValue() == 0)
		{
			cout << "Game Over" << endl;
		}
	}

private:
	RoleStateMemento *memento;
};

class RoleStateCaretaker
{
public:
	void SetRoleStateMemento(RoleStateMemento *pRoleStateMemento) { m_pRoleStateMemento = pRoleStateMemento; }
	RoleStateMemento *GetRoleStateMemento() { return m_pRoleStateMemento; }

private:
	RoleStateMemento *m_pRoleStateMemento;
};

int main()
{
	GameRole *pLiXY = new GameRole(); // 创建李逍遥这个角色
	pLiXY->ShowState(); // 显示初始的状态

	// 存档
	RoleStateCaretaker *pRoleStateCaretaker = new RoleStateCaretaker();
	pRoleStateCaretaker->SetRoleStateMemento(pLiXY->SaveState());

	// 开始打大BOSS
	pLiXY->Fight();
	pLiXY->ShowState();

	// 读档，从新开始
	pLiXY->RecoveryState(pRoleStateCaretaker->GetRoleStateMemento());
	pLiXY->ShowState();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
