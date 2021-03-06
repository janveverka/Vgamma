/**
 * \class VgLeafCandidate
 * \brief Representation of a generic elementary particle.
 * Derives from the VgCandidate class and holds a key under
 * which it is stored in the VgTree array.
 *
 * \author Jan Veverka, Caltech
 * \date 15 September 2012.
 */

#ifndef Vgamma_Analysis_interface_VgLeafCandidate_h
#define Vgamma_Analysis_interface_VgLeafCandidate_h

#include "Vgamma/Analysis/interface/VgCandidate.h"
#include "Vgamma/Analysis/interface/VgAnalyzerTree.h"

namespace cit {
  class VgLeafCandidate;
  typedef std::vector<VgLeafCandidate> VgLeafCandidates;
  
  class VgLeafCandidate : public VgCandidate {
  public:
    /// Ctor and dtor
    VgLeafCandidate(VgAnalyzerTree const &, ParticleType, unsigned);
    VgLeafCandidate(VgLeafCandidate const &);
    VgLeafCandidate();
    ~VgLeafCandidate() {}
    /// Accessors
    inline VgAnalyzerTree const & tree() const {return *tree_;}
    inline unsigned key() const {return key_;}
    inline double rho() const {return tree_->rho;}
    /// Overloaded the equality operator
    bool operator==(VgLeafCandidate const & other) const;
    bool operator!=(VgLeafCandidate const & other) const {
      return ! operator==(other);
    }
    /// Static data
    static const double kElectronMass;
    static const double kMuonMass;
    static const double kPhotonMass;
    /// Common isolation interface
    double combRelIso();
  private:
    /// Initialize data members
    void init();
    /// Reference to our tree holding data
    VgAnalyzerTree const * tree_;
    /// Index in the VgTree array. 
    unsigned key_;
  }; /// class VgLeafCandidate
} /// namespace cit

#endif // #define Vgamma_Analysis_interface_VgLeafCandidate_h
