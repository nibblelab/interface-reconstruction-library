// This file is part of the Interface Reconstruction Library (IRL),
// a library for interface reconstruction and computational geometry operations.
//
// Copyright (C) 2019 Robert Chiodi <robert.chiodi@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef SRC_MOMENTS_TAGGED_ACCUMULATED_LISTED_VOLUME_MOMENTS_H_
#define SRC_MOMENTS_TAGGED_ACCUMULATED_LISTED_VOLUME_MOMENTS_H_

#include "src/moments/listed_volume_moments.h"
#include "src/moments/tagged_accumulated_volume_moments.h"

namespace IRL {

template <class VolumeMomentsType>
class TaggedAccumulatedListedVolumeMoments
    : public TaggedAccumulatedVolumeMoments<
          ListedVolumeMoments<VolumeMomentsType>> {
 public:
  using contained_type = VolumeMomentsType;
  /// \brief Default constructor.
  TaggedAccumulatedListedVolumeMoments(void) = default;

  /// \brief Default destructor.
  ~TaggedAccumulatedListedVolumeMoments(void) = default;

 private:
};
}  // namespace IRL

#endif  // SRC_MOMENTS_TAGGED_ACCUMULATED_LISTED_VOLUME_MOMENTS_H_