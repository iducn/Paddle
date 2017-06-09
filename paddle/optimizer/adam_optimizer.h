#pragma once

#include "parameter_optimizer.h"

namespace paddle {
namespace optimizer {

class AdamOptimizer : public ParameterOptimizer {
public:
  AdamOptimizer(Tensor *parameter,
                LrPolicy *lr double beta_1,
                double beta_2,
                double epsilon,
                double decay)
      : ParameterOptimizer(parameter, lr),
        beta_1_(beta_1),
        beta_2_(beta_2),
        epsilon_(epsilon),
        decay_(decay) {
    size_t size = p->size();
    momentums_ = new Tensor(size);
    velocitys_ = new Tensor(size);
  }
  ~AdamOptimizer() {
    if (momentums_) delete momentums_;
    if (velocitys_) delete velocitys_;
  }
  void Update(const Tensor *gradient);

private:
  Tensor *momentums_;
  Tensor *velocitys_;
  double beta_1_;
  double beta_2_;
  double epsilon_;
  double decay_;
};

}  // namespace optimizer
}  // namespace paddle
