#include "Analysis_Selec.h"

Selec::Selec()
{
    NofParticlesPassingCut=0;
    NofParticlesPassingNminus1=0;
    NofParticlesPassingInOrderUpToCut=0;
}

Selec::~Selec()
{
    NofParticlesPassingCut=0;
    NofParticlesPassingNminus1=0;
    NofParticlesPassingInOrderUpToCut=0;
    delete tableOfBool;
}

Selec::Selec(string file_name)
{
    NofParticlesPassingCut=0;
    NofParticlesPassingNminus1=0;
    NofParticlesPassingInOrderUpToCut=0;
    config_file = file_name;
}

void Selec::Configure(string file_name)
{
    config_file = file_name;
}

void Selec::LoadVariables()
{
    ifstream ifile;
    ifile.open(config_file,std::ifstream::in);
    int indice=-1;
    string name="";
    double var=0.;
    char test='=';
    double threshold=0.;
    string plot_name="";
    int plot_NofBins=0;
    double plot_min=0.;
    double plot_max=0.;
    while(!ifile.eof())
    {
        ifile>>indice;
        ifile>>name;
        ifile>>var;
        ifile>>test;
        ifile>>threshold;
        ifile>>plot_name;
        ifile>>plot_NofBins;
        ifile>>plot_min;
        ifile>>plot_max;
        Variable variable(indice,name,var,test,threshold,plot_name,plot_NofBins,plot_min,plot_max);
        vect_Var.push_back(variable);
    }
    vect_Var.pop_back(); //la boucle remplit une variable supplementaire avec la derniere ligne (effectue deux fois...)
    for(int i=0;i<vect_Var.size();i++) vect_Var[i].CreateHistogram();
}

void Selec::LoadCinematicVariables()
{
    ifstream ifile;
    ifile.open(config_file,std::ifstream::in);
    int indice=-1;
    string name="";
    double var=0.;
    char test='=';
    double threshold=0.;
    string plot_name="";
    int plot_NofBins=0;
    double plot_min=0.;
    double plot_max=0.;
    while(!ifile.eof())
    {
        ifile>>indice;
        ifile>>name;
        ifile>>var;
        ifile>>test;
        ifile>>threshold;
        ifile>>plot_name;
        ifile>>plot_NofBins;
        ifile>>plot_min;
        ifile>>plot_max;
        Variable variable(indice,name,var,test,threshold,plot_name,plot_NofBins,plot_min,plot_max);
        vect_CinematicVar.push_back(variable);
    }
    vect_CinematicVar.pop_back(); //la boucle remplit une variable supplementaire avec la derniere ligne (effectue deux fois...)
}


std::vector<Variable> Selec::GetVectVar() {return vect_Var;}

std::vector<Variable> Selec::GetVectCinematicVar() {return vect_CinematicVar;}

bool Selec::isPass(double var,char test,double threshold)
{
    switch(test)
    {
        case '=' : 
            if(var == threshold) return true;
            else return false; 
            break;
        case '>' :
            if(var > threshold) return true;
            else return false; 
            break;
        case '<' :
            if(var < threshold) return true; 
            else return false; 
            break;
        default :
            return false;
    }
}

bool Selec::BoolNminus1(bool* table,int size,int skip)
{
    for(int i=0;i<size;i++)
    {
        if(i==skip) continue;
        if(!table[i]) {return false;}
    }
    return true;
}

void Selec::LoadValues(std::map<std::string,double> mapOfValues)
{
    tableOfBool = new bool(vect_Var.size());
    for(int i=0;i<vect_Var.size();i++) tableOfBool[i]=false; //init the table of booleans
    
    for(int i=0;i<vect_Var.size();i++)
    {
        string name_i=vect_Var.at(i).GetName();
        for(auto& j:mapOfValues)
        {
            string name_j=j.first;
            if(!(name_j==name_i)) continue;
            Variable* var = &vect_Var[i];
            var->SetVariable(j.second);
            //if(!isPass(j.second,vect_Var.at(i).GetTest(),vect_Var.at(i).GetThreshold())) continue; 
            //vect_Bool.push_back(isPass(j.second,vect_Var.at(i).GetTest(),vect_Var.at(i).GetThreshold()));
            //mapOfBool[name_j]                           = isPass(j.second,vect_Var.at(i).GetTest(),vect_Var.at(i).GetThreshold());
            //tableOfBool[vect_Var.at(i).GetIndice()]     = isPass(j.second,vect_Var.at(i).GetTest(),vect_Var.at(i).GetThreshold());
            tableOfBool[var->GetIndice()]       = isPass(var->GetVariable(),var->GetTest(),var->GetThreshold());
        }
    }
    for(int i=0;i<vect_Var.size();i++) //loop on the table of booleans
    {
        Variable* var = &vect_Var[i];
        if(tableOfBool[i]) var->IncreaseNofParticlesPassingCut();
        /*for(int j=0;j<vect_Var.size();j++)
        {
            if(i==j) continue;
            if(!tableOfBool[j]) {test=false;continue;}
            test=true;
        }*/
        bool test=BoolNminus1(tableOfBool,vect_Var.size(),i);
        if(test) {var->FillHistoNminus1(var->GetVariable());cout<<var->GetVariable()<<"   "<<var->GetName()<<endl;}
    }
}

std::map<string,bool> Selec::GetMapOfBool() {return mapOfBool;}

bool* Selec::GetTableOfBool() {return tableOfBool;}

void Selec::SaveHistograms(string file_name)
{
    TFile* ifile = new TFile(file_name.c_str(),"RECREATE");
    for(int i=0;i<vect_Var.size();i++)
    {
        vect_Var[i].GetPlotNminus1()->Write();
    }
    ifile->Close();
}
