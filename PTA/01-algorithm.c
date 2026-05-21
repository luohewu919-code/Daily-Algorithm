//01-递归求阶乘和: 1! + 2! + ... + n!
double fact(int n) {
	if (n == 0 || n == 1) {
		return 1;	//递归的终止条件：0! = 1! = 1
	}
	return n * fact(n - 1);	//执行条件
}
//递推与回溯的理解：
//比如说n = 5；
//（向下）递推：
//fact(4) -> fact(3) -> fact(2) -> fact(1)
//递推到哪里，取决于结束条件
//(向上）回溯：
//fact(1)返回 1
//fact(2)返回 2 * 1 = 2
//fact(3)返回 3 * 2 = 6
//fact(4)返回 4 * 5 = 24
//其实，所谓的递推，其实是一种入栈
//不同于直接返回递推，比如return fact(n - 1)
//该题采用return n * fact(n - 1),这种首先拿到fact（n - 1)的结果，然后再返回


double factsum(int n) {
	double sum = 0;	//类型
	for (int i = 1; i <= n; i++) {
		sum += fact(i);
	}
	return sum;
}
//易错点：
//1.递归一定要明确终止条件
//2.特别是求和的类型，一定要清楚

//02-递归实现指数函数
double calc_pow(double x, int n) {
	if (n == 0) {
		return 1;
	}
	double result = x;
	return x * calc_pow(x, n - 1);
}

//03-递归计算P函数
double P(int n, double x) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
	//小细节：
	//1.C语言,"[ ]"只能访问数组，所以数学上面的[]写成()
	//2.C语言，2n = 2 * n;不要直接写2n
}

//04-递归实现顺序输出整数
//5432:5_4_3_2
void printdigits(int n) {
	if (n < 10) {
		printf("%d\n", n);
		return;
	}
	printdigits(n / 10);
	printf("%d\n", n % 10);
}
//递归 = 循环 + 栈
//也就是体现：递推和回溯两个方面
//当然，回溯不一定都会体现，主要是有两个条件，即就是，第一个循环
//分析5432：
//递推：
//printdigits(5432)	第一层
//printdigits(5432 / 10 = 543)	第二层
//printdigits(543 / 10 = 54)	第三层
//printdigits(54 / 10 = 5)	第四层
//回溯：
//第四层：打印5
//第三层：打印4
//第二层：打印3
//第一层：打印2
//解题思路：获取每一位数，本质就是利用除法与求模运算，得到每一位数
//解题步骤：
//1.首先从位数出发，如果只有个位数，直接输出打印，因为获得每一位上的数字，主要使用先除法，后求模
//	但是，如果说只是一个个位数，该数字除以10，只能得到0，所以不太行
//2.不断除以10，拆解层次(本身就是一种递推)
//3.利用求模，得到最低位上面的数字

//递归求简单交错幂级数的部分和
double fn(double x, int n) {
	if (n == 0) {
		return 0;
	}
	double temp = pow(x, n);
	if (n % 2 == 0) {
		temp = -temp;
	}
	return temp + fn(x, n - 1);
}
