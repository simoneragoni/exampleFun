#include <iostream>
#include <TFile.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TFile.h>
#include "DictExample.h"


using namespace std;



/*
void   runCascadeAnalysis( TString lCascType = "OmegaMinus", bool debug = kTRUE, bool forceInelCalc = kTRUE){

  cout<<"----------------------------------------------------"<<endl;
  cout<<"               Cascade Analysis Macro               "<<endl;
  cout<<"----------------------------------------------------"<<endl;
  cout<<endl;
  Int_t workedornot = gSystem->Load("libDictExample");
  cout<<endl;
  if( workedornot == 0 ){
    cout<<"******************************************"<<endl;
    cout<<" AliCascadeModule.cxx LOADING failed!     "<<endl;
    cout<<"******************************************"<<endl;
    return;
  }
  Double_t ptbinlimits[] = {0.9,1.8,2.3,2.8,3.5,5};
  Long_t ptbinnumb = sizeof(ptbinlimits)/sizeof(Double_t)-1;
  Float_t centr_lim_common[] ={ 0, 5, 15, 30, 60, 100};
  Long_t centrbinnumb = sizeof(centr_lim_common)/sizeof(Float_t)-1;
  AliCascadeAnalysis *v0 = new AliCascadeAnalysis( lCascType,
                                                   ptbinnumb,
                                                   ptbinlimits,
                                                   centrbinnumb,
                                                   centr_lim_common);

  // v0->SetRealDataFile    ( "rldata.root" );
  v0->SetRealDataFile    ( "mcdataom.root" );

  if(lCascType.Contains("Xi"))          v0->SetMCDataFile( "mcdataxi.root");
  else if (lCascType.Contains("Omega")) v0->SetMCDataFile( "mcdataom.root");


  char nameoutput[500];
  sprintf(nameoutput,"./Results-%s-CENT_wSDD-LHC16r-LHC17d14_allV0_weighted_scaled.root",lCascType.Data());
  v0->SetOutputFile      ( nameoutput );

  char nameinelfile[500];
  if(lCascType.Contains("Xi"))         sprintf(nameinelfile,"./Inelastics_Xi.root");
  else if(lCascType.Contains("Omega")) sprintf(nameinelfile,"./Inelastics_Omega.root");
  v0->SetInelasticsFile(nameinelfile);

  v0->SetDefaultCuts();
  // v0->SetPtBinLimits(ptbinnumb,ptbinlimits);
  // v0->SetRapidityWindow(-0.5,0.);
  // v0->SetCentralityLimits(centrbinnumb,centr_lim_common);
  // v0->SetCheckEff(kTRUE);
  v0->SetDebugMode(debug);
  v0->SetForceInelCalc(forceInelCalc);
  // v0->SetFitBkg(kTRUE);
  v0->DoAnalysis();


}
*/


// R__LOAD_LIBRARY(libDictExample)    //starting point to ROOT6 integration!!!



void   runCascadeAnalysis( TString lCascType = "OmegaMinus", bool debug = kTRUE, bool forceInelCalc = kTRUE){
  cout<<"----------------------------------------------------"<<endl;
  cout<<"               Cascade Analysis Macro               "<<endl;
  cout<<"----------------------------------------------------"<<endl;
  cout<<endl;

  Int_t workedornot = gSystem->Load("libDictExample");  //ROOT 5
  cout<<workedornot;
  cout<<endl;
  if( workedornot == 0 ){
    cout<<"******************************************"<<endl;
    cout<<" AliCascadeModule.cxx LOADING failed!     "<<endl;
    cout<<"******************************************"<<endl;
    return;
  }
  Double_t ptbinlimits[] = {0.9,1.8,2.3,2.8,3.5,5};
  Long_t ptbinnumb = sizeof(ptbinlimits)/sizeof(Double_t)-1;
  Float_t centr_lim_common[] ={ 0, 5, 15, 30, 60, 100};
  Long_t centrbinnumb = sizeof(centr_lim_common)/sizeof(Float_t)-1;

  AliCascadeAnalysis *v0 = new AliCascadeAnalysis( lCascType );
  // AliCascadeAnalysis *v0 = new AliCascadeAnalysis( lCascType,
  //                                                  ptbinnumb,
  //                                                  ptbinlimits,
  //                                                  centrbinnumb,
  //                                                  centr_lim_common);
  // cout<<endl;
  // cout<<centrbinnumb;
  // cout<<endl<<flush;
  // // v0->SetRealDataFile    ( "rldata.root" );
  v0->SetRealDataFile    ( "mcdataom.root" );
  //v0->SetRealDataFile    ( "rldata.root" );

  if(lCascType.Contains("Xi"))          v0->SetMCDataFile( "mcdataxi.root");
  else if (lCascType.Contains("Omega")) v0->SetMCDataFile( "mcdataom.root");


  char nameoutput[500];
  sprintf(nameoutput,"./Results-%s-CENT_wSDD-LHC16r-LHC17d14_allV0_weighted_scaled.root",lCascType.Data());
  v0->SetOutputFile      ( nameoutput );

  char nameinelfile[500];
  if(lCascType.Contains("Xi"))         sprintf(nameinelfile,"./Inelastics_Xi.root");
  else if(lCascType.Contains("Omega")) sprintf(nameinelfile,"./Inelastics_Omega.root");
  v0->SetInelasticsFile(nameinelfile);

  v0->SetDefaultCuts();
  v0->SetPtBinLimits(ptbinnumb,ptbinlimits);
  v0->SetRapidityWindow(-0.5,0.);
  v0->SetCentralityLimits(centrbinnumb,centr_lim_common);
  v0->SetCheckEff(kTRUE);
  v0->SetDebugMode(debug);
  v0->SetForceInelCalc(forceInelCalc);
  v0->SetFitBkg(kTRUE);

  v0->DoAnalysis();


}

int main(){
  runCascadeAnalysis();
cout << 2+2 ;
// runCascadeAnalysis();
// gSystem->Load("libDictExample");
//Simple s;
//cout << s.GetX() << endl;
// TFile *_file = TFile::Open("tmp.root", "RECREATE");
//gDirectory->WriteObject(&s, "MyS");
//Simple *MyS = nullptr;
//gDirectory->GetObject("MyS", MyS);
//cout << MyS->GetX() << endl;
// _file->Close();
return 1;
}
