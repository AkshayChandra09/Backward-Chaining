/*** FORWARD CHAINING ***/

#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



class doti{

private:
const int BLOCK_SIZE = 2;

int flag;

char cndvar[20][19];
char varlt[21][19],  clvarlt[40][19];
char c[20], vp[19], v[19];
char CANCER_TYPE[30], TREATMENT[50];
int instlt[21];
int f, i, j, k, s;
int fp;
int bp;
int sn;
int cn;
int choice;
char answer;

public:
doti(int);

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

};

doti::doti(int no){

choice = no;
forward();

}

 void doti:: forward()
{
    cout << endl;
	cout << "*   RECOMMENDED TREATMENT FOR DETECTED CANCER           *\n";

	initialization();

	cancerListDisplay();

	getTreatment();

}

void doti:: initialization(void)
{
    fp=1;
    bp=1;

    for (i=1;i < 40; i++)
        strcpy(clvarlt[i], "");
    for (i=1;i < 20; i++)
        strcpy(cndvar[i], "");
    for (i=1;i < 21; i++)
        instlt[i]=0;
    for (i=1;i < 21; i++)
        strcpy(varlt[i], "");
    for (i=1;i < 21; i++)
    {
        strcpy(cndvar[i], "");
        strcpy(varlt[i], "");
        instlt[i]=0;
    }

    strcpy(varlt[1], "CANCER_TYPE");

   for(i=1;i<41;i++)
    {
        if(i%2 == 1)
        {
            strcpy(clvarlt[i], "CANCER_TYPE");
        }
    }

	cout << "\n********* VARIABLE LIST ***********\n\n";
	cout << varlt[1];
	cout << endl << endl << endl;


	/*cout << "\n******* CLAUSE-VARIABLE LIST *******\n\n";

        for (i = 1; i < 21; i++)
        {
          cout << "Clause " << i << endl;
          for (j = 1; j < 3; j++)
            {
              k =  (i - 1)*BLOCK_SIZE  + j;
              cout <<j << " " << clvarlt[k] << endl;
            }
            cout << endl;

        }
        cout << "\nPress enter to continue...";*/
        getchar();
}


void doti:: instantiate()
{
    i=1;

    while ((strcmp(v, varlt[i]) != 0) && (i <= 21))
        i=i+1;

    instlt[i] = 1;
    i = 1;

    while ((strcmp(v, cndvar[i]) != 0) && (i <= 21))
        i=i+1;

    if (strcmp(v, cndvar[i]) != 0)
    {
        strcpy(cndvar[bp], v);
        bp=bp+1;
    }
}

void doti::getTreatment()
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
            if (strcmp(CANCER_TYPE, "Large_Cell_Neuroma") == 0)
                s=1;
            break;
        case 2:
            if ( strcmp(CANCER_TYPE, "Squanors_Cell_Carcinoma")  == 0)
                s=1;
            break;
        case 3:
            if (strcmp(CANCER_TYPE, "Large_Cell_Carcinoma") == 0)
                s=1;
            break;
        case 4:
            if ( strcmp(CANCER_TYPE, "AdenoCarcinoma") == 0)
                s=1;
            break;

        //Skin Cancer
        case 5:
            if (strcmp(CANCER_TYPE, "Acoustic Neuroma") == 0)
                s=1;
            break;
        case 6:
            if (strcmp(CANCER_TYPE, "CNS Lymphoma") == 0)
                s=1;
            break;
        case 7:
            if (strcmp(CANCER_TYPE, "Medulloblastoma") == 0)
                s=1;
            break;
        case 8:
            if (strcmp(CANCER_TYPE, "Pituitary Tumours") == 0)
                s=1;
            break;
        case 9:
            if (strcmp(CANCER_TYPE, "Superficial Spreading") == 0)
                s=1;
            break;
        case 10:
            if ( strcmp(CANCER_TYPE, "Nodular") == 0)
                s=1;
            break;
        case 11:
            if (strcmp(CANCER_TYPE, "Lentigo Maligna") == 0)
                s=1;
            break;
        case 12:
            if (strcmp(CANCER_TYPE, "Acral Lentiginous") == 0)
                s=1;
            break;
        case 13:
            if ( strcmp(CANCER_TYPE, "Acute Lymphocytic") == 0)
                s=1;
            break;
        case 14:
            if (strcmp(CANCER_TYPE, "Acute Mylogenous") == 0)
                s=1;
            break;
        case 15:
            if (strcmp(CANCER_TYPE, "Chronic Lymphocytic") == 0)
                s=1;
            break;
        case 16:
            if (strcmp(CANCER_TYPE, "Chronic myelogenous") == 0)
                s=1;
            break;
	 case 17:
            if (strcmp(CANCER_TYPE, "enalangio carcinoma") == 0)
                s=1;
            break;
 	case 18:
            if (strcmp(CANCER_TYPE, "Heptoblastoma") == 0)
                s=1;
            break;
	case 19:
            if (strcmp(CANCER_TYPE, "Liver Metastasis") == 0)
                s=1;
            break;
 	case 20:
            if (strcmp(CANCER_TYPE, "angiosarcoma") == 0)
                s=1;
            break;

        }

        if (s != 1)
        {
            f = sn + 1;
            goto Find;
        }

        switch (sn)
        {

        case 1:
            {
            strcpy(TREATMENT, "SURGERY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
            }

        case 2:
            strcpy(TREATMENT, "IMMUNO THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;

        case 3:
            strcpy(TREATMENT, "TARGETED THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 4:
            strcpy(TREATMENT, "RADIO SURGERY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 5:
            strcpy(TREATMENT, "CHEMO THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 6:
            strcpy(TREATMENT, "STEROIDS");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 7:
            strcpy(TREATMENT, "STEM CELL TRANSPLANTATION");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 8:
            strcpy(TREATMENT, "BIOPSY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 9:
            strcpy(TREATMENT, "DERMOSCOPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 10:
            strcpy(TREATMENT, "PATHOLOGY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 11:
            strcpy(TREATMENT, "LYMPHANGIOGRAM THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 12:
            strcpy(TREATMENT, "SPECIMEN BIOPSY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 13:
            strcpy(TREATMENT, "MONOCLONAL ANTIBODIES");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 14:
            strcpy(TREATMENT, "CHELATING AGENTS");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 15:
            strcpy(TREATMENT, "LEUKAPHORESIS");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
        case 16:
            strcpy(TREATMENT, "PHOTO DYNAMIC THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
 	case 17:

            strcpy(TREATMENT, "PERCUTANEOUS ETHANOL INJECTION");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
 	case 18:

            strcpy(TREATMENT, "HORMONAL THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;
	 case 19:
            strcpy(TREATMENT, "CHEMOTHERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
            strcpy(v, "TREATMENT");
            instantiate();
            break;

 	case 20:
            strcpy(TREATMENT, "TARGETED THERAPY");
            cout <<"********************************************************\n";
            cout <<"*      TREATMENT :	" << TREATMENT
                 << "               *\n";
            cout <<"********************************************************\n";
            cout << endl;
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

void doti::check_instantiation(void)
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
                       strcpy(CANCER_TYPE,"Large_Cell_Neuroma");
                       break;
                   case 2:
                       strcpy(CANCER_TYPE,"Squanors_Cell_Carcinoma");
                       break;
                    case 3:
                       strcpy(CANCER_TYPE,"Large_Cell_Carcinoma");
                       break;
                   case 4:
                       strcpy(CANCER_TYPE,"AdenoCarcinoma");
                       break;
                   case 5:
                       strcpy(CANCER_TYPE,"Acoustic Neuroma");
                       break;
                    case 6:
                       strcpy(CANCER_TYPE ,"CNS Lymphoma");
                       break;
                    case 7:
                       strcpy(CANCER_TYPE ,"Medulloblastoma");
                       break;
                    case 8:
                       strcpy(CANCER_TYPE,"Pituitary Tumours");
                       break;
                    case 9:
                       strcpy(CANCER_TYPE,"Superficial Spreading");
                       break;
                    case 10:
                       strcpy(CANCER_TYPE,"Nodular");
                       break;
                    case 11:
                       strcpy(CANCER_TYPE,"Lentigo Maligna");
                       break;
                    case 12:
                       strcpy(CANCER_TYPE,"Acral Lentiginous");
                       break;
                    case 13:
                       strcpy(CANCER_TYPE,"Acute Lymphocytic");
                       break;
                    case 14:
                       strcpy(CANCER_TYPE,"Acute Mylogenous");
                       break;
                    case 15:
                       strcpy(CANCER_TYPE,"Chronic Lymphocytic");
                       break;
                    case 16:
                       strcpy(CANCER_TYPE,"Chronic myelogenous");
                       break;
		    case 17:
                       strcpy(CANCER_TYPE,"enalangio carcinoma");
                       break;
		    case 18:
                       strcpy(CANCER_TYPE,"Heptoblastoma");
                       break;
		    case 19:
                       strcpy(CANCER_TYPE,"Liver Metastasis");
                       break;
		    case 20:
                       strcpy(CANCER_TYPE,"angiosarcoma");
                       break;
                    default:
                        cout << "\n Invalid choice. Please enter a number "
                             << "within 1-16\n\n";
                        goto repeat;
                  }
 		}
               break;
            }
	}
}


void doti::search()
{
   flag = 0;
    sn = f;

    while ((flag == 0) && (sn <= 20))
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


void doti::cancerListDisplay()
{
    cout << "\n\n**********************************************************\n";
    cout << "\n The list of cancer types diagnosed: \n";
    cout << " 1. Large Cell Neuroma \n";
    cout << " 2. Squamous Cell Carcinoma \n";
    cout << " 3. AdenoCarcinoma \n";
    cout << " 4. Large Cell Carcinoma \n";
    cout << " 5. Acoustic Neuroma \n";
    cout << " 6. CNS Lymphoma \n";
    cout << " 7. Medulloblastoma \n";
    cout << " 8. Pituitary Tumours \n";
    cout << " 9. Superficial Spreading \n";
    cout << " 10. Nodular \n";
    cout << " 11. Lentigo Maligna \n";
    cout << " 12. Acral Lentiginous \n";
    cout << " 13. Acute Lymphocytic \n";
    cout << " 14. Acute Mylogenous \n";
    cout << " 15. Chronic Lymphocytic \n";
    cout << " 16. Chronic myelogenous \n";
    cout << " 17. enolangio carcinoma \n";
    cout << " 18. Heptoblastoma \n";
    cout << " 19. Liver Metastasis \n";
    cout << " 20. Angiosarcoma \n";
    cout << "\n\n**********************************************************\n";
}

