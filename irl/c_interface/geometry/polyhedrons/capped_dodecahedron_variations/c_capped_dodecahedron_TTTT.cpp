// This file is part of the Interface Reconstruction Library (IRL),
// a library for interface reconstruction and computational geometry operations.
//
// Copyright (C) 2019 Robert Chiodi <robert.chiodi@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "irl/c_interface/geometry/polyhedrons/capped_dodecahedron_variations/c_capped_dodecahedron_TTTT.h"

extern "C" {

void c_CapDod_TTTT_new(c_CapDod_TTTT* a_self) {
  assert(a_self->obj_ptr == nullptr);
  a_self->obj_ptr = new IRL::CappedDodecahedron_TTTT;
}

void c_CapDod_TTTT_delete(c_CapDod_TTTT* a_self) {
  delete a_self->obj_ptr;
  a_self->obj_ptr = nullptr;
}

void c_CapDod_TTTT_construct(c_CapDod_TTTT* a_self, const double* a_capped_dodecahedron) {
  assert(a_self != nullptr);
  assert(a_self->obj_ptr != nullptr);
  *a_self->obj_ptr =
      IRL::CappedDodecahedron_TTTT::fromRawDoublePointer(9, a_capped_dodecahedron);
}

void c_CapDod_TTTT_adjustCapToMatchVolume(c_CapDod_TTTT* a_self,
                                     const double* a_correct_signed_volume) {
  assert(a_self != nullptr);
  assert(a_self->obj_ptr != nullptr);
  a_self->obj_ptr->adjustCapToMatchVolume(*a_correct_signed_volume);
}

void c_CapDod_TTTT_getBoundingPts(const c_CapDod_TTTT* a_self, double* a_lower_pt,
                             double* a_upper_pt) {
  assert(a_self != nullptr);
  assert(a_self->obj_ptr != nullptr);
  const IRL::Pt& lower_pt = a_self->obj_ptr->getLowerLimits();
  const IRL::Pt& upper_pt = a_self->obj_ptr->getUpperLimits();
  std::memcpy(&a_lower_pt[0], &lower_pt[0], 3 * sizeof(double));
  std::memcpy(&a_upper_pt[0], &upper_pt[0], 3 * sizeof(double));
}

void c_CapDod_TTTT_getPt(const c_CapDod_TTTT* a_self, const int* a_index, double* a_pt) {
  assert(a_self != nullptr);
  assert(a_self->obj_ptr != nullptr);
  assert(*a_index >= 0 &&
         *a_index < static_cast<int>(a_self->obj_ptr->getNumberOfVertices()));
  a_pt[0] = (*a_self->obj_ptr)[static_cast<IRL::UnsignedIndex_t>(*a_index)].x();
  a_pt[1] = (*a_self->obj_ptr)[static_cast<IRL::UnsignedIndex_t>(*a_index)].y();
  a_pt[2] = (*a_self->obj_ptr)[static_cast<IRL::UnsignedIndex_t>(*a_index)].z();
}
}
