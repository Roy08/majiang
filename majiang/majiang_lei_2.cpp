#include<iostream>
#include<stdio.h>
#include<string>
#include <cstring>
#include <math.h>
using namespace std;

class AI
{
public:
	string respond_table(string message) {}              //接受信息返回信息的，最高层函数
	bool hupai() {}     //将自己的牌，与别人的出牌判断是否胡牌
	bool hupai2() {}					//基本同上
	void tingpai() {}				//判断自己听哪张牌，将听得牌都返回
	bool pengpai() {}	//判断是否要碰牌
	bool zhigangpai() {}	//判断自己是否要直杠牌
	bool wangangpai() {}  //判断自己是否要弯杠牌
	double calculate_energy() {}    //计算当前牌面的势能函数
	double calculate_energy_max() {}  //计算当前牌面不论出哪张牌，能达到的最大势能
	int remain() {}					//计算当前牌组剔除后还有几张，是胡牌函数的小函数
	int chupai() {}					//判断该出哪张牌

private:
	int m_hand_brick[30];						//手牌数组，较少时，如13,10,7,4,1
	int m_hand_brick_temp[30];
	int m_clear_brick[30];							//桌面碰杠牌
	int m_tingpai[30]
	int m_chupai
		//后面的暂时还没用上
	int m_desk_brick[30];							//桌面上已经出现了的牌
	int m_xia_chupai[30];							//三个对手出的牌
	int m_dui_chupai[30];
	int m_shang_chupai[30];
	int m_anpai[30];								//剩下的还从来没见过的牌

};

string respond_table(string message) 
{



}




double AI::calculate_energy()
{
	double energy = 0;
	int temp;
	for (i = 1; i <= 29; i++)
	{
		energy += 0.1*m_hand_brick[i];
	}
	for (i = 1; i <= 29; i++)
	{
		temp = m_hand_brick[i] * m_hand_brick[i - 1];
		energy += temp * 2;
	}
	for (i = 2; i <= 29; i++)
	{
		temp = m_hand_brick[i] * m_hand_brick[i - 2];
		energy += temp;
	}
	return energy;
}

double AI::calculate_energy_max()
{
	double energy = 0;
	double energy_max = 0;
	for (i = 1; i <= 29; i++)
	{
		if (m_hand_brick[i] > 0)
		{
			m_hand_brick[i] = m_hand_brick[i] - 1;
			energy = calculate_energy();
			if (energy > energy_max)
			{
				energy_max = energy;
			}
			m_hand_brick[i] = m_hand_brick[i] + 1;
		}
	}
	return energy_max;
}

int AI::chupai()
{
	double energy = 0;
	double energy_max = 0;
	int chupai = 1;
	for (i = 1; i <= 29; i++)
	{
		if (m_hand_brick[i] > 0)
		{
			m_hand_brick[i] = m_hand_brick[i] - 1;
			energy = calculate_energy();
			if (energy > energy_max)
			{
				energy_max = energy;
				chupai = i;
			}
			m_hand_brick[i] = m_hand_brick[i] + 1;
		}
	}
	return chupai;
}

bool AI::hupai(int hand_brick[])
{	
	int hand_brick_temp[30];
	memcpy(hand_brick_temp, hand_brick, 30);
	if (remain(hand_brick_temp) == 0) return true;
	for (i = 1; i <= 29; i++)
	{
		/*
		if (hand_brick_more[i] == 4)
		{
		hand_brick_more[i] = 0;
		if (hupai(hand_brick_more[])) return true;
		hand_brick_more[i] = 4;
		}
		*/
		if (m_hand_brick_temp[i] >= 3)
		{
			m_hand_brick_temp[i] = m_hand_brick_temp[i] - 3;
			if (hupai()) return true;
			m_hand_brick_temp[i] = m_hand_brick_temp[i] + 3;
		}
		if (m_hand_brick_temp[i] >= 2)
		{
			m_hand_brick_temp[i] = m_hand_brick_temp[i] - 2;
			if (hupai()) return true;
			m_hand_brick_temp[i] = m_hand_brick_temp[i] + 2;
		}
		if (i <= 27)
		{
			if (m_hand_brick_temp[i] * m_hand_brick_temp[i + 1] * m_hand_brick_temp[i + 2] > 0)
			{
				m_hand_brick_temp[i] -= 1;
				m_hand_brick_temp[i + 1] -= 1;
				m_hand_brick_temp[i + 2] -= 1;
				if (hupai()) return true;
				m_hand_brick_temp[i] += 1;
				m_hand_brick_temp[i + 1] += 1;
				m_hand_brick_temp[i + 2] += 1;
			}
		}
	}
	return false;

}

bool AI::hupai2()
{
	m_hand_brick_temp[m_chupai] += 1;
	if (huipai())
	{
		m_hand_brick_temp[m_chupai] -= 1;
		return true;
	}
	else
	{
		m_hand_brick_temp[m_chupai] -= 1;
		return false;
	}
}

int AI::remain()
{
	int num = 0;
	for (i = 1; i <= 29; i++)
	{
		num += m_hand_brick_temp[i];
	}
	return num;
}

void AI::tingpai()
{
	for (i = 1; i <= 29; i++)
	{
		m_tingpai[i] = 0;
		if (i == 10 || i == 20)  continue;
		m_chupai = i;
		memcpy(m_hand_brick_temp, m_hand_brick, sizeof(m_hand_brick));
		if (hupai2())
		{
			m_tingpai[i] = 1;
		}
	}
}











