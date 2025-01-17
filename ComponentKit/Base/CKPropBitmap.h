/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#pragma once

#include <type_traits>

namespace CK {
namespace BuilderDetails {

using PropsBitmapType = unsigned long long;

namespace PropBitmap {
static constexpr auto isSet(PropsBitmapType bitmap, PropsBitmapType prop) -> bool
{
  return (bitmap & prop) != 0;
}

template<typename ...PropsBitmapTypes>
static constexpr auto isSet(PropsBitmapType bitmap, PropsBitmapType prop, PropsBitmapTypes... props) -> bool
{
  return isSet(bitmap, prop) && isSet(bitmap, props...);
}

}  // namespace PropBitmap
}  // namespace BuilderDetails
}  // namespace CK
