#include<iostream>
#include<stdio.h>
#include<string>
#include <math.h>
using namespace std;

class AI
{
public:
	string respond_table(string message){}              //接受信息返回信息的，最高层函数
	bool hupai(int hand_brick_less[],int chupai) {}     //将自己的牌，与别人的出牌判断是否胡牌
	bool hupai(int hand_brick_more[]){}					//基本同上
	void tingpai(int hand_brick_less[],int tingpai[]){}				//判断自己听哪张牌，将听得牌都返回
	bool pengpai(int hand_brick_less[],int chupai){}	//判断是否要碰牌
	bool zhigangpai(int hand_brick_less[],int chupai){}	//判断自己是否要直杠牌
	bool wangangpai(int hand_brick_less[],int clear_brick[],int mopai){}  //判断自己是否要弯杠牌
	double calculate_energy(int hand_brick_less[]){}    //计算当前牌面的势能函数
	double calculate_energy_max(int hand_brick_more[]){}  //计算当前牌面不论出哪张牌，能达到的最大势能
	int remain(int hand_brick_now[]){}					//计算当前牌组剔除后还有几张，是胡牌函数的小函数
	int chupai(int hand_brick_more[]){}					//判断该出哪张牌

private:
	int m_hand_brick_less[30];						//手牌数组，较少时，如13,10,7,4,1
	int m_hand_brick_more[30];						//手牌数组，交多时，如14,11,8,5,2
	int m_clear_brick[30];							//桌面碰杠牌
	int m_tingpai[30]
			//后面的暂时还没用上
	int m_desk_brick[30];							//桌面上已经出现了的牌
	int m_xia_chupai[30];							//三个对手出的牌
	int m_dui_chupai[30];
	int m_shang_chupai[30];
	int m_anpai[30];								//剩下的还从来没见过的牌

};


double AI::calculate_energy(int hand_brick_less[])
{
	double energy = 0;
	int temp
	for (i = 1; i <= 29; i++) 
	{
		energy += 0.1*hand_brick_less[i];
	}
	for (i = 1; i <= 29; i++)
	{
		temp = hand_brick_less[i] * hand_brick_less[i - 1];
		energy += temp * 2;
	}
	for (i = 2; i <= 29; i++)
	{
		temp = hand_brick_less[i] * hand_brick_less[i - 2];
		energy += temp;
	}
	return energy;
}

double AI::calculate_energy_max(int hand_brick_more[])
{
	double energy=0;
	double energy_max = 0;
	for (i = 1; i <= 29; i++)
	{
		if (hand_brick_more[i] > 0)
		{
			hand_brick_more [i]= hand_brick_more[i]-1;
			energy = calculate_energy(hand_brick_more);
			if (energy > energy_max)
			{
				energy_max = energy;
			}
			hand_brick_more[i] = hand_brick_more[i] + 1;
		}
	}
	return energy_max;
}

int AI::chupai(int hand_brick_more[])
{
	double energy = 0;
	double energy_max = 0;
	int chupai=1;
		for (i = 1; i <= 29; i++)
		{
			if (hand_brick_more[i] > 0)
			{
				hand_brick_more[i] = hand_brick_more[i] - 1;
				energy = calculate_energy(hand_brick_more);
				if (energy > energy_max)
				{
					energy_max = energy;
					chupai = i;
				}
				hand_brick_more[i] = hand_brick_more[i] + 1;
			}
		}
	return chupai;
}

bool AI::hupai(int hand_brick_more[]) 
{
	if (remain(hand_brick_more[]) == 0) return true;
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
		if (hand_brick_more[i] >= 3)
		{
			hand_brick_more[i] = hand_brick_more[i] - 3;
			if (hupai(hand_brick_more[])) return true;
			hand_brick_more[i] = hand_brick_more[i] + 3;
		}
		if (hand_brick_more[i] >= 2)
		{
			hand_brick_more[i] = hand_brick_more[i] - 2;
			if (hupai(hand_brick_more[])) return true;
			hand_brick_more[i] = hand_brick_more[i] + 2;
		}
		if (i <= 27)
		{
			if (hand_brick_more[i] * hand_brick_more[i + 1] * hand_brick_more[i + 2] > 0)
			{
				hand_brick_more[i] -= 1;
				hand_brick_more[i+1] -= 1;
				hand_brick_more[i+2] -= 1;
				if (hupai(hand_brick_more[])) return true;
				hand_brick_more[i] += 1;
				hand_brick_more[i + 1] += 1;
				hand_brick_more[i + 2] += 1;
			}
		}
	}
	return false;

}

bool AI::hupai(int hand_brick_less[], int chupai)
{
	hand_brick_less[chupai] += 1;
	return huipai(hand_brick_less[]);
}

int AI::remain(int hand_brick_now[])
{
	int num = 0;
	for (i = 1; i <=29; i++)
	{
		num += hand_brick_now[i];
	}
	return num;
}

void AI::tingpai(int hand_brick_less[]) 
{
	for (i = 1; i <= 29; i++)
	{
		m_tingpai[i] = 0;
		if (i == 10 || i == 20)  continue;
		if (hupai(hand_brick_less, i))
		{
			m_tingpai[i] = 1;
		}
	}
	
}











