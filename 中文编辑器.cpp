#include<iostream> 
#include<map>
#include<math.h>
using namespace std;

map<string,int>num;
map<int,string>R_num;
map<string,int>var;
int judge_num;
string op;
string equ = "等于";
string judge;
string op_var;
string op_var1;
string judg_var;
string judg_var1;
string judg_jump;
string op_var_val;

int change_to_num(string a) //一二三四 转化为 1234 
{
	int c;
	int j=0;
	for(int i=a.length()-2;i>=0;i-=2,j++){
		string s3(a,i,2);
		c+=num[s3]*pow(10,j);
	}
	return c;
}

string R_change_to_num(int c) //1234 转化为 一二三四
{
	string a;
	int i = 0;
	int b;
	for(;b>0;i++)
		b = c / pow(10,i);
	for(i=i-2;i>=0;i--){
		b = int(c / pow(10,i)) % 10;
		a += R_num[b];
	}
	return a;
}

void no_operation()
{
	cin>>op;
	if(op=="整数"){
		cin>>op_var;
		cin>>equ;
		cin>>op_var_val;
	}
	else if(op=="看看"){
		cin>>op_var;
	}
	else{
		if(var.find(op) == var.end())
			cout<<"无此变量"; 
		else{
			op_var = op;
			cin >> op;
			if(op == "增加"){
				cin >> op_var1;
			} 
			else if(op == "减少"){
				cin >> op_var1;
			} 
		}
	}
}

void operation()
{
	cin>>op;
	if(op=="整数")
	{
		cin>>op_var;
		cin>>equ;
		cin>>op_var_val;
		var[op_var] = change_to_num(op_var_val);
		//cout<<"变量‘"<<op_var<<"’的值是"<<var[op_var]<<endl;//可以输出值 
	}
	else if(op=="看看")
	{
		cin>>op_var;
			/*去除引号 */ 
		if (!var.count(op_var)) {
				if (op_var[0] == '"' && op_var[op_var.size()-1] == '"') 
					cout << op_var.substr(1,op_var.size()-2) << endl;
				else if (op_var.substr(0,2) == "“" && op_var.substr(op_var.size()-2,2) == "”") 
					cout << op_var.substr(2,op_var.size()-4) << endl; 
					} 
		// 
		else
			cout<<R_change_to_num(var[op_var])<<endl;
	}
	else if(op=="如果")
	{
		cin >> judg_var;
		cin >> judge;
		if(judge=="等于")
		{
			cin >> judg_var1;
			if(var.find(judg_var1) == var.end())
				judge_num = num[judg_var1];
			else
				judge_num = var[judg_var1];
			if(var[judg_var] == judge_num)
			{
				cin>>judg_jump;
				operation();
				cin>>judg_jump;
				no_operation();
			}
			else
			{
				cin>>judg_jump;
				no_operation();
				cin>>judg_jump;
				operation();
			}
		}
		if(judge=="大于")
		{
			cin >> judg_var1;
			if(var.find(judg_var1) == var.end())
				judge_num = num[judg_var1];
			else
				judge_num = var[judg_var1];
			if(var[judg_var] > judge_num)
			{
				cin>>judg_jump;
				operation();
				cin>>judg_jump;
				no_operation();
			}
			else
			{
				cin>>judg_jump;
				no_operation();
				cin>>judg_jump;
				operation();
			}
		}
		else if(judge=="小于")
		{
			cin >> judg_var1;
			if(var.find(judg_var1) == var.end())
				judge_num = num[judg_var1];
			else
				judge_num = var[judg_var1];
			if(var[judg_var] < judge_num)
			{
				cin>>judg_jump;
				operation();
				cin>>judg_jump;
				no_operation();
			}
			else
			{
				cin>>judg_jump;
				no_operation();
				cin>>judg_jump;
				operation();
			}
		}
	}
	
	else
	{
		if(var.find(op) == var.end())
			cout<<"无此变量"; 
		else
		{
			op_var = op;
			cin >> op;
			if(op == "增加")
			{
				cin >> op_var1; 
				if(var.find(op_var1) == var.end())
					var[op_var] = var[op_var]+num[op_var1];
				else
					var[op_var] = var[op_var]+var[op_var1];
				//cout<<R_num[var[op_var]]<<endl;//可以输出值 
			} 
			else if(op == "减少")
			{
				cin >> op_var1; 
				if(var.find(op_var1) == var.end())
					var[op_var] = var[op_var]-num[op_var1];
				else
					var[op_var] = var[op_var]-var[op_var1];
				//cout<<R_num[var[op_var]]<<endl;//可以输出值 
			} 
		}
	}
}

int main()
{
	num["零"]=0,num["一"]=1,num["二"]=2,num["三"]=3,num["四"]=4,num["五"]=5,
	num["六"]=6,num["七"]=7,num["八"]=8,num["九"]=9,num["十"]=10;
	R_num[0]="零",R_num[1]="一",R_num[2]="二",R_num[3]="三",R_num[4]="四",
	R_num[5]="五",R_num[6]="六",R_num[7]="七",R_num[8]="八",R_num[9]="九",R_num[10]="十";
	
	while(true)
	{
		operation();
	}
	return 0;
	
}
