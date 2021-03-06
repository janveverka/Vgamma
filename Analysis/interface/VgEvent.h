/**
 * \class VgEvent
 * 
 * \brief Holds data Z->mmg event data for the VgHistoManager.
 * Specifies candidates whose quantities will be filled in histograms.
 * 
 * \author Jan Veverka, Caltech 
 * \date 08 September 2012
 */
#ifndef Vgamma_Analysis_interface_VgEvent_h
#define Vgamma_Analysis_interface_VgEvent_h

#include <vector>
// #include <boost/ptr_container/ptr_vector.hpp>
#include "Vgamma/Analysis/interface/VgAnalyzerTree.h"
#include "Vgamma/Analysis/interface/VgLeafCandidate.h"
#include "Vgamma/Analysis/interface/VgCombinedCandidate.h"
// #include "Vgamma/Analysis/interface/VgCandidate.h"

//_____________________________________________________________________
namespace cit {
  
  class VgEvent {
  public:
    VgEvent(VgAnalyzerTree const &);
    VgEvent(VgEvent const &);
    ~VgEvent();
    /// Accessors
    VgAnalyzerTree       const & tree   ()  const {return tree_    ;}
    VgLeafCandidates     const & muons  ()  const {return muons_   ;}
    VgLeafCandidates     const & photons()  const {return photons_ ;}
    VgCombinedCandidates const & dimuons()  const {return dimuons_ ;}
    VgCombinedCandidates const & mmgCands() const {return mmgCands_;}
    double               const & weight ()  const {return weight_  ;}
    /// Producers
    void readFromTree();
    void putPhotons(VgLeafCandidates const &);
    void putMuons  (VgLeafCandidates const &);
    void putDimuons(VgCombinedCandidates const &);
    void putZgammas(VgCombinedCandidates const &);
    /// Combiners
    void combineMuonsToDimuons();
    void combineDimuonsAndPhotonsToMmgCands();
  private:
    VgAnalyzerTree const & tree_;
    VgLeafCandidates muons_;
    VgLeafCandidates photons_;
    VgCombinedCandidates dimuons_;
    VgCombinedCandidates mmgCands_;
    double weight_;
  }; // class VgEvent
  
} // namespace cit


#endif // #ifndef Vgamma_Analysis_interface_VgEvent_h
