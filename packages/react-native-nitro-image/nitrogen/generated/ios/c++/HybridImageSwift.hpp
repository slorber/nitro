///
/// HybridImageSwift.hpp
/// Mon Jul 22 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridImage.hpp"

namespace NitroImage {
  // Forward-declare ImageSpecCxx, because the NitroImage-Swift.h header might not do that automatically.
  class ImageSpecCxx;
} // namespace NitroImage





#include "NitroImage-Swift.h"

/**
 * The C++ part of ImageSpecCxx.swift.
 */
class HybridImageSwift final: public HybridImage {
public:
  // Constructor from a Swift instance
  explicit HybridImageSwift(NitroImage::ImageSpecCxx swiftPart): HybridImage(), _swiftPart(swiftPart) { }

public:
  // Get the Swift part
  inline NitroImage::ImageSpecCxx getSwiftPart() { return _swiftPart; }

public:
  // Properties
  inline ImageSize getSize() override {
    return _swiftPart.getSize();
  }
  inline PixelFormat getPixelFormat() override {
    auto result = _swiftPart.getPixelFormat();
    return static_cast<PixelFormat>(result);
  }
  inline double getSomeSettableProp() override {
    return _swiftPart.getSomeSettableProp();
  }
  inline void setSomeSettableProp(double someSettableProp) override {
    _swiftPart.setSomeSettableProp(std::forward<decltype(someSettableProp)>(someSettableProp));
  }

public:
  // Methods
  inline double toArrayBuffer(ImageFormat format) override {
    auto valueOrError = _swiftPart.toArrayBuffer(static_cast<int>(format));
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
    auto value = valueOrError.getValue();
    return value;
  }
  inline void saveToFile(const std::string& path) override {
    auto valueOrError = _swiftPart.saveToFile(std::forward<decltype(path)>(path));
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
  }

private:
  NitroImage::ImageSpecCxx _swiftPart;
};