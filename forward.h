/*** FORWARD CHAINING ***/

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;



class Forward_Chaining{

private:

const int BLOCK_SIZE = 2;

int flag;

char cndvar[25][19];
char varlt[26][19],  clvarlt[50][19];
char c[20], vp[19], v[19];
char CANCER_TYPE[30], TREATMENT[50];
int instlt[26];

#define cndvar_size 25
#define varlt_size 26
#define clvarlt_size 50
#define instlt_size 26

int f, i, j, k, s;
int fp;
int bp;
int sn;
int cn;
int choice;
char answer;

public:
Forward_Chaining(int);
void initialization(void);
void search(void);
void check_instantiation(void);
void instantiate(void);
void cancerListDisplay();
void getTreatment();
 void forward();
	int getChoice(){
	return choice;
	}

	void setChoice(int no){
	 choice = no;
	}

	void write_file(string);

};

Forward_Chaining::Forward_Chaining(int no){
choice = no;
forward();
}

 void Forward_Chaining:: forward()
{

    cout << endl;
	cout << endl<<"*******RECOMMENDED TREATMENT FOR DETECTED CANCER*******\n"<<endl;

	initialization();

	getTreatment();

}

void Forward_Chaining:: initialization(void)
{
    fp=1;
    bp=1;

    for (i=1;i < clvarlt_size; i++)
        strcpy(clvarlt[i], "");
    for (i=1;i < cndvar_size; i++)
        strcpy(cndvar[i], "");
    for (i=1;i < instlt_size; i++)
        instlt[i]=0;
    for (i=1;i < varlt_size; i++)
        strcpy(varlt[i], "");

    for (i=1;i < cndvar_size; i++)
    {
        strcpy(cndvar[i], "");
        strcpy(varlt[i], "");
        instlt[i]=0;
    }

    strcpy(varlt[1], "CANCER_TYPE");

   for(i=1;i<clvarlt_size+1;i++)
    {
        if(i%2 == 1)
        {
            strcpy(clvarlt[i], "CANCER_TYPE");
        }
    }

        getchar();
}


void Forward_Chaining:: instantiate()
{
    i=1;

    while ((strcmp(v, varlt[i]) != 0) && (i <= varlt_size))
        i=i+1;

    instlt[i] = 1;
    i = 1;

    while ((strcmp(v, cndvar[i]) != 0) && (i <= cndvar_size))
        i=i+1;

    if (strcmp(v, cndvar[i]) != 0)
    {
        strcpy(cndvar[bp], v);
        bp=bp+1;
    }
}

void Forward_Chaining::getTreatment()
{
    strcpy(c,"CANCER_TYPE");
    strcpy(cndvar[bp], c);
    bp = bp + 1;
    sn = 1; cn = 1;
    f=1;
    Find: search();
    cn=1;

   if (sn != 0)
    {

        i = 2 * (sn-1) + cn;
        strcpy(v, clvarlt[i]);
        while (strcmp(v, "") !=0)
        {
            check_instantiation();
            cn = cn+1;
            i = 2 * (sn-1) + cn;
            strcpy(v, clvarlt[i]);
        }

        s = 0;

        switch(sn)
        {
        case 1:
            if (strcmp(CANCER_TYPE, "large_cell_neuroma") == 0)
                s=1;
            break;
        case 2:
            if ( strcmp(CANCER_TYPE, "squanors_cell_carcinoma")  == 0)
                s=1;
            break;
        case 3:
            if (strcmp(CANCER_TYPE, "large_cell_carcinoma") == 0)
                s=1;
            break;
        case 4:
            if ( strcmp(CANCER_TYPE, "adeno_carcinoma") == 0)
                s=1;
            break;

        case 5:
            if (strcmp(CANCER_TYPE, "no_lung_cancer") == 0)
                s=1;
            break;
        case 6:
            if (strcmp(CANCER_TYPE, "nodular") == 0)
                s=1;
            break;
        case 7:
            if (strcmp(CANCER_TYPE, "acral_lentigious") == 0)
                s=1;
            break;
        case 8:
            if (strcmp(CANCER_TYPE, "lentigo") == 0)
                s=1;
            break;
        case 9:
            if (strcmp(CANCER_TYPE, "superficial_spreading") == 0)
                s=1;
            break;
        case 10:
            if ( strcmp(CANCER_TYPE, "no_skin_cancer") == 0)
                s=1;
            break;
        case 11:
            if (strcmp(CANCER_TYPE, "leukemia_stage1") == 0)
                s=1;
            break;
        case 12:
            if (strcmp(CANCER_TYPE, "acute_myclogeneous") == 0)
                s=1;
            break;
        case 13:
            if ( strcmp(CANCER_TYPE, "chronic_myclogeneous") == 0) //Acute Mylogenous
                s=1;
            break;
        case 14:
            if (strcmp(CANCER_TYPE, "chronic_lymphocytic") == 0)
                s=1;
            break;
        case 15:
            if (strcmp(CANCER_TYPE, "acute_lymphocytic") == 0)
                s=1;
            break;
        case 16:
            if (strcmp(CANCER_TYPE, "no_blood_cancer") == 0)
                s=1;
            break;
        case 17:
            if (strcmp(CANCER_TYPE, "acoustic_neuroma") == 0)
                s=1;
            break;
        case 18:
            if (strcmp(CANCER_TYPE, "cns_lymphoma") == 0)
                s=1;
            break;
        case 19:
            if (strcmp(CANCER_TYPE, "medulloblastoma") == 0)
                s=1;
            break;
        case 20:
            if (strcmp(CANCER_TYPE, "pituitary_tumour") == 0)
                s=1;
            break;

        case 21:
            if (strcmp(CANCER_TYPE, "enalangio_carcinoma") == 0)
                s=1;
            break;
        case 22:
            if (strcmp(CANCER_TYPE, "heptoblastoma") == 0)
                s=1;
            break;
        case 23:
            if (strcmp(CANCER_TYPE, "metastasis") == 0)
                s=1;
            break;
        case 24:
            if (strcmp(CANCER_TYPE, "angiosarcoma") == 0)
                s=1;
            break;

         case 25:
            if (strcmp(CANCER_TYPE, "wheezing") == 0)
                s=1;
            break;

        }

        if (s != 1)
        {
            f = sn + 1;
            goto Find;
        }

        string treat;

        switch (sn)
        {

        case 1:
            {
            strcpy(TREATMENT, "SURGERY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
            }

        case 2:
            strcpy(TREATMENT, "IMMUNO THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 3:
            strcpy(TREATMENT, "TARGETED THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 4:
            strcpy(TREATMENT, "CHEMO SURGERY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        //no skin cancer
        case 5:
            strcpy(TREATMENT, "PRESCRIBED MEDICATION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

         //skin cancer
        case 6:
            strcpy(TREATMENT, "DERMOSCOPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 7:
            strcpy(TREATMENT, "LYMPHANGIOGRAM");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 8:
            strcpy(TREATMENT, "PATHOLOGY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 9:
            strcpy(TREATMENT, "BIOPSY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

           //no skin cancer
        case 10:
            strcpy(TREATMENT, "GENERAL_MEDICATION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 11:
            strcpy(TREATMENT, "GENERAL_MEDICATION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

         //blood cancer
        case 12:
            strcpy(TREATMENT, "MONOCLONAL_ANTIBODIES");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 13:
            strcpy(TREATMENT, "BIOLOGICAL_THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 14:
            strcpy(TREATMENT, "LEUKAPHORESIS");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 15:
            strcpy(TREATMENT, "SPECIMEN_BIOPSY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 16:
            strcpy(TREATMENT, "GENERAL_MEDICATION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;
 	case 17:

            strcpy(TREATMENT, "RADIO_SURGERY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 18:
            strcpy(TREATMENT, "STERIODS");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 19:
            strcpy(TREATMENT, "STEMCELL_TRANSPLANT");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 20:
            strcpy(TREATMENT, "TRANSPHENODIAL_SURGERY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

            case 21:
            strcpy(TREATMENT, "PHOTODYNAMIC THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 22:
            strcpy(TREATMENT, "PERCUTANEOUS ETHANOL INJECTION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 23:
            strcpy(TREATMENT, "HORMONAL THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 24:
            strcpy(TREATMENT, "BIOLOGICAL THERAPY");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;

         case 25:
            strcpy(TREATMENT, "NEBULIZATION");

            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            write_file(TREATMENT);
            strcpy(v, "TREATMENT");
            instantiate();
            break;


	}

	    f = sn + 1;
        goto Find;
      }


     fp=fp+1;
     if (fp < bp)
     {
        f = 1;
        goto Find;
     }
}

void Forward_Chaining::check_instantiation(void)
{
	i=1;

    while ((strcmp(v, varlt[i]) != 0) && (i < 2))
	i = i+1;

    if (instlt[i] != 1)
    {

        instlt[i] = 1;
        switch (i)
        {

        case 1:
           {
               repeat:

               switch(getChoice())
               {
                    case 1:
                        strcpy(CANCER_TYPE, "large_cell_neuroma");
                        break;
                    case 2:
                        strcpy(CANCER_TYPE, "squanors_cell_carcinoma");
                        break;
                    case 3:
                        strcpy(CANCER_TYPE, "large_cell_carcinoma");
                        break;
                    case 4:
                        strcpy(CANCER_TYPE, "adeno_carcinoma");
                        break;

                    //Skin Cancer
                    case 5:
                        strcpy(CANCER_TYPE, "no_lung_cancer");
                        break;
                    case 6:
                        strcpy(CANCER_TYPE, "nodular");
                        break;
                    case 7:
                        strcpy(CANCER_TYPE, "acral_lentigious");
                        break;
                    case 8:
                        strcpy(CANCER_TYPE, "lentigo");
                        break;
                    case 9:
                        strcpy(CANCER_TYPE, "superficial_spreading");
                        break;
                    case 10:
                        strcpy(CANCER_TYPE, "no_skin_cancer");
                        break;
                    case 11:
                        strcpy(CANCER_TYPE, "leukemia_stage1");
                        break;
                    case 12:
                        strcpy(CANCER_TYPE, "acute_myclogeneous");
                        break;
                    case 13:
                        strcpy(CANCER_TYPE, "chronic_myclogeneous"); //Acute Mylogenous
                        break;
                    case 14:
                        strcpy(CANCER_TYPE, "chronic_lymphocytic");
                            s=1;
                        break;
                    case 15:
                        strcpy(CANCER_TYPE, "acute_lymphocytic");
                        break;
                    case 16:
                        strcpy(CANCER_TYPE, "no_blood_cancer");
                        break;
                    case 17:
                        strcpy(CANCER_TYPE, "acoustic_neuroma");
                        break;
                    case 18:
                        strcpy(CANCER_TYPE, "cns_lymphoma");
                        break;
                    case 19:
                        strcpy(CANCER_TYPE, "medulloblastoma");
                        break;
                    case 20:
                        strcpy(CANCER_TYPE, "pituitary_tumour");
                        break;

                    case 21:strcpy(CANCER_TYPE, "enalangio_carcinoma");
                        break;
                    case 22:strcpy(CANCER_TYPE, "heptoblastoma");
                        break;
                    case 23:strcpy(CANCER_TYPE, "metastasis");
                        break;
                    case 24:strcpy(CANCER_TYPE, "angiosarcoma");
                        break;
                     case 25:strcpy(CANCER_TYPE, "wheezing");
                        break;

                    default:
                        cout << "\n Invalid choice... "<< endl;
                        goto repeat;
                  }
 		}
               break;
            }
	}
}


void Forward_Chaining::search()
{
   flag = 0;
    sn = f;

    while ((flag == 0) && (sn <= cndvar_size))
    {
        cn=1;
        k = (sn-1)*BLOCK_SIZE+cn;
        while ((strcmp(clvarlt[k], cndvar[fp]) != 0) && (cn < 3))
        {
            cn = cn+1;
            k = (sn-1)*BLOCK_SIZE+cn;
        }

        if (strcmp(clvarlt[k], cndvar[fp]) == 0)
            flag = 1;

        if (flag == 0)
            sn = sn+1;
    }
    if (flag == 0)
        sn=0;
}

void Forward_Chaining::write_file(string treat){
    ofstream fout;
    fout.open("data_log.txt",ios::app);
    fout<<"TREATMENT"<<" :\t"<<treat<<endl;
    fout<<"___________________________________________________________________________________"<<endl<<endl;
}
