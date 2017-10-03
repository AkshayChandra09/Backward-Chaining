#include <iostream>
#include <stack>
#include<vector>
#include <string>
#include <string.h>
#include "data_structures.h"

#define var_list_size 19
#define clause_list_size 41
#define conc_list_size 10


using namespace std;

void initialize_lists();
int conclusion_search(int,string);
void update_variable_list(int rule);
void evaluate_then_part(int rule);
void check_var_list(string var_to_check);
void iterate(int);

ConclusionList conc_list[conc_list_size];
VariableList var_list[var_list_size];
NewRules rules[4];
ClauseVarList clause_vars[clause_list_size];
bool rule_found();

stack<int> cn_stack;
stack<int> sn_stack;

int sn,i;
int cn,count;
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


    pos=0;  //pos is the index of conc_list

        sn = conclusion_search(pos,conclusion);
        if(sn==-1){
            cout<<"Conclusion Not Found.."<<endl;
            return 0;
        }

        else
            backward_chaining(sn, conclusion);

          for(int i=0;i<conc_list_size;i++){
             if(conc_list[i].get_rule()==sn){
                pos = i; break;
             }
          }
        cout<<"pos = "<<pos<<endl;
        while(conc_list[pos].get_conclusion_value()=="" && pos<conc_list_size){
              pos++;sn_stack.pop(); cn_stack.pop();
              sn = conclusion_search(pos,conclusion);
              if(sn!=-1)
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
             case 60: con_no = 5; break;
             case 70: con_no = 6; break;
             case 80: con_no = 7; break;
             case 90: con_no = 8; break;
             case 100: con_no = 9; break;
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
    for(int i=0;i<var_list_size;i++)
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
    for(int i=pos;i<conc_list_size;i++)
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
                        }else{conc_list[0].set_value("no");}
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

            case 60:    if(var_list[0].getValue() == "yes" && var_list[1].getValue() == "yes" && var_list[2].getValue() == "no")
                        {
                            conc_list[5].set_value("no_lung_cancer");
                            case_no = 5;
                        }
                        break;
            case 70:    if(var_list[8].getValue() == "yes" && var_list[9].getValue() == "yes" && var_list[10].getValue() == "yes" && var_list[11].getValue() == "yes")
                        {
                            conc_list[6].set_value("nodular");
                            case_no = 6;
                        }
                        break;

            case 80:    cout<<"In case 7 "<<endl;
                        if(var_list[8].getValue() == "no" && var_list[12].getValue() == "yes" && var_list[13].getValue() == "yes" && var_list[14].getValue() == "yes")
                        {
                            conc_list[7].set_value("acral_lentigious");
                            case_no = 7;
                        }
                        break;

            case 90:    cout<<"In case 8 "<<endl;
                        if(var_list[8].getValue() == "no" && var_list[15].getValue() == "yes" && var_list[16].getValue() == "yes")
                        {
                            conc_list[8].set_value("lentigo");
                            case_no = 8;
                        }
                        break;

             case 100:    cout<<"In case 10 "<<endl;
                        if(var_list[8].getValue() == "yes" && var_list[9].getValue() == "no"
                           && var_list[17].getValue() == "yes" && var_list[18].getValue() == "yes")
                        {
                            conc_list[9].set_value("super_facial_spreading");
                            case_no = 9;
                        }
                        break;

        }
}




void initialize_lists()
{
    cout<<"Initializing Variable List.."<<endl;
    //LUNG CANCER
    var_list[0].init(0,"short_breath","");
    var_list[1].init(0,"chronic_cough","");
    var_list[2].init(0,"cough_blood","");
    var_list[3].init(0,"recurrent_pneunomia","");
    var_list[4].init(0,"shoulder_pain","");
    var_list[5].init(0,"achiness_back_shoulder","");
    var_list[6].init(0,"chest_pain","");
    var_list[7].init(0,"fatigue","");

    var_list[8].init(0,"itching","");
    var_list[9].init(0,"head_neck_affected","");
    var_list[10].init(0,"done_shaped_lump","");
    var_list[11].init(0,"bleeding","");
    var_list[12].init(0,"nails_affected","");
    var_list[13].init(0,"border_irregularity","");
    var_list[14].init(0,"assymetry","");
    var_list[15].init(0,"moles>6mm","");
    var_list[16].init(0,"face_affected","");

    var_list[17].init(0,"moles_beyond_border","");
    var_list[18].init(0,"variable_pigmentation","");




    for(int i = 0 ; i < 15;i++)
    {
		var_list[i].printVarList();
		cout<<endl;
	}
    cout<<endl;

    cout<<"Initializing Conclusion Variable List.."<<endl;

    //Conclusions for Lung Cancer
    conc_list[0].set_rule(10,"wheezing");
    conc_list[1].set_rule(20,"lung_cancer");
    conc_list[2].set_rule(30,"lung_cancer");
    conc_list[3].set_rule(40,"lung_cancer");
    conc_list[4].set_rule(50,"lung_cancer");
    conc_list[5].set_rule(60,"lung_cancer");

    conc_list[6].set_rule(70,"skin_cancer_itching");
    conc_list[7].set_rule(80,"skin_cancer");
    conc_list[8].set_rule(90,"skin_cancer");
    conc_list[9].set_rule(100,"skin_cancer_itching");
    conc_list[10].set_rule(110,"skin_cancer");

    for(int i=0;i<10;i++)
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
    clause_vars[21].set_vars(21,"short_breath");
    clause_vars[22].set_vars(22,"chronic_cough");
    clause_vars[23].set_vars(23,"cough_blood");
    clause_vars[24].set_vars(24,"");

    clause_vars[25].set_vars(25,"itching");
    clause_vars[26].set_vars(26,"head_neck_affected");
    clause_vars[27].set_vars(27,"done_shaped_lump");
    clause_vars[28].set_vars(28,"bleeding");

    clause_vars[29].set_vars(29,"itching");
    clause_vars[30].set_vars(30,"nails_affected");
    clause_vars[31].set_vars(31,"border_irregularity");
    clause_vars[32].set_vars(32,"assymetry");

    clause_vars[33].set_vars(33,"itching");
    clause_vars[34].set_vars(34,"moles>6mm");
    clause_vars[35].set_vars(35,"face_affected");
    clause_vars[36].set_vars(36,"");

    clause_vars[37].set_vars(37,"itching");
    clause_vars[38].set_vars(38,"moles_beyond_border");
    clause_vars[39].set_vars(39,"head_neck_affected");
    clause_vars[40].set_vars(40,"variable_pigmentation");




    for(int i = 0 ; i <41;i++)
    {
		clause_vars[i].print_clause_vars();
		cout<<endl;
	}
    cout<<endl;
}
