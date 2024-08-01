//
//  JHybridObjectInitializer.hpp
//  DoubleConversion
//
//  Created by Marc Rousavy on 22.07.24.
//

#pragma once

#include "HybridObject.hpp"
#include "JHybridObject.hpp"
#include <fbjni/fbjni.h>

namespace margelo::nitro {

using namespace facebook;

struct JHybridObjectInitializer : public jni::JavaClass<JHybridObjectInitializer> {
public:
  jni::local_ref<JHybridObject::javaobject> call() const {
    const auto method = this->getClass()->getMethod<JHybridObject::javaobject()>("initialize");
    return method(self());
  }

public:
  static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/HybridObjectInitializer;";
};

} // namespace margelo::nitro