#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;


class AI
{
public:
	string respond_table(string message);      //接受信息返回信息的，最高层函数
	AI(int);


private:
	bool hupai(int hand_brick[], int chupai);    //将自己的牌，与别人的出牌判断是否胡牌
	bool hupai(int hand_brick[]);				//基本同上
	void tingpai(int hand_brick[]);				//判断自己听哪张牌，将听得牌都返回
	bool pengpai(int hand_brick[], int chupai);	//判断是否要碰牌
	bool zhigangpai(int hand_brick[], int chupai);	//判断自己是否要直杠牌
	bool wangangpai(int hand_brick[], int mopai);  //判断自己是否要弯杠牌
	int angangpai(int hand_brick[]);
	double calculate_energy(int hand_brick[]);   //计算当前牌面的势能函数
	double calculate_energy1(int hand_brick[]);
	double calculate_energy2(int hand_brick[]);
	double calculate_energy3(int hand_brick[]);
	double calculate_energy4(int hand_brick[]);
	double calculate_energy_for_residue(int hand_brick[]);
	double calculate_energy_max(int hand_brick[]);  //计算当前牌面不论出哪张牌，能达到的最大势能
	int remain(int hand_brick[]);				//计算当前牌组剔除后还有几张，是胡牌函数的小函数
	int chupai(int hand_brick[]);				//判断该出哪张牌
	void set_quepai(int hand_brick[]);
	bool daque(int hand_brick[]);


	int m_hand_brick[30];						//手牌数组，较少时，如13,10,7,4,1
	int m_clear_brick[30];							//自己的桌面碰杠牌
	int m_tingpai[30];
	int m_guopai = 0;
	int m_jiang_num = 0;
	double m_basic_sco ;
	double m_peng_sco;
	double m_zhigang_sco;
	double m_wangang_sco;
	double m_angang_sco;
	int m_chupai_other;
	int m_chupai_self;
	int m_identity;
	double m_dingque[30];                              //打缺权重
	int m_anpai[30];								//剩下的还从来没见过的牌
													//后面的暂时还没用上
	int m_desk_brick[30];							//桌面上已经出现了的牌
	int m_xia_chupai[30];							//三个对手出的牌
	int m_dui_chupai[30];
	int m_shang_chupai[30];

};

