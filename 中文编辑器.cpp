#include<iostream> 
#include<map>
#include<math.h>
using namespace std;

map<string,int>num;
map<int,string>R_num;
map<string,int>var;
int judge_num;
string op;
string equ = "����";
string judge;
string op_var;
string op_var1;
string judg_var;
string judg_var1;
string judg_jump;
string op_var_val;

int change_to_num(string a) //һ������ ת��Ϊ 1234 
{
	int c;
	int j=0;
	for(int i=a.length()-2;i>=0;i-=2,j++){
		string s3(a,i,2);
		c+=num[s3]*pow(10,j);
	}
	return c;
}

string R_change_to_num(int c) //1234 ת��Ϊ һ������
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
	if(op=="����"){
		cin>>op_var;
		cin>>equ;
		cin>>op_var_val;
	}
	else if(op=="����"){
		cin>>op_var;
	}
	else{
		if(var.find(op) == var.end())
			cout<<"�޴˱���"; 
		else{
			op_var = op;
			cin >> op;
			if(op == "����"){
				cin >> op_var1;
			} 
			else if(op == "����"){
				cin >> op_var1;
			} 
		}
	}
}

void operation()
{
	cin>>op;
	if(op=="����")
	{
		cin>>op_var;
		cin>>equ;
		cin>>op_var_val;
		var[op_var] = change_to_num(op_var_val);
		//cout<<"������"<<op_var<<"����ֵ��"<<var[op_var]<<endl;//�������ֵ 
	}
	else if(op=="����")
	{
		cin>>op_var;
			/*ȥ������ */ 
		if (!var.count(op_var)) {
				if (op_var[0] == '"' && op_var[op_var.size()-1] == '"') 
					cout << op_var.substr(1,op_var.size()-2) << endl;
				else if (op_var.substr(0,2) == "��" && op_var.substr(op_var.size()-2,2) == "��") 
					cout << op_var.substr(2,op_var.size()-4) << endl; 
					} 
		// 
		else
			cout<<R_change_to_num(var[op_var])<<endl;
	}
	else if(op=="���")
	{
		cin >> judg_var;
		cin >> judge;
		if(judge=="����")
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
		if(judge=="����")
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
		else if(judge=="С��")
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
			cout<<"�޴˱���"; 
		else
		{
			op_var = op;
			cin >> op;
			if(op == "����")
			{
				cin >> op_var1; 
				if(var.find(op_var1) == var.end())
					var[op_var] = var[op_var]+num[op_var1];
				else
					var[op_var] = var[op_var]+var[op_var1];
				//cout<<R_num[var[op_var]]<<endl;//�������ֵ 
			} 
			else if(op == "����")
			{
				cin >> op_var1; 
				if(var.find(op_var1) == var.end())
					var[op_var] = var[op_var]-num[op_var1];
				else
					var[op_var] = var[op_var]-var[op_var1];
				//cout<<R_num[var[op_var]]<<endl;//�������ֵ 
			} 
		}
	}
}

int main()
{
	num["��"]=0,num["һ"]=1,num["��"]=2,num["��"]=3,num["��"]=4,num["��"]=5,
	num["��"]=6,num["��"]=7,num["��"]=8,num["��"]=9,num["ʮ"]=10;
	R_num[0]="��",R_num[1]="һ",R_num[2]="��",R_num[3]="��",R_num[4]="��",
	R_num[5]="��",R_num[6]="��",R_num[7]="��",R_num[8]="��",R_num[9]="��",R_num[10]="ʮ";
	
	while(true)
	{
		operation();
	}
	return 0;
	
}
