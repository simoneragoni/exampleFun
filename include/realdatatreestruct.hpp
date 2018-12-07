#pragma once

// Standard library includes
#include <string>
#include <vector>

// Our project headers
// #include "CipherMode.hpp"
// #include "CipherType.hpp"

/**
 * \file realdatatreestruct.hpp
 * \brief Contains the declarations of the data structures.
 */

/**
 * \struct realdatatreestruct
 * \brief Holds the settings of the tree that can be accessed during the program
 */
struct realdatatreestruct {
  //Kinematic
  Float_t lPt;            ///< Kinematic variable
  Float_t lRap;           ///< Kinematic variable
  Float_t lNegEta;        ///< Kinematic variable
  Float_t lPosEta;        ///< Kinematic variable
  Float_t lBachEta;       ///< Kinematic variable
  //Invariant Masses
  Float_t lInvMass;       ///< Invariant Masses
  Float_t lInvMassComp;   ///< Invariant Masses: Competing Species rejection
  //Topological variable definitions
  Float_t lDcaV0Daught;   ///< Topological variable definitions
  Float_t lDcaPosToPV;    ///< Topological variable definitions
  Float_t lDcaNegToPV;    ///< Topological variable definitions
  Float_t lDcaBachToPV;   ///< Topological variable definitions
  Float_t lV0CosPA;       ///< Topological variable definitions
  Float_t lCascCosPA;     ///< Topological variable definitions
  Float_t lV0Radius;      ///< Topological variable definitions
  Float_t lCascRadius;    ///< Topological variable definitions
  Float_t lDistOverTotMom;///< Topological variable definitions

  Float_t lV0Mass;        ///< Topological variable definitions
  Float_t lDcaCascDaught; ///< Topological variable definitions
  Float_t lDcaV0ToPV;     ///< Topological variable definitions
  //TPC and PID
  Int_t   lLeastNbrClust;    ///< TPC and PID
  Float_t lNSigmasPosProton; ///< TPC and PID
  Float_t lNSigmasNegProton; ///< TPC and PID
  Float_t lNSigmasPosPion;   ///< TPC and PID
  Float_t lNSigmasNegPion;   ///< TPC and PID
  Float_t lNSigmasBachPion;  ///< TPC and PID
  Float_t lNSigmasBachKaon;  ///< TPC and PID

  //Charge
  Int_t   lCharge;           ///< Charge

  //Centrality estimators
  Float_t lCentrality_V0A;   ///< Centrality estimators
  Float_t lCentrality_V0C;   ///< Centrality estimators
  Float_t lCentrality_V0M;   ///< Centrality estimators

  //MC-related
  Float_t lRapMC;            ///< MC-related
  Float_t lPtMC;             ///< MC-related
  Int_t   lPID;              ///< MC-related
  Int_t   lPIDBachelor;      ///< MC-related
  Int_t   lPIDNegative;      ///< MC-related
  Int_t   lPIDPositive;      ///< MC-related
  Int_t   lPrimaryStatus;    ///< MC-related
  Float_t lNegPxMC;          ///< used for g3/fluka correction
  Float_t lNegPyMC;          ///< used for g3/fluka correction
  Float_t lNegPzMC;          ///< used for g3/fluka correction
  Float_t lPosPxMC;          ///< used for g3/fluka correction
  Float_t lPosPyMC;          ///< used for g3/fluka correction
  Float_t lPosPzMC;          ///< used for g3/fluka correction

};

// #endif // RUNCASCADEANALYSIS_STRUCT_HPP
