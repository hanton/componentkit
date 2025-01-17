/*
*  Copyright (c) 2014-present, Facebook, Inc.
*  All rights reserved.
*
*  This source code is licensed under the BSD-style license found in the
*  LICENSE file in the root directory of this source tree. An additional grant
*  of patent rights can be found in the PATENTS file in the same directory.
*
*/

#import "CKAsyncBlock.h"

#import "CKAnalyticsListener.h"
#import "CKGlobalConfig.h"

namespace CK {
namespace Analytics {

auto willStartAsyncBlock(const char *const blockName) -> AsyncBlock {
  return {
    .name = blockName,
    .didStartBlock = [CKReadGlobalConfig().defaultAnalyticsListener.systraceListener willStartAsyncBlockTrace:blockName],
  };
}

}
}
