#include <iostream>
#include <stack>
#include<vector>
#include <string>
#include <string.h>
#include "data_structures.h"
#include "forward.cpp"

#define var_list_size 54
#define clause_list_size 101
#define conc_list_size 25


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

int sn;
int cn,count;
int pos;
int var_in_clause_list;
string conclusion;
int case_no=-1;


void backward_chaining(int sn, string conclusion);

//----------------------------- Main ------------------------------------------------



int main()
{
    int con_no;

char answer;
int choice;


 /* do{
	cout << "\nPlease enter a number for the cancer type "
                    << " to find the treatment: ";
        cin >> choice;

	doti d1(choice);

	cout << "\n\n Do you want to check treatment for another cancer (Y/N)?";
    	cin >> answer;

     }while(answer == 'Y'  || answer == 'y');*/

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

          /*for(int i=0;i<conc_list_size;i++){
             if(conc_list[i].get_rule()==sn){
                pos = i; break;
             }
          }*/


        cout<<"pos = "<<pos<<endl;
        while(conc_list[pos].get_conclusion_value()=="" && pos<conc_list_size){
              pos++;sn_stack.pop(); cn_stack.pop();
              sn = conclusion_search(pos,conclusion);
              //if(sn!=-1)    //***check couple of times***
                 backward_chaining(sn, conclusion);
        }


     while(!sn_stack.empty()){

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
             case 110: con_no = 10; break;
             case 120: con_no = 11; break;
             case 130: con_no = 12; break;
             case 140: con_no = 13; break;
             case 150: con_no = 14; break;
             case 160: con_no = 15; break;
             case 170: con_no = 16; break;
             case 180: con_no = 17; break;
             case 190: con_no = 18; break;
             case 200: con_no = 19; break;
             case 210: con_no = 20; break;

             case 220: con_no = 21; break;
             case 230: con_no = 22; break;
             case 240: con_no = 23; break;
             case 250: con_no = 24; break;
        }
        if(conc_list[con_no].get_conclusion_value()!=""){
            cout<<endl<<"********************************************************"<<endl;
            cout<<"The Conclusion is: "<<endl;
            cout<<"Evaluated Rule: "<<sn_stack.top()<<endl;
            cout<<"Result: "<<conc_list[con_no].get_conclusion()<<" = "<< conc_list[con_no].get_conclusion_value()<<endl;
            choice = con_no;
        }

        sn_stack.pop(); cn_stack.pop();
     }


    doti d1(choice);
    cout<<"con_no is: "<<con_no<<endl;

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
                            conc_list[4].set_value("adeno_carcinoma");
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
            case 110:    cout<<"In case 11 "<<endl;
                        if(var_list[8].getValue() == "no" && var_list[13].getValue() == "no")
                        {
                           //&& var_list[17].getValue() == "no" && var_list[18].getValue() == "no");
                            conc_list[10].set_value("no_skin_cancer");
                            case_no =10;
                        }
                        break;

            case 120:   cout<<"In case 12 "<<endl;
                        if(var_list[19].getValue() == "yes" && var_list[20].getValue() == "yes" && var_list[21].getValue() == "yes")
                        {
                            conc_list[11].set_value("yes");
                            case_no =11;
                        }else{conc_list[11].set_value("no");}
                        break;

             case 130:   cout<<"In case 13 "<<endl;
                        if(conc_list[11].get_conclusion_value() == "yes" && var_list[22].getValue() == "yes" && var_list[23].getValue() == "no")
                        {
                            conc_list[12].set_value("acute_myclogenous");
                            case_no =12;
                        }
                        break;

             case 140:   cout<<"In case 14 "<<endl;
                        if(conc_list[11].get_conclusion_value() == "yes" && var_list[22].getValue() == "no" && var_list[25].getValue() == "yes" && var_list[26].getValue() == "yes")
                        {
                            conc_list[13].set_value("chronic_myclogenous");
                            case_no =13;
                        }
                        break;
            case 150:   cout<<"In case 15 "<<endl;
                        if(conc_list[11].get_conclusion_value() == "yes" && var_list[22].getValue() == "no" && var_list[25].getValue() == "no" && var_list[27].getValue() == "yes")
                        {
                            conc_list[14].set_value("chronic_lymphocytic");
                            case_no =14;
                        }
                        break;

             case 160:   cout<<"In case 16 "<<endl;
                        if(conc_list[11].get_conclusion_value() == "yes" && var_list[22].getValue() == "yes" && var_list[23].getValue() == "yes")
                        {
                            conc_list[15].set_value("acute_lymphocytic");
                            case_no =15;
                        }
                        break;

             case 170:   cout<<"In case 17 "<<endl;
                        if(conc_list[11].get_conclusion_value() == "no")
                        {
                            conc_list[16].set_value("No Blood Cancer");
                            case_no =16;
                        }
                        break;

             case 180:   cout<<"In case 18 "<<endl;
                        if(var_list[28].getValue() == "yes" && var_list[29].getValue() == "no" && var_list[30].getValue() == "yes" && var_list[31].getValue() == "yes")
                        {
                            conc_list[17].set_value("acoustic_neuroma");
                            case_no =17;
                        }
                        break;

            case 190:   cout<<"In case 19 "<<endl;
                        if(var_list[28].getValue() == "yes" && var_list[29].getValue() == "yes" && var_list[32].getValue() == "yes")
                        {
                            conc_list[18].set_value("cns_lymphoma");
                            case_no =18;
                        }
                        break;

             case 200:   cout<<"In case 20 "<<endl;
                        if(var_list[28].getValue() == "yes" && var_list[33].getValue() == "yes" && var_list[34].getValue() == "yes")
                        {
                            conc_list[19].set_value("medulloblastoma");
                            case_no =19;
                        }
                        break;

            case 210:   cout<<"In case 21 "<<endl;
                        if(var_list[28].getValue() == "yes" && var_list[35].getValue() == "yes" && var_list[36].getValue() == "yes" && var_list[37].getValue() == "no")
                        {
                            conc_list[20].set_value("pituitary_tumor");
                            case_no =20;
                        }
                        break;


             case 220:   cout<<"In case 22 "<<endl;
                        if(var_list[38].getValue() == "yes" && var_list[39].getValue() == "yes" && var_list[40].getValue() == "yes" && var_list[41].getValue() == "yes")
                        {
                            conc_list[21].set_value("enalangio_carcinoma");
                            case_no =21;
                        }
                        break;

             case 230:   cout<<"In case 23 "<<endl;
                        if(var_list[42].getValue() == "yes" && var_list[43].getValue() == "yes" && var_list[44].getValue() == "yes")
                        {
                            conc_list[22].set_value("heptoblastoma");
                            case_no =22;
                        }
                        break;

             case 240:   cout<<"In case 24 "<<endl;
                        if(var_list[46].getValue() == "yes" && var_list[47].getValue() == "yes" && var_list[48].getValue() == "yes")
                        {
                            conc_list[23].set_value("metastasis");
                            case_no =23;
                        }
                        break;

             case 250:   cout<<"In case 25 "<<endl;
                        if(var_list[50].getValue() == "yes" && var_list[51].getValue() == "yes" && var_list[52].getValue() == "yes")
                        {
                            conc_list[24].set_value("angiosarcoma");
                            case_no =24;
                        }
                        break;
        }
}




void initialize_lists()
{
    cout<<"Initializing Variable List.."<<endl;
    //LUNG CANCER
    for(int i=0;i<var_list_size;i++){
        var_list[i].init(0,"","");
    }

    var_list[0].init(0,"short_breath","");
    var_list[1].init(0,"chronic_cough","");
    var_list[2].init(0,"cough_blood","");
    var_list[3].init(0,"recurrent_pneunomia","");
    var_list[4].init(0,"shoulder_pain","");
    var_list[5].init(0,"achiness_back_shoulder","");
    var_list[6].init(0,"chest_pain","");
    var_list[7].init(0,"fatigue","");
    //SKIN CANCER
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

    var_list[19].init(0,"swollen_lymph_nodes","");
    var_list[20].init(0,"red_spots_on_skin","");
    var_list[21].init(0,"excess_sweat","");

    var_list[22].init(0,"abdomen_swelling","");
    var_list[23].init(0,"joint_pain","");
    var_list[24].init(0,"clotting_problem","");

    var_list[25].init(0,"pain_below_ribs","");
    var_list[26].init(0,"easy_bleeding","");
    var_list[27].init(0,"pain_upper_left_abdomen","");


    var_list[28].init(0,"head_ache","");
    var_list[29].init(0,"vision_loss","");
    var_list[30].init(0,"hearing_loss","");
    var_list[31].init(0,"tinnitus","");
    var_list[32].init(0,"partial_paralysis","");
    var_list[33].init(0,"lack_of_coordination","");
    var_list[34].init(0,"personality_changes","");
    var_list[35].init(0,"depression","");
    var_list[36].init(0,"abnormal_wt_gain","");
    var_list[37].init(0,"speech_disorder","");


    var_list[38].init(0,"yellow_skin","");
    var_list[39].init(0,"weight_loss","");
    var_list[40].init(0,"deep_fatigue","");
    var_list[41].init(0,"itensively_itchy_skin","");

    var_list[42].init(0,"decreased_apatite","");
    var_list[43].init(0,"swollen_abdomen","");
    var_list[44].init(0,"nausea_vomiting","");
    var_list[45].init(0,"","");

    var_list[46].init(0,"dark_colored_urine","");
    var_list[47].init(0,"enlarged_liver","");
    var_list[48].init(0,"confusion","");
    var_list[49].init(0,"","");

     var_list[50].init(0,"lesion_bleeding","");
    var_list[51].init(0,"unhealing_bruise","");
    var_list[52].init(0,"purplish_affected_area","");
    var_list[53].init(0,"","");



    for(int i = 0; i < var_list_size;i++)
    {
		var_list[i].printVarList();
		cout<<endl;
	}
    cout<<endl;

    cout<<"Initializing Conclusion Variable List.."<<endl;

    //Conclusions for Lung Cancer
    conc_list[0].set_rule(10,"wheezing");
    conc_list[1].set_rule(20,"lung_cancer");  //large-cell-carninoma
    conc_list[2].set_rule(30,"lung_cancer");
    conc_list[3].set_rule(40,"lung_cancer");
    conc_list[4].set_rule(50,"lung_cancer");
    conc_list[5].set_rule(60,"lung_cancer");
     //Conclusions for Skin Cancer
    conc_list[6].set_rule(70,"skin_cancer_itching");
    conc_list[7].set_rule(80,"skin_cancer");
    conc_list[8].set_rule(90,"skin_cancer");
    conc_list[9].set_rule(100,"skin_cancer_itching");
    conc_list[10].set_rule(110,"skin_cancer");

    conc_list[11].set_rule(120,"leukemia_stage1");
    conc_list[12].set_rule(130,"blood_cancer_acute");
    conc_list[13].set_rule(140,"blood_cancer_chronic");
    conc_list[14].set_rule(150,"blood_cancer_chronic");
    conc_list[15].set_rule(160,"blood_cancer_acute");
    conc_list[16].set_rule(170,"no_blood_cancer");

    conc_list[17].set_rule(180,"brain_cancer");
    conc_list[18].set_rule(190,"brain_cancer");
    conc_list[19].set_rule(200,"brain_cancer");
    conc_list[20].set_rule(210,"brain_cancer");

    conc_list[21].set_rule(220,"liver_cancer_enalangio");
    conc_list[22].set_rule(230,"liver_cancer_hepto");
    conc_list[23].set_rule(240,"liver_cancer_metastasis");
    conc_list[24].set_rule(250,"liver_cancer_angio");

    for(int i=0;i<conc_list_size;i++)
    {
        conc_list[i].print_rule();
        cout<<"\n";
    }

    cout<<endl<<"Initializing Rules.."<<endl;
   /* rules[0].set_if_part1(10, "short_breath","yes", "chronic_cough", "yes", "cough_blood", "yes");
    rules[0].set_then_part(10, "wheezing", "yes");
    rules[1].set_if_part2(20, "wheezing","yes", "recurrent_pneunomia", "yes");
    rules[1].set_then_part(20, "lung_cancer", "yes");
    rules[2].set_if_part2(30, "wheezing","yes", "shoulder_pain", "yes");
    rules[2].set_then_part(30, "lung_cancer", "yes");
    rules[3].set_if_part2(40, "wheezing","no", "achiness_back_shoulder", "yes");
    rules[3].set_then_part(40, "lung_cancer", "yes");*/


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
    clause_vars[41].set_vars(41,"itching");
    clause_vars[42].set_vars(42,"border_irregularity");
    clause_vars[43].set_vars(43,"");
    clause_vars[44].set_vars(44,"");

    clause_vars[45].set_vars(45,"swollen_lymph_nodes");
    clause_vars[46].set_vars(46,"red_spots_on_skin");
    clause_vars[47].set_vars(47,"excess_sweat");
    clause_vars[48].set_vars(48,"");
    clause_vars[49].set_vars(49,"leukemia_stage1");
    clause_vars[50].set_vars(50,"abdomen_swelling");
    clause_vars[51].set_vars(51,"");
    clause_vars[52].set_vars(52,"");
    clause_vars[53].set_vars(53,"leukemia_stage1");
    clause_vars[54].set_vars(54,"abdomen_swelling");
    clause_vars[55].set_vars(55,"pain_below_ribs");
    clause_vars[56].set_vars(56,"easy_bleeding");
    clause_vars[57].set_vars(57,"leukemia_stage1");
    clause_vars[58].set_vars(58,"abdomen_swelling");
    clause_vars[59].set_vars(59,"pain_below_ribs");
    clause_vars[60].set_vars(60,"pain_upper_left_abdomen");
    clause_vars[61].set_vars(61,"leukemia_stage1");
    clause_vars[62].set_vars(62,"abdomen_swelling");
    clause_vars[63].set_vars(63,"joint_pain");
    clause_vars[64].set_vars(64,"");
    clause_vars[65].set_vars(65,"leukemia_stage1");
    clause_vars[66].set_vars(66,"");
    clause_vars[67].set_vars(67,"");
    clause_vars[68].set_vars(68,"");

    clause_vars[69].set_vars(69,"head_ache");
    clause_vars[70].set_vars(70,"vision_loss");
    clause_vars[71].set_vars(71,"hearing_loss");
    clause_vars[72].set_vars(72,"tinnitus");
    clause_vars[73].set_vars(73,"head_ache");
    clause_vars[74].set_vars(74,"vision_loss");
    clause_vars[75].set_vars(75,"partial_paralysis");
    clause_vars[76].set_vars(76,"");
    clause_vars[77].set_vars(77,"head_ache");
    clause_vars[78].set_vars(78,"lack_of_coordination");
    clause_vars[79].set_vars(79,"personality_changes");
    clause_vars[80].set_vars(80,"");
    clause_vars[81].set_vars(81,"head_ache");
    clause_vars[82].set_vars(82,"depression");
    clause_vars[83].set_vars(83,"abnormal_wt_gain");
    clause_vars[84].set_vars(84,"speech_disorder");



    clause_vars[85].set_vars(85,"yellow_skin");
    clause_vars[86].set_vars(86,"weight_loss");
    clause_vars[87].set_vars(87,"deep_fatigue");
    clause_vars[88].set_vars(88,"itensively_itchy_skin");

    clause_vars[89].set_vars(89,"decreased_apatite");
    clause_vars[90].set_vars(90,"swollen_abdomen");
    clause_vars[91].set_vars(91,"nausea_vomiting");
    clause_vars[92].set_vars(92,"");

    clause_vars[93].set_vars(93,"dark_colored_urine");
    clause_vars[94].set_vars(94,"enlarged_liver");
    clause_vars[95].set_vars(95,"confusion");
    clause_vars[96].set_vars(96,"");

    clause_vars[97].set_vars(97,"lesion_bleeding");
    clause_vars[98].set_vars(98,"unhealing_bruise");
    clause_vars[99].set_vars(99,"purplish_affected_area");
    clause_vars[100].set_vars(100,"");





    /*for(int i =0; i <53;i++)
    {
		clause_vars[i].print_clause_vars();
		cout<<endl;
	}*/
    cout<<endl;
}
