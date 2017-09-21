#include <iostream>
#include <stack>
#include<vector>
#include "data_structures.h"

using namespace std;

void initialize_lists();
int conclusion_search(int,string str);
void update_variable_list(int rule);
string evaluate_then_part(int rule);
void check_var_list(string var_to_check);

ConclusionList conc_list[5];
VariableList var_list[9];
NewRules rules[4];
ClauseVarList clause_vars[17];

vector<int> stack_rule_no;
vector<int> stack_pointer;

int sn;
int cn;


//----------------------------- Main ------------------------------------------------
int main()
{
    //initialize variable list, conclusion variable list & clause variable list
    cout<<endl<<"***************************************************************"<<endl;
        initialize_lists();
    cout<<endl<<"***************************************************************"<<endl;

    string conclusion;
    cout<<"Please Enter The Conclusion: ";
    cin>>conclusion;


    //1.calculate clause no and then place 2.if that conclusion not found display message
    //initially search from the begining
    sn = conclusion_search(0,conclusion);
    stack_rule_no.push_back(sn);
    if(sn==-1)
    {
        cout<<"No such conclusion exists.."<<endl;
    }
    cn = 4 * (sn/10-1) + 1;
    stack_pointer.push_back(cn);
    cout<<"Cn: "<<cn<<endl;
    int var_in_clause_list = 1;
    do{
        //check if variable is instantiated
        string var_to_check = clause_vars[cn].get_clause_vars();
        check_var_list(var_to_check);
        cout<<endl;
     // if(var_list[cn].get
        cn++;
        var_in_clause_list++;
    }while(clause_vars[cn].get_clause_vars()!= "" && var_in_clause_list<4);


   /* //initializing variable list
        update_variable_list(sn);

    //evaluate then part
    string var=evaluate_then_part(sn);
    if(var != "fails")
    {
        cout<<"Conclusion: "<<var<<" = yes"<<endl;
    }
*/

    return 0;
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

/*
void update_variable_list(int rule)
{
    switch(rule)
    {
        case 10:if(!var_list[0].getStatus())
                {
                    string ans1;
                    cout<<"Shortness of Breath? yes/no: ";
                    cin>>ans1;
                    var_list[0].set("short_breath",ans1);
                    var_list[0].setStatus(1);
                }
                if(!var_list[1].getStatus())
                {
                    string ans2;
                    cout<<"Chronic Cough? yes/no: ";
                    cin>>ans2;
                    var_list[1].set("chronic_cough",ans2);
                    var_list[1].setStatus(1);
                }
                if(!var_list[2].getStatus())
                {
                    string ans3;
                    cout<<"Cough of Blood? yes/no: ";
                    cin>>ans3;
                    var_list[2].set("cough_blood",ans3);
                    var_list[2].setStatus(1);
                }
                break;

        case 20:if(!var_list[3].getStatus())
                {
                    for(int i=0;i<4;i++)
                    {
                        if(var_list[3].getVarName() == conc_list[i].get_conclusion())
                        {
                            update_variable_list(10);
                            evaluate_then_part(10);
                            break;
                        }
                    }
                }

                if(!var_list[4].getStatus())
                {
                    string ans2;
                    cout<<"Recurrent Pneunomia? yes/no: ";
                    cin>>ans2;
                    var_list[4].set("recurrent_pneunomia",ans2);
                    var_list[4].setStatus(1);
                }
                break;

        case 30:if(!var_list[3].getStatus())
                {
                    for(int i=0;i<4;i++)
                    {
                        if(var_list[3].getVarName() == conc_list[i].get_conclusion())
                        {
                            update_variable_list(10);
                            evaluate_then_part(10);
                            break;
                        }
                    }
                }

                if(!var_list[5].getStatus())
                {
                    string ans2;
                    cout<<"Shoulder Pain? yes/no: ";
                    cin>>ans2;
                    var_list[5].set("shoulder_pain",ans2);
                    var_list[5].setStatus(1);
                }
                break;

        case 40:if(!var_list[3].getStatus())
                {
                    for(int i=0;i<4;i++)
                    {
                        if(var_list[3].getVarName() == conc_list[i].get_conclusion())
                        {
                            update_variable_list(10);
                            evaluate_then_part(10);
                            break;
                        }
                    }
                }

                if(!var_list[6].getStatus())
                {
                    string ans2;
                    cout<<"Achiness in Back Shoulder? yes/no: ";
                    cin>>ans2;
                    var_list[6].set("achiness_back_shoulder",ans2);
                    var_list[6].setStatus(1);
                }
                break;
    }
}
*/

string evaluate_then_part(int rule)
{
        switch(rule)
        {
            case 10:    if(var_list[0].getValue() == "yes" && var_list[1].getValue() == "yes" && var_list[2].getValue() == "yes")
                        {
                            conc_list[0].set_value("yes");
                            //string var = conc_list[0].get_conclusion() + " = yes";
                            return conc_list[0].get_conclusion();
                        }
                        break;

            case 20:    if(var_list[0].getValue() == "yes" &&  var_list[3].getValue() == "yes")
                        {
                            conc_list[1].set_value("yes");
                            return conc_list[1].get_conclusion();
                        }
                        break;

            case 30:    if(var_list[0].getValue() == "yes" && var_list[4].getValue() == "yes")
                        {
                            conc_list[2].set_value("yes");
                            return conc_list[2].get_conclusion();
                        }
                        break;

            case 40:    if(var_list[0].getValue() == "no" &&  var_list[5].getValue() == "yes")
                        {
                          conc_list[3].set_value("yes");
                            return conc_list[3].get_conclusion();
                        }
                        break;

           /* case 50:    if(var1 == "no" && var_list[5].getValue() == "yes" && var_list[6].getValue() == "yes" && var_list[7].getValue() == "yes")
                        {
                            conc_list[4].set_value("yes");
                            return conclusion;
                        }
                        break;

            case 60:    if(var_list[0].getValue() == "yes" && var_list[1].getValue() == "yes" && var_list[2].getValue() == "no")
                        {
                            conc_list[0].set_value("no");
                            return conclusion;
                        }
                        break; */
        }
        return "fail";
}


int conclusion_search(int pos, string str)
{
    for(int i=pos;i<5;i++)
    {
        if(str == conc_list[i].get_conclusion())
        {
            return conc_list[i].get_rule();
        }
    }
    return -1;
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

    for(int i=0;i<4;i++)
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
   /* clause_vars[17].set_vars(17,"wheezing");
    clause_vars[18].set_vars(18,"achiness_back_shoulder");
    clause_vars[19].set_vars(19,"chest_pain");
    clause_vars[20].set_vars(20,"fatigue");*/
    for(int i = 0 ; i < 16;i++)
    {
		clause_vars[i].print_clause_vars();
		cout<<endl;
	}
    cout<<endl;
}
