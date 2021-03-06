// Copyright (c) 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LIBSPIRV_OPT_REFLECT_H_
#define LIBSPIRV_OPT_REFLECT_H_

#include "spirv/1.1/spirv.h"

namespace spvtools {
namespace ir {

// Note that as SPIR-V evolves over time, new opcodes may appear. So the
// following functions tend to be outdated and should be updated when SPIR-V
// version bumps.

inline bool IsDebugInst(SpvOp opcode) {
  return (opcode >= SpvOpSourceContinued && opcode <= SpvOpLine) ||
         opcode == SpvOpNoLine || opcode == SpvOpModuleProcessed;
}
inline bool IsDebugLineInst(SpvOp opcode) {
  return opcode == SpvOpLine || opcode == SpvOpNoLine;
}
inline bool IsAnnotationInst(SpvOp opcode) {
  return opcode >= SpvOpDecorate && opcode <= SpvOpGroupMemberDecorate;
}
inline bool IsTypeInst(SpvOp opcode) {
  return (opcode >= SpvOpTypeVoid && opcode <= SpvOpTypeForwardPointer) ||
         opcode == SpvOpTypePipeStorage || opcode == SpvOpTypeNamedBarrier;
}
inline bool IsConstantInst(SpvOp opcode) {
  return opcode >= SpvOpConstantTrue && opcode <= SpvOpSpecConstantOp;
}
inline bool IsTerminatorInst(SpvOp opcode) {
  return opcode >= SpvOpBranch && opcode <= SpvOpUnreachable;
}
inline bool IsVariableInst(SpvOp opcode) {
	return opcode == SpvOpVariable;
}

}  // namespace ir
}  // namespace spvtools

#endif  // LIBSPIRV_OPT_REFLECT_H_
