// Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
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
#pragma once
#include <unordered_map>
#include "paddle/common/enforce.h"
#include "paddle/pir/core/block.h"

namespace pir {

class IrMapping {
 public:
  void Add(Value from, Value to) { value_map_[from] = to; }

  Value Lookup(Value from) const {
    IR_ENFORCE(value_map_.count(from) > 0, "Not Found Value in IRMapping.");
    return value_map_.at(from);
  }
  void Earse(Value from) { value_map_.erase(from); }

  void Clear() { value_map_.clear(); }

 private:
  std::unordered_map<Value, Value> value_map_;
};

}  // namespace pir
