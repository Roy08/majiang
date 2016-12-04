#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include"majiangAI.h"

using namespace std;



string AI::respond_table(string message)
{
	string respond="oooo";
	if (message[3] == 'o')
	{
		
		int fapai = 0;
		if (message[1] == 't')  fapai += 10;
		if (message[1] == 'w')  fapai += 20;
		fapai += message[2] - '0';
		m_anpai[fapai] -= 1;
		m_hand_brick[fapai]++;
		m_guopai++;
		set_quepai(m_hand_brick);
		if (m_guopai<14) {
			respond = "000g";
			return respond;
		}
		m_chupai_self = chupai(m_hand_brick);
		m_hand_brick[m_chupai_self] -= 1;
		respond[0] = m_identity + '0';
		if (m_chupai_self < 10) respond[1] = 'b';
		if (m_chupai_self <20 && m_chupai_self > 10) respond[1] = 't';
		if (m_chupai_self <30 && m_chupai_self > 20) respond[1] = 'w';
		respond[2] = m_chupai_self % 10 + '0';
		respond[3] = '1';
		return respond;
	}
	if (message[3] == '0')
	{
		
		int fapai = 0;
		if (message[1] == 't')  fapai += 10;
		if (message[1] == 'w')  fapai += 20;
		fapai += message[2] - '0';
		m_anpai[fapai] -= 1;
		m_hand_brick[fapai]++;
		m_guopai++;
		if (m_guopai<14) {
			respond = "000g";
			return respond;

		}
		if (hupai(m_hand_brick))
		{
			m_jiang_num = 0;
			respond[0]= m_identity + '0';
			respond[1] = message[1];
			respond[2] = message[2];
			respond[3] = '2';
			return respond;

		}
		int angang = angangpai(m_hand_brick);
		if (angang != 0)
		{
			m_clear_brick[fapai] = 4;
			m_hand_brick[fapai] = 0;
			respond[0] = m_identity + '0';
			if (fapai < 10) respond[1] = 'b';
			if (fapai <20 && fapai > 10) respond[1] = 't';
			if (fapai <30 && fapai > 20) respond[1] = 'w';
			respond[2] = fapai % 10 + '0';
			respond[3] = '3';
			return respond;
		}
		if (wangangpai(m_hand_brick, fapai))
		{
			m_hand_brick[fapai] = 0;
			respond[0] = m_identity + '0';
			if (fapai < 10) respond[1] = 'b';
			if (fapai <20 && fapai > 10) respond[1] = 't';
			if (fapai <30 && fapai > 20) respond[1] = 'w';
			respond[2] = fapai % 10 + '0';
			respond[3] = '8';
			return respond;

		}
		m_chupai_self = chupai(m_hand_brick);
		m_hand_brick[m_chupai_self] -= 1;
		respond[0] = m_identity + '0';
		if (m_chupai_self < 10) respond[1] = 'b';
		if (m_chupai_self <20 && m_chupai_self > 10) respond[1] = 't';
		if (m_chupai_self <30 && m_chupai_self > 20) respond[1] = 'w';
		respond[2] = m_chupai_self % 10 + '0';
		respond[3] = '1';
		return respond;
	}
	if (message[3] == '1')
	{
		m_chupai_other = 0;
		if (message[1] == 't')  m_chupai_other += 10;
		if (message[1] == 'w')  m_chupai_other += 20;
		m_chupai_other += message[2] - '0';
		m_anpai[m_chupai_other] -= 1;
		if (hupai(m_hand_brick, m_chupai_other))
		{
			m_jiang_num = 0;
			respond[0] = m_identity + '0';
			respond[1] = message[1];
			respond[2] = message[2];
			respond[3] = '2';
			return respond;
		}
		if (zhigangpai(m_hand_brick, m_chupai_other))
		{
			respond[0] = m_identity + '0';
			respond[1] = message[1];
			respond[2] = message[2];
			respond[3] = '9';
			return respond;
		}
		if (pengpai(m_hand_brick, m_chupai_other))
		{
			respond[0] = m_identity + '0';
			respond[1] = message[1];
			respond[2] = message[2];
			respond[3] = '7';
			return respond;
		}
		
		return "000g";
	}
	if (message[3] == '2')
	{
		int huipai_other = 0;
		if (message[1] == 't')  huipai_other += 10;
		if (message[1] == 'w')  huipai_other += 20;
		huipai_other += message[2] - '0';
		
		if ((huipai_other - m_chupai_other) == 0)
		{
			if (hupai(m_hand_brick, huipai_other))
			{
				m_jiang_num = 0;
				respond[0] = m_identity + '0';
				respond[1] = message[1];
				respond[2] = message[2];
				respond[3] = '2';
				return respond;
			}
			return "000g";
		}

		if ((huipai_other - m_chupai_self) == 0)
		{
			return "000g";
		}

		m_anpai[huipai_other] -= 1;
		return "000g";

	}
	if (message[3] == '3')
	{
		int gangpai = 0;
		if (message[1] == 't')  gangpai += 10;
		if (message[1] == 'w')  gangpai += 20;
		gangpai += message[2] - '0';
		m_anpai[gangpai] = 0;
		return "000g";

	}
	if (message[3] == '4')
	{
		int pengpai = 0;
		if (message[1] == 't')  pengpai += 10;
		if (message[1] == 'w')  pengpai += 20;
		pengpai += message[2] - '0';
		if (message[0] - '0' == m_identity)
		{
			m_hand_brick[pengpai] -= 2;
			m_clear_brick[pengpai] = 3;
			m_chupai_self = chupai(m_hand_brick);
			m_hand_brick[m_chupai_self] -= 1;
			respond[0] = m_identity + '0';
			if (m_chupai_self < 10) respond[1] = 'b';
			if (m_chupai_self <20 && m_chupai_self > 10) respond[1] = 't';
			if (m_chupai_self <30 && m_chupai_self > 20) respond[1] = 'w';
			respond[2] = m_chupai_self % 10 + '0';
			respond[3] = '1';
			return respond;

		}
		else
		{
			m_anpai[pengpai]-=2;
			return "000g";
		}
	}
	if (message[3] == '5')
	{
		int gangpai = 0;
		if (message[1] == 't')  gangpai += 10;
		if (message[1] == 'w')  gangpai += 20;
		gangpai += message[2] - '0';
		if (message[0] - '0' == m_identity)
		{
			m_clear_brick[gangpai] = 4;

		}

		m_anpai[gangpai] =0;
		return "000g";

	}
	if (message[3] == '6')
	{
		int gangpai = 0;
		if (message[1] == 't')  gangpai += 10;
		if (message[1] == 'w')  gangpai += 20;
		gangpai += message[2] - '0';
		if (message[0] - '0' == m_identity)
		{
			m_hand_brick[gangpai] -=3;
			m_clear_brick[gangpai] = 4;
			return "000g";

		}
		else
		{
			m_anpai[gangpai] = 0;
			return "000g";
		}


	}
	if (message[3] == '7'|| message[3] == '8' || message[3] == '9')
	{
		int pai_other = 0;
		if (message[1] == 't')  pai_other += 10;
		if (message[1] == 'w')  pai_other += 20;
		pai_other += message[2] - '0';
		if (hupai(m_hand_brick, pai_other))
		{
			m_jiang_num = 0;
			respond[0] = m_identity + '0';
			respond[1] = message[1];
			respond[2] = message[2];
			respond[3] = '2';
			return respond;
		}
		return "000g";

	}
}

AI::AI(int identity) {
	int i = 0;
	m_guopai = 0;
	m_identity = identity;
	m_chupai_other = 0;
	m_chupai_self = 0;
	for (i = 0; i <= 29; i++)
	{
		m_hand_brick[i] = 0;
		m_clear_brick[i] = 0;
		m_tingpai[i] = 0;
		m_daque[i] = 0;
		m_desk_brick[i] = 0;
		m_xia_chupai[i] = 0;
		m_dui_chupai[i] = 0;
		m_shang_chupai[i] = 0;
		m_anpai[i] = 4;
	}
}

void AI::set_quepai(int hand_brick[])
{
	int i;
	int num[3] = { 0,0,0 };
	int iden=0;
	for (i = 0; i < 10; i++)   num[0] += hand_brick[i];
	for (i = 10; i < 20; i++)   num[1] += hand_brick[i];
	for (i = 20; i < 30; i++)   num[2] += hand_brick[i];
	if (num[1] < num[0])   iden = 1;
	if (num[2] < num[iden])  iden = 2;
	
	for (i = 0; i < 30; i++)
	{
		m_daque[i] = 1;
	}
	for (i = 0 + 10 * iden; i < 10 + 10 * iden; i++)
	{
		m_daque[i] = 0.01;
	}


	


}

double AI::calculate_energy(int hand_brick[])
{
	//  23445566689
	double energy = 0, temp;
	int  i;
	for (i = 1; i <= 29; i++)
	{
		energy += 0.1*hand_brick[i] * m_daque[i];
	}
	for (i = 1; i <= 29; i++)
	{
		temp = hand_brick[i] * hand_brick[i - 1] * m_daque[i];
		energy += temp * 2;
	}
	for (i = 2; i <= 29; i++)
	{
		temp = hand_brick[i] * hand_brick[i - 2] * m_daque[i];
		energy += temp;
	}
	for (i = 1; i <= 29; i++)
	{
		double k_energy = 0.5;
		if (hand_brick[i] > 0)
		{
			energy += k_energy*(m_anpai[i - 1] + m_anpai[i])*m_daque[i];
			if (i < 29)   energy += k_energy*m_anpai[i + 1] * m_daque[i];
		}
	}
	tingpai(hand_brick);
	int zhangshu = 0;
	for (i = 1; i <= 29; i++)
	{
		zhangshu += m_tingpai[i] * m_anpai[i];
	}
	energy += zhangshu * 10;
	return energy;
}

double AI::calculate_energy_max(int hand_brick[])
{
	double energy = 0;
	double energy_max = 0;
	int i;
	for (i = 1; i <= 29; i++)
	{
		if (hand_brick[i] > 0)
		{
			hand_brick[i] = hand_brick[i] - 1;
			energy = calculate_energy(hand_brick);
			if (energy > energy_max)
			{
				energy_max = energy;
			}
			hand_brick[i] = hand_brick[i] + 1;
		}
	}
	return energy_max;
}

int AI::chupai(int hand_brick[])
{
	double energy = 0;
	double energy_max = 0;
	int chupai = 0, i;
	for (i = 1; i <= 29; i++)
	{
		if (hand_brick[i] > 0)
		{
			hand_brick[i] = hand_brick[i] - 1;
			energy = calculate_energy(hand_brick);
			if (energy > energy_max)
			{
				energy_max = energy;
				chupai = i;
			}
			hand_brick[i] = hand_brick[i] + 1;
		}
	}
	return chupai;
}

bool AI::hupai(int hand_brick[])
{
	int hand_brick_temp[30];
	int i;
	memcpy(hand_brick_temp, hand_brick, 120);

	if (remain(hand_brick_temp) == 0)
	{
		if (m_jiang_num == 1 || m_jiang_num == 7)
		{
			m_jiang_num = 0;
			return true;
		}
		return false;
	}
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
		if (hand_brick_temp[i] >= 3)
		{
			hand_brick_temp[i] = hand_brick_temp[i] - 3;
			if (hupai(hand_brick_temp)) return true;
			hand_brick_temp[i] = hand_brick_temp[i] + 3;
		}
		if (hand_brick_temp[i] >= 2)
		{
			m_jiang_num += 1;
			hand_brick_temp[i] = hand_brick_temp[i] - 2;
			if (hupai(hand_brick_temp)) return true;
			m_jiang_num -= 1;
			hand_brick_temp[i] = hand_brick_temp[i] + 2;
		}
		if (i <= 27)
		{
			if (hand_brick_temp[i] * hand_brick_temp[i + 1] * hand_brick_temp[i + 2] > 0)
			{
				hand_brick_temp[i] -= 1;
				hand_brick_temp[i + 1] -= 1;
				hand_brick_temp[i + 2] -= 1;
				if (hupai(hand_brick_temp)) return true;
				hand_brick_temp[i] += 1;
				hand_brick_temp[i + 1] += 1;
				hand_brick_temp[i + 2] += 1;
			}
		}
	}
	return false;

}

bool AI::hupai(int hand_brick[], int chupai)
{
	int hand_brick_temp[30];
	memcpy(hand_brick_temp, hand_brick, 120);
	hand_brick_temp[chupai] += 1;
	return hupai(hand_brick_temp);
}

int AI::remain(int hand_brick_temp[])
{
	int num = 0, i;
	for (i = 1; i <= 29; i++)
	{
		num += hand_brick_temp[i];
	}
	return num;
}

void AI::tingpai(int hand_brick[])
{
	int i;
	for (i = 1; i <= 29; i++)
	{
		m_tingpai[i] = 0;
		if (i == 10 || i == 20)  continue;
		if (hupai(hand_brick, i))
		{
			m_jiang_num = 0;
			m_tingpai[i] = 1;
		}
	}

}

bool AI::pengpai(int hand_brick[], int chupai) 
{
	int hand_brick_temp[30];
	memcpy(hand_brick_temp, hand_brick, 120);
	double energy_peng = 0, energy_old = 0;
	energy_old = calculate_energy(hand_brick_temp);
	hand_brick_temp[chupai] -= 2;
	energy_peng = calculate_energy_max(hand_brick_temp)+5;
	if (energy_old > energy_peng)  return false;
	else   return true;

}

bool AI::zhigangpai(int hand_brick[], int chupai) 
{
	int hand_brick_temp[30];
	memcpy(hand_brick_temp, hand_brick, 120);
	if (hand_brick_temp[chupai] == 3) {
		double energy_gang = 0, energy_old = 0;
		energy_old = calculate_energy(hand_brick_temp);
		hand_brick_temp[chupai] -= 3;
		energy_gang = calculate_energy(hand_brick_temp) + 9;
		if (energy_old > energy_gang)  return false;
		else   return true;
	}
	return false;
}

bool AI::wangangpai(int hand_brick[], int mopai) 
{
	if (m_clear_brick[mopai] == 3)
	{
		int hand_brick_temp[30];
		memcpy(hand_brick_temp, hand_brick, 120);
		double energy_gang = 0, energy_no = 0;
		energy_no = calculate_energy_max(hand_brick_temp);
		hand_brick_temp[mopai] -= 1;
		energy_gang = calculate_energy(hand_brick_temp) + 4;
		
		
		if (energy_no > energy_gang)  return false;
		else   return true;
	}
	else return false;
	
}

int AI::angangpai(int hand_brick[]) 
{
	int i;
	for (i = 1; i <= 30; i++)
	{
		if (hand_brick[i] == 4) break;
	}
	if (i == 31)  return 0;
	int hand_brick_temp[30];
	memcpy(hand_brick_temp, hand_brick, 120);
	double energy_gang = 0, energy_no = 0;
	energy_no = calculate_energy_max(hand_brick_temp);
	hand_brick_temp[i] -= 4;
	energy_gang = calculate_energy(hand_brick_temp)+8;
	if (energy_no > energy_gang)  return false;
	else   return true;
}


