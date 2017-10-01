#include <iostream>
#include <stack>
#include<vector>
#include <string>
#include <string.h>
#include "data_structures.h"

using namespace std;

void initialize_lists();
int conclusion_search(int,string);
void update_variable_list(int rule);
void evaluate_then_part(int rule);
void check_var_list(string var_to_check);
void iterate(int);

ConclusionList conc_list[5];
VariableList var_list[9];
NewRules rules[4];
ClauseVarList clause_vars[21];
bool rule_found();

stack<int> cn_stack;
stack<int> sn_stack;

int sn,i;
int cn;
int pos;
int var_in_clause_list = 1;
string conclusion;
int case_no=-1;

void backward_chaining(int sn, string conclusion);

//----------------------------- Main ------------------------------------------------
int main()
{
    //initialize variable list, conclusion variable list & clause variable list
    cout<<endl<<"***************************************************************"<<endl;
        initialize_lists();
    cout<<endl<<"***************************************************************"<<endl;


    cout<<"Please Enter The Conclusion: ";
    cin>>conclusion;


    pos=0;

        sn = conclusion_search(pos,conclusion);

        if(sn==-1){
            cout<<"Conclusion Not Found.."<<endl;
            return 0;
        }


        else
            backward_chaining(sn, conclusion);

            while(conc_list[pos].get_conclusion_value()=="" && pos<6){
                pos++;sn_stack.pop(); cn_stack.pop();
                sn = conclusion_search(pos,conclusion);
                backward_chaining(sn, conclusion);
            }

     while(!sn_stack.empty()){
        int con_no;
        switch(sn_stack.top()){
             case 10: con_no = 0; break;
             case 20: con_no = 1; break;
             case 30: con_no = 2; break;
             case 40: con_no = 3; break;
             case 50: con_no = 4; break;
        }
        if(conc_list[con_no].get_conclusion_value()!=""){
            cout<<endl<<"********************************************************"<<endl;
            cout<<"The Conclusion is: "<<endl;
            cout<<"Evaluated Rule: "<<sn_stack.top()<<endl;
            cout<<"Result: "<<conc_list[con_no].get_conclusion()<<" = "<< conc_list[con_no].get_conclusion_value()<<endl;
        }

        sn_stack.pop(); cn_stack.pop();
     }


    return 0;
}



void backward_chaining(int sn, string conclusion)
{
    sn_stack.push(sn);
    cn = 4 * (sn/10-1) + 1;
    cn_stack.push(cn);

    int var_in_clause_list = 1;
    do{
        string var_to_check = clause_vars[cn].get_clause_vars();
        int new_sn = conclusion_search(pos, var_to_check);

        if(new_sn!=-1){
            pos++;
            backward_chaining(new_sn, var_to_check);
        }
        check_var_list(var_to_check);
        cout<<endl;
        cn++;
        var_in_clause_list++;
    }while(var_in_clause_list<5 && clause_vars[cn].get_clause_vars()!="");

    evaluate_then_part(sn);
}

void check_var_list(string var_to_check)
{
    for(int i=0;i<8;i++)
    {
        if(var_to_check == var_list[i].getVarName())
        {
            if(!var_list[i].getStatus())
            {
                string question;
                cout<<var_list[i].getVarName()<<" <yes/no>: ";
                cin>>question;
                var_list[i].set(question);
                var_list[i].setStatus(1);
            }
        }
    }
}

int conclusion_search(int pos, string var)
{
    for(int i=pos;i<5;i++)
    {
        if(var == conc_list[i].get_conclusion())
        {
            return conc_list[i].get_rule();
        }
    }
    return -1;
}


void evaluate_then_part(int rule)
{
        switch(rule)
        {
            case 10:    if(var_list[0].getValue() == "yes" && var_list[1].getValue() == "yes" && var_list[2].getValue() == "yes")
                        {
                            conc_list[0].set_value("yes");
                            case_no = 0;
                        }else{conc_list[0].set_value("no");};
                        break;

            case 20:   if(conc_list[0].get_conclusion_value() == "yes" &&  var_list[3].getValue() == "yes")
                        {
                            conc_list[1].set_value("large_cell_neuroma");
                            case_no = 1;
                        }
                        break;

           case 30:    if(conc_list[0].get_conclusion_value() == "yes" && var_list[4].getValue() == "yes")
                        {
                            conc_list[2].set_value("squanors_cell_carcinoma");
                            case_no = 2;
                        }
                         break;

            case 40:    if(conc_list[0].get_conclusion_value() == "no" &&  var_list[5].getValue() == "yes")
                        {
                            conc_list[3].set_value("large_cell_carcinoma");
                            case_no = 3;
                        }
                        break;

            case 50:    if(conc_list[0].get_conclusion_value() == "no" && var_list[5].getValue() == "no" && var_list[6].getValue() == "yes" && var_list[7].getValue() == "yes")
                        {
                            conc_list[4].set_value("adeno_carcinome");
                            case_no = 4;
                        }
                        break;

        }
}




void initialize_lists()
{
    cout<<"Initializing Variable List.."<<endl;
    var_list[0].init(0,"short_breath","");
    var_list[1].init(0,"chronic_cough","");
    var_list[2].init(0,"cough_blood","");
    var_list[3].init(0,"recurrent_pneunomia","");
    var_list[4].init(0,"shoulder_pain","");
    var_list[5].init(0,"achiness_back_shoulder","");
    var_list[6].init(0,"chest_pain","");
    var_list[7].init(0,"fatigue","");

    for(int i = 0 ; i < 8;i++)
    {
		var_list[i].printVarList();
		cout<<endl;
	}
    cout<<endl;

    cout<<"Initializing Conclusion Variable List.."<<endl;
    conc_list[0].set_rule(10,"wheezing");
    conc_list[1].set_rule(20,"lung_cancer");
    conc_list[2].set_rule(30,"lung_cancer");
    conc_list[3].set_rule(40,"lung_cancer");
    conc_list[4].set_rule(50,"lung_cancer");


    for(int i=0;i<5;i++)
    {
        conc_list[i].print_rule();
        cout<<"\n";
    }

    cout<<endl<<"Initializing Rules.."<<endl;
    rules[0].set_if_part1(10, "short_breath","yes", "chronic_cough", "yes", "cough_blood", "yes");
    rules[0].set_then_part(10, "wheezing", "yes");
    rules[1].set_if_part2(20, "wheezing","yes", "recurrent_pneunomia", "yes");
    rules[1].set_then_part(20, "lung_cancer", "yes");
    rules[2].set_if_part2(30, "wheezing","yes", "shoulder_pain", "yes");
    rules[2].set_then_part(30, "lung_cancer", "yes");
    rules[3].set_if_part2(40, "wheezing","no", "achiness_back_shoulder", "yes");
    rules[3].set_then_part(40, "lung_cancer", "yes");
    for(int i = 0 ; i < 4;i++)
    {
		rules[i].print_rules();
		cout<<endl;
	}
    cout<<endl;

    cout<<"Initializing Clause Variables.."<<endl;
    clause_vars[0].set_vars(0,"");
    clause_vars[1].set_vars(1,"short_breath");
    clause_vars[2].set_vars(2,"chronic_cough");
    clause_vars[3].set_vars(3,"cough_blood");
    clause_vars[4].set_vars(4,"");
    clause_vars[5].set_vars(5,"wheezing");
    clause_vars[6].set_vars(6,"recurrent_pneunomia");
    clause_vars[7].set_vars(7,"");
    clause_vars[8].set_vars(8,"");
    clause_vars[9].set_vars(9,"wheezing");
    clause_vars[10].set_vars(10,"shoulder_pain");
    clause_vars[11].set_vars(11,"");
    clause_vars[12].set_vars(12,"");
    clause_vars[13].set_vars(13,"wheezing");
    clause_vars[14].set_vars(14,"achiness_back_shoulder");
    clause_vars[15].set_vars(15,"");
    clause_vars[16].set_vars(16,"");
    clause_vars[17].set_vars(17,"wheezing");
    clause_vars[18].set_vars(18,"achiness_back_shoulder");
    clause_vars[19].set_vars(19,"chest_pain");
    clause_vars[20].set_vars(20,"fatigue");
    for(int i = 0 ; i < 21;i++)
    {
		clause_vars[i].print_clause_vars();
		cout<<endl;
	}
    cout<<endl;
}
