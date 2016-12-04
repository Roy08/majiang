
#include<string>



using namespace std;


class AI
{
public:
	string respond_table(string message);      //������Ϣ������Ϣ�ģ���߲㺯��
	AI(int);


private:
	bool hupai(int hand_brick[], int chupai);    //���Լ����ƣ�����˵ĳ����ж��Ƿ����
	bool hupai(int hand_brick[]);				//����ͬ��
	void tingpai(int hand_brick[]);				//�ж��Լ��������ƣ��������ƶ�����
	bool pengpai(int hand_brick[], int chupai);	//�ж��Ƿ�Ҫ����
	bool zhigangpai(int hand_brick[], int chupai);	//�ж��Լ��Ƿ�Ҫֱ����
	bool wangangpai(int hand_brick[], int mopai);  //�ж��Լ��Ƿ�Ҫ�����
	int angangpai(int hand_brick[]);
	double calculate_energy(int hand_brick[]);   //���㵱ǰ��������ܺ���
	double calculate_energy_max(int hand_brick[]);  //���㵱ǰ���治�۳������ƣ��ܴﵽ���������
	int remain(int hand_brick[]);				//���㵱ǰ�����޳����м��ţ��Ǻ��ƺ�����С����
	int chupai(int hand_brick[]);				//�жϸó�������
	void set_quepai(int hand_brick[]);


	int m_hand_brick[30];						//�������飬����ʱ����13,10,7,4,1
	int m_clear_brick[30];							//�Լ�������������
	int m_tingpai[30];
	int m_guopai = 0;
	int m_jiang_num = 0;
	int m_chupai_other;
	int m_chupai_self;
	int m_identity;
	double m_daque[30];                              //��ȱȨ��
	int m_anpai[30];								//ʣ�µĻ�����û��������
													//�������ʱ��û����
	int m_desk_brick[30];							//�������Ѿ������˵���
	int m_xia_chupai[30];							//�������ֳ�����
	int m_dui_chupai[30];
	int m_shang_chupai[30];

};

