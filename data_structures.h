#ifndef DATA_STRUCTURES_H_INCLUDED
#define DATA_STRUCTURES_H_INCLUDED
#include <iostream>
using namespace std;
//--------------------------- Rules Class-----------------------------------------------------

class NewRules{

private:
    int rule_no;
    string if_var1;
	string if_var1_value;
	string if_var2;
	string if_var2_value;
	string if_var3;
	string if_var3_value;
	string then_var;
	string then_var_value;

public:

    void set_if_part1(int rule, string if1,string if1_val, string if2,string if2_val, string if3, string if3_val)
    {
        rule_no = rule;
        if_var1 = if1; if_var1_value = if1_val;
        if_var2 = if2; if_var2_value = if2_val;
        if_var3 = if3; if_var3_value = if3_val;
    }

     void set_if_part2(int rule, string if1,string if1_val, string if2,string if2_val)
    {
        rule_no = rule;
        if_var1 = if1; if_var1_value = if1_val;
        if_var2 = if2; if_var2_value = if2_val;
    }

    void set_then_part(int rule, string th1,string th1_val)
    {
        rule_no = rule;
        then_var = th1; then_var_value = th1_val;
    }

    void print_rules()
    {
        cout<<rule_no<<"\tIF "<<if_var1<<" = "<<if_var1_value<<" "<<if_var2<<" = "<<if_var2_value<<" "<<if_var3<<" = "<<if_var3_value<<endl;
        cout<<"\tTHEN "<<then_var<<" "<<then_var_value<<endl;
    }
};

//----------------------- Conclusion List Class-----------------------------------------------------

class ConclusionList{

private:
    int rule_number;
    string conclusion_var;
    string varValue;
    bool status;

public:
    ConclusionList(){
        rule_number = 0;
        status=0;
    }

    void set_rule(int ruleNo, string var){
        rule_number = ruleNo;
        conclusion_var = var;
    }

    void set_value(string value)
    {
        varValue = value;
        status = 1;
    }

    void print_rule(){
        cout<< rule_number<<" "<<conclusion_var;
    }

    string get_conclusion()
    {
        return conclusion_var;
    }

    string get_conclusion_value()
    {
        return varValue;
    }

    int get_rule()
    {
        return rule_number;
    }

    void set_status()
    {
        status = 1;
    }

    bool get_status()
    {
        return status;
    }
};

//----------------------- Variable List Class-----------------------------------------------------
class VariableList{

private:
    string varName;
	string varValue;
    bool varStatus;

public:

	void set(string var, string Value){
		varName = var;
		varValue = Value;
	}

    void set(string Value){
		varValue = Value;
	}
	/*void update(string var, string val){
		varValue = Value;
		//varStatus = "I";
	}*/

	void init(bool stat, string var, string Value){
		varStatus = stat;
		varName = var;
		varValue = Value;
	}

    string getVarName(){
	  return varName;
	}

	string getValue(){
	  return varValue;
	}

    void setStatus(bool value)
	{
	    varStatus = value;
	}

	bool getStatus()
	{
	    return varStatus;
	}

	void printVarList(){
		cout<<varStatus<<"  "<<varName << "  " << varValue;
	}

};

class ClauseVarList
{
private:
    int clause_no;
    string clause_value;

public:

    void set_vars(int no, string value)
    {
        clause_no = no;
        clause_value = value;
    }

    string get_clause_vars()
    {
        return clause_value;
    }

    void print_clause_vars()
    {
        cout<<"  "<<clause_no<<"  "<<clause_value;
    }

};




#endif // DATA_STRUCTURES_H_INCLUDED
