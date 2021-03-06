/**
 * \class VgPhotonHistoFiller
 * 
 * \brief Fills photon Vgamma histograms.
 * 
 * \author Jan Veverka, Caltech 
 * \date 08 September 2012
 */
#ifndef Vgamma_Analysis_VgPhotonHistoFiller_h
#define Vgamma_Analysis_VgPhotonHistoFiller_h

#include "Vgamma/Analysis/interface/VgHistoFillerBase.h"
#include "Vgamma/Analysis/interface/VgPhotonSelector.h"

//_____________________________________________________________________
namespace cit {
  
  class VgPhotonHistoFiller : public VgHistoFillerBase {
  public:
    VgPhotonHistoFiller(VgAnalyzerTree const& tree,
                        HistoCollection & histos,
                        const Int_t * nMu);
    ~VgPhotonHistoFiller();
    virtual void bookHistograms();
    virtual void fillHistograms();
    virtual void fillObjectWithIndex(UInt_t i);
  }; // class VgPhotonHistoFiller
  
} // namespace cit

#endif // #ifndef Vgamma_Analysis_VgPhotonHistoFiller_h