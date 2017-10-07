#ifndef DATA_STRUCTURES_H_INCLUDED
#define DATA_STRUCTURES_H_INCLUDED
#include <iostream>
using namespace std;

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

    void set_status(int v)
    {
        status = v;
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
