#include<stdio.h>
#include<string>
#define GET_ARRAY_LEN(arr, len)  { len  = (sizeof(arr) / sizeof(arr[0])); }

int* regular_brick(int brick[]) {
	//将当前数组规则化，去掉其中的0元素，按顺序排列
	return brick_reg;
}


int subroutine_calculate_energy(int hand_brick_less[]){
// 计算势能   牌数是1 4 7 10 13
	int potential_energy = 0;      //牌面势能
	int length_brick;				//牌面有效长度
	int *hand_brick;				//手牌数组
	int dis_price;					//前后两张牌的差
	int i;
	for (i = 1; i <= 13; i++) {
		if (hand_brick_less(i)>0)
			hand_brick(i) = hand_brick_less(i);
	}
	// 24  1
	// 23  2
	// 22  3
	GET_ARRAY_LEN(hand_brick, length_brick);
	for (i = 2; i <= length_brick; i++) {
		dis_price = hand_brick(i) - hand_brick(i - 1);
		if (dis_price<3)
			potential_energy = potential_energy + 3 - dis_price;
	}

	return potential_energy;
}


int subroutine_out_of_brick(int hand_brick_more[]){
// 1 2 3 9   21 22 23 29    41 42 43 49

	for (i = 1; i <= 14; i++) {
		if (hand_brick_more(i)>0)
			hand_brick_temp(i) = hand_brick_more(i);
	}
	GET_ARRAY_LEN(hand_brick_temp, length_brick)

	for (i = 1; i <= length_brick; i++) {
		hand_brick = hand_brick_temp;
		hand_brick(i) = [];
	}


	return out_brick;
}


string AI(char* get_char, int* hand_brick_less_old, char* brick_desk){
	if char[4] = 0
	// 庄家发牌
	//判断有没有要弯杠或者直杠或者胡牌
	//判断出牌
	if char[4] == 1
	// 某人打牌
	//     判断是否碰杠胡


	if char[4] == 2
	// 某人胡牌
	//     返回空值
	if char[4] == 3
	// 某人暗杠
	//     返回空值
	if char[4] == 4
	// 某人实际碰牌
	//     返回空值
	if char[4] == 5
	// 某人实际弯杠
	//     返回空值
	if char[4] == 6
	// 某人实际直杠
	//     返回空值


	if char[4] == 7
	// 某人想碰牌
	//     返回胡牌或空值
	if char[4] == 8
	// 某人想弯杠
	//     返回胡牌或空值
	if char[4] == 9
	//某人想直杠
	return out_char;
}


string majiang_main(char* get_char) {
	//定义静态数组  手牌，碰杠牌，


	return out_char;
}


